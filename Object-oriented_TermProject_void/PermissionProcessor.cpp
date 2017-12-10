#include "stdafx.h"
#include "PermissionProcessor.h"

void PermissionProcessor::fileExtraction(char* name, vector<Permission*>* permissions) {
	for (int i = 0; i < permissions->size(); i++)
		delete permissions->at(i);
	permissions->clear();
	vector<const char*>* permissionFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn("SystemData\\UserPermissionInfo.VOID_DB", permissionFile);
	for (int i = 0; i + 1 < permissionFile->size(); i++) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, permissionFile->at(i + 1));
		if (!strcmp(permissionFile->at(i), name)) {
			for (int j = 0; j < temp; j++)
				permissions->push_back(new Permission(permissionFile->at(i + 2 + j)));
		}
		i += temp + 1;
	}
}

void PermissionProcessor::fileRenewal(char* name, vector<Permission*>* permissions)
{
	vector<const char*>* permissionFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn("SystemData\\UserPermissionInfo.VOID_DB", permissionFile);
	bool find = false;
	int index = 0;
	for (int i = 0; i < permissionFile->size(); i++) {
		if (!strcmp(permissionFile->at(i), name)) {
			find = true;
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
	vector<const char*>* permissionList = new vector<const char*>();
	for (int i = 0; i < permissions->size(); i++)
		permissionList->push_back(permissions->at(i)->getPermission());
	if (find) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, permissionFile->at(index));
		permissionFile->erase(permissionFile->begin() + index, permissionFile->begin() + index + temp + 1);
		char* permissionSize;
		SFA.intToChar(permissionList->size(), &permissionSize);
		permissionFile->insert(permissionFile->begin() + index, permissionSize);
		for (int i = 0; i < permissionList->size(); i++)
			if (permissionFile->size() > index + i + 1)
				permissionFile->insert(permissionFile->begin() + index + i + 1, permissionList->at(i));
			else
				permissionFile->push_back(permissionList->at(i));
	}
	else {
		permissionFile->push_back(name);
		StringFixAdapter SFA;
		char* permissionSize;
		SFA.intToChar(permissionList->size(), &permissionSize);
		permissionFile->push_back(permissionSize);
		for (int i = 0; i < permissionList->size(); i++)
			permissionFile->push_back(permissionList->at(i));
	}
	delete permissionList;
	VBFSA.fileOut("SystemData\\UserPermissionInfo.VOID_DB", permissionFile);
	delete permissionFile;
}

void PermissionProcessor::subjectList(vector<const char*>* subjects)
{
	subjects->clear();
	vector<const char*>* permissionFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn("SystemData\\UserPermissionInfo.VOID_DB", permissionFile);
	for (int i = 0; i < permissionFile->size(); i++) {
		subjects->push_back(permissionFile->at(i));
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, permissionFile->at(i + 1));
		i += temp + 1;
	}
	delete permissionFile;
}

void PermissionProcessor::subjectDelete(char* name, bool* success)
{
	*success = false;
	vector<const char*>* permissionFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn("SystemData\\UserPermissionInfo.VOID_DB", permissionFile);
	for (int i = 0; i < permissionFile->size(); i++) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, permissionFile->at(i + 1));
		if (!strcmp(permissionFile->at(i), name)) {
			permissionFile->erase(permissionFile->begin() + i, permissionFile->begin() + i + temp + 2);
			*success = true;
			break;
		}
		else
			i += temp + 1;
	}
	VBFSA.fileOut("SystemData\\UserPermissionInfo.VOID_DB", permissionFile);
	delete permissionFile;
}

void PermissionProcessor::permissionOwnerList(Permission* permission, vector<const char*>* userList)
{
	userList->clear();
	vector<const char*>* subjects = new vector<const char*>();
	subjectList(subjects);
	for (int i = 0; i < subjects->size(); i++) {
		StringFixAdapter SFA;
		char* temp;
		SFA.constToNot(subjects->at(i), &temp);
		vector<Permission*>* permissionList = new vector<Permission*>();
		fileExtraction(temp, permissionList);
		for (int j = 0; j < permissionList->size(); j++) {
			if (*permissionList->at(j) == *permission)
				userList->push_back(subjects->at(i));
			delete permissionList->at(j);
		}
		delete permissionList;
	}
	delete subjects;
}
