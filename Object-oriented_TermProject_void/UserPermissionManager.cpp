#include "stdafx.h"
#include "UserPermissionManager.h"

void UserPermissionManager::fileExtraction(char* userName, vector<Permission*>* userPermissions)
{
	vector<const char*>* permissionFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn("SystemData\\UserPermissionInfo.PermissionInfoDB.txt", permissionFile);
	for (int i = 0; i < permissionFile->size(); i++) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, permissionFile->at(i + 1));
		if (!strcmp(permissionFile->at(i), userName)) {
			for(int j = 0; j < temp; j++)
				userPermissions->push_back(new Permission(permissionFile->at(i + 2 + j)));
		}
		else {
			i += temp + 1;
		}
	}

}

void UserPermissionManager::fileRenewal(char* userName, vector<Permission*>* userPermissions)
{
	vector<const char*>* permissionFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn("SystemData\\UserPermissionInfo.PermissionInfoDB.txt", permissionFile);
	bool findUser = false;
	int index = 0;
	for (int i = 0; i < permissionFile->size(); i++) {
		if (!strcmp(permissionFile->at(i), userName)) {
			findUser = true;
			index = i + 1;
			break;
		}
		else {
			StringFixAdapter SFA;
			int temp = 0;
			SFA.charToInt(&temp, permissionFile->at(i + 1));
			i += temp + 1;
		}
	}
	vector<const char*>* permissions = new vector<const char*>();
	for (int i = 0; i < userPermissions->size(); i++)
		permissions->push_back(userPermissions->at(i)->getPermission());
	if (findUser) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, permissionFile->at(index));
		vector<const char*>::iterator it = permissionFile->begin();
		permissionFile->erase(it + index, it + index + temp + 1);
		char* permissionSize;
		SFA.intToChar(permissions->size(), &permissionSize);
		it = permissionFile->begin();
		permissionFile->insert(it + index, permissionSize);
		for(int i = 0; i < permissions->size(); i++)
			if (permissionFile->size() > index + i + 1) {
				it = permissionFile->begin();
				permissionFile->insert(it + index + i + 1, permissions->at(i));
			}
			else
				permissionFile->push_back(permissions->at(i));
	}
	else {
		permissionFile->push_back(userName);
		StringFixAdapter SFA;
		char* permissionSize;
		SFA.intToChar(permissions->size(), &permissionSize);
		permissionFile->push_back(permissionSize);
		for (int i = 0; i < permissions->size(); i++)
			permissionFile->push_back(permissions->at(i));
	}
	delete permissions;
	VBFSA.fileOut("SystemData\\UserPermissionInfo.PermissionInfoDB.txt", permissionFile);
	delete permissionFile;
}
