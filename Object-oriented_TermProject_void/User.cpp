#include "stdafx.h"
#include "User.h"

User::~User()
{
	for (int i = 0; i < permissions->size(); i++)
		delete permissions->at(i);
	delete permissions;
}

User::User(char* name)
{
	userName = name;
	permissions = new vector<Permission*>();
	PermissionProcessor PP;
	PP.fileExtraction(userName, permissions);
	if (permissions->size() == 0)
		PP.fileRenewal(userName, permissions);
}

void User::addPermission(Permission* permission)
{
	permissions->push_back(permission);
	PermissionProcessor PP;
	PP.fileRenewal(userName, permissions);
}

void User::deletePermission(Permission* permission, bool* success)
{
	int perNum;
	searchPermission(permission, &perNum);
	if (perNum != -1) {
		permissions->erase(permissions->begin() + perNum);
		PermissionProcessor PP;
		PP.fileRenewal(userName, permissions);
		*success = true;
		return;
	}
}

void User::searchPermission(Permission* permission, int* num)
{
	for (int i = 0; i < permissions->size(); i++) {
		if (*permissions->at(i) == *permission) {
			*num = i;
			return;
		}
	}
	*num = -1;
}

char * User::getUserName()
{
	return userName;
}
