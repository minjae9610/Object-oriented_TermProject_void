#include "stdafx.h"
#include "LoginProcessor.h"

void LoginProcessor::signUp(const char* ID, const char* PW, bool* success)
{
	*success = true;
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it)
		if (!strcmp(it->first, ID)) {
			*success = false;
			break;
		}
	if (*success) {
		userLoginInfo->insert(map<const char *, const char *>::value_type(ID, PW));
		MBFSA.fileOut("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
	}
	delete userLoginInfo;
}

void LoginProcessor::signIn(char* inputID, const char* inputPW, bool* success)
{
	*success = false;
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
		if (!strcmp(it->first, inputID) && !strcmp(it->second, inputPW))
			*success = true;
		delete it->first;
		delete it->second;
	}
	delete userLoginInfo;
}

void LoginProcessor::DeleteAccount(const char* ID, const char* PW, bool* success)
{
	*success = false;
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
		if (!strcmp(it->first, ID) && !strcmp(it->second, PW)) {
			userLoginInfo->erase(it);
			MBFSA.fileOut("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
			StringFixAdapter SFA;
			char* ptr;
			SFA.constToNot(ID, &ptr);
			PermissionProcessor PP;
			PP.subjectDelete(ptr, success);
			*success = true;
			break;
		}
	}
	delete userLoginInfo;
}

void LoginProcessor::getUserList(vector<const char*>* userList)
{
	userList->clear();
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it)
		userList->push_back(it->first);
	delete userLoginInfo;
}
