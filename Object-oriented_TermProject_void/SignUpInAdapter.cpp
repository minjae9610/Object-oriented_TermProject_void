#include "stdafx.h"
#include "SignUpInAdapter.h"

SignUpInAdapter::~SignUpInAdapter()
{
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
		delete it->first;
		delete it->second;
	}
	delete userLoginInfo;
}

SignUpInAdapter::SignUpInAdapter()
{
	userLoginInfo = new map<const char*, const char*>();
	path = "SystemData\\UserLoginInfo.LoginInfoDB";
	vector<const char*>* tempLoginInfo = new vector<const char*>();
	FileSystemAdapter fileSys;
	fileSys.fileIn(path, tempLoginInfo);
	StringFixAdapter fix;
	vector<string>* tokens = new vector<string>();
	for (int i = 0; i < tempLoginInfo->size(); i++)
		fix.split(tempLoginInfo->at(i), ' ', tokens);
	for (int i = 0; i < tokens->size() / 2; i++) {
		string* tempID = new string();
		*tempID = tokens->at(2 * i).substr(0, tokens->at(2 * i).length());
		string* tempPW = new string();
		*tempPW = tokens->at(2 * i + 1).substr(0, tokens->at(2 * i + 1).length());
		userLoginInfo->insert({ (*tempID).c_str(), (*tempPW).c_str() });
	}
	delete tokens;
	delete tempLoginInfo;
}

void SignUpInAdapter::signUp(const char* ID, const char* PW, bool* success)
{
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it)
		if (!strcmp(it->first, ID)) {
			*success = false;
			return;
		}
	userLoginInfo->insert({ ID, PW });
	vector<const char*>* tempLoginInfo = new vector<const char*>();
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
		string* temp = new string();
		*temp = it->first;
		*temp += " ";
		*temp += it->second;
		tempLoginInfo->push_back((*temp).c_str());
	}
	FileSystemAdapter fileSys;
	fileSys.fileOut(path, tempLoginInfo);
	delete tempLoginInfo;
	*success = true;
}

void SignUpInAdapter::signIn(char* inputID, const char* inputPW, char **ID)
{
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it)
		if (!strcmp(it->first, inputID) && !strcmp(it->second, inputPW))
			*ID = inputID;
}

void SignUpInAdapter::signOut(char** ID)
{
	if (*ID != "")
		*ID = "";
}

void SignUpInAdapter::DeleteAccount(const char* ID, const char* PW, bool* success)
{
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it)
		if (!strcmp(it->first, ID) && !strcmp(it->second, PW)) {
			userLoginInfo->erase(it);
			vector<const char*>* tempLoginInfo = new vector<const char*>();
			for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
				string* temp = new string();
				*temp = it->first;
				*temp += " ";
				*temp += it->second;
				tempLoginInfo->push_back((*temp).c_str());
			}
			FileSystemAdapter fileSys;
			fileSys.fileOut(path, tempLoginInfo);
			delete tempLoginInfo;
			*success = true;
			return;
		}
	*success = false;
}
