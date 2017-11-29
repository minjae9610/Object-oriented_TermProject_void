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
	MapBinaryFileSystemAdapter file;
	file.fileIn(path, userLoginInfo);
}

void SignUpInAdapter::signUp(const char* ID, const char* PW, bool* success)
{
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it)
		if (!strcmp(it->first, ID)) {
			*success = false;
			return;
		}
	userLoginInfo->insert(map<const char *, const char *>::value_type(ID, PW));
	MapBinaryFileSystemAdapter file;
	file.fileOut(path, userLoginInfo);
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
			MapBinaryFileSystemAdapter file;
			file.fileOut(path, userLoginInfo);
			*success = true;
			return;
		}
	*success = false;
}
