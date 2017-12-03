#include "stdafx.h"
#include "LoginManager.h"

void LoginManager::signUp(const char* ID, const char* PW, bool* success)
{
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.LoginInfoDB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it)
		if (!strcmp(it->first, ID)) {
			*success = false;
			return;
		}
	userLoginInfo->insert(map<const char *, const char *>::value_type(ID, PW));
	MBFSA.fileOut("SystemData\\UserLoginInfo.LoginInfoDB", userLoginInfo);
	delete userLoginInfo;
	*success = true;
}

void LoginManager::signIn(char* inputID, const char* inputPW, char **ID)
{
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.LoginInfoDB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
		if (!strcmp(it->first, inputID) && !strcmp(it->second, inputPW))
			*ID = inputID;
		delete it->first;
		delete it->second;
	}
	delete userLoginInfo;
}

void LoginManager::signOut(char** ID)
{
	if (*ID != "")
		*ID = "";
}

void LoginManager::DeleteAccount(const char* ID, const char* PW, bool* success)
{
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.LoginInfoDB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
		if (!strcmp(it->first, ID) && !strcmp(it->second, PW)) {
			userLoginInfo->erase(it);
			MBFSA.fileOut("SystemData\\UserLoginInfo.LoginInfoDB", userLoginInfo);
			*success = true;
			return;
		}
		delete it->first;
		delete it->second;
	}
	delete userLoginInfo;
	*success = false;
}