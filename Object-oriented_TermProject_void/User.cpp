#include "stdafx.h"
#include "User.h"
#include "Processor.h"

User::User(char* name)
{
	userName = name;
	permissions = new vector<Permission*>();
	groups = new vector<Group*>();
	PermissionProcessor PP;
	PP.fileExtraction("SystemData\\UserPermissionInfo.VOID_DB", userName, permissions);
	if (permissions->size() == 0)
		PP.fileRenewal("SystemData\\UserPermissionInfo.VOID_DB", userName, permissions);
	GroupProcessor GP;
	GP.fileExtraction("SystemData\\GroupInfo.VOID_DB", userName, groups);
	if (groups->size() == 0)
		GP.fileRenewal("SystemData\\GroupInfo.VOID_DB", userName, groups);
}

void User::addPermission(Permission* permission)
{
	permissions->push_back(permission);
	PermissionProcessor PP;
	PP.fileRenewal("SystemData\\UserPermissionInfo.VOID_DB", userName, permissions);
}

void User::deletePermission(const char* name, bool* success)
{
	int perNum;
	searchPermission(name, &perNum);
	if (perNum != -1) {
		permissions->erase(permissions->begin() + perNum);
		PermissionProcessor PP;
		PP.fileRenewal("SystemData\\UserPermissionInfo.VOID_DB", userName, permissions);
		*success = true;
		return;
	}
}

void User::searchPermission(const char* name, int* num)
{
	for (int i = 0; i < permissions->size(); i++) {
		if (!strcmp(permissions->at(i)->getPermission(), name)) {
			*num = i;
			return;
		}
	}
	*num = -1;
}

void User::addGroup(Group* group)
{
	groups->push_back(group);
	GroupProcessor GP;
	GP.fileRenewal("SystemData\\GroupInfo.VOID_DB", userName, groups);
}

void User::deleteGroup(const char* name, bool* success)
{
	int groupNum;
	searchGroup(name, &groupNum);
	if (groupNum != -1) {
		groups->erase(groups->begin() + groupNum);
		GroupProcessor GP;
		GP.fileRenewal("SystemData\\UserGroupInfo.VOID_DB", userName, groups);
		*success = true;
		return;
	}
}

void User::searchGroup(const char* name, int* num)
{
	for (int i = 0; i < groups->size(); i++) {
		if (!strcmp(groups->at(i)->getGroupName(), name)) {
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
