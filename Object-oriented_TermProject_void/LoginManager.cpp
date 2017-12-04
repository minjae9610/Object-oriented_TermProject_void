#include "stdafx.h"
#include "LoginManager.h"

void LoginManager::signUp(const char* ID, const char* PW, bool* success)
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

void LoginManager::signIn(char* inputID, const char* inputPW, char **ID)
{
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
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
	*success = false;
	map<const char*, const char*>* userLoginInfo = new map<const char*, const char*>();
	MapBinaryFileSystemAdapter MBFSA;
	MBFSA.fileIn("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
	for (map<const char *, const char *>::iterator it = userLoginInfo->begin(); it != userLoginInfo->end(); ++it) {
		if (!strcmp(it->first, ID) && !strcmp(it->second, PW)) {
			userLoginInfo->erase(it);
			MBFSA.fileOut("SystemData\\UserLoginInfo.VOID_DB", userLoginInfo);
			string temp = ID;
			vector<char> writable(temp.begin(), temp.end());
			writable.push_back('\0');
			char* ptr = &writable[0];
			PermissionManager PM;
			PM.subjectDelete("SystemData\\UserPermissionInfo.VOID_DB", ptr, success);
			GroupManager GM;
			GM.subjectDelete("SystemData\\GroupInfo.VOID_DB", ptr, success);
			break;
		}
		delete it->first;
		delete it->second;
	}
	delete userLoginInfo;
}