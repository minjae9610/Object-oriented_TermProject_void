#include "stdafx.h"
#include "Group.h"
#include "Manager.h"

Group::Group(char* name)
{
	groupName = name;
	permissions = new vector<Permission*>();
	PermissionManager PM;
	PM.fileExtraction("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
	if (permissions->size() == 0)
		PM.fileRenewal("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
}

void Group::addPermission(Permission* permission)
{
	permissions->push_back(permission);
	PermissionManager PM;
	PM.fileRenewal("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
}

void Group::deletePermission(const char* name, bool* success)
{
	int perNum;
	searchPermission(name, &perNum);
	if (perNum != -1) {
		permissions->erase(permissions->begin() + perNum);
		PermissionManager PM;
		PM.fileRenewal("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
		*success = true;
		return;
	}
}

void Group::searchPermission(const char* name, int* num)
{
	for (int i = 0; i < permissions->size(); i++) {
		if (!strcmp(permissions->at(i)->getPermission(), name)) {
			*num = i;
			return;
		}
	}
	*num = -1;
}

void Group::deleteGroup(bool* success)
{
	PermissionManager PM;
	PM.subjectDelete("SystemData\\GroupPermissionInfo.VOID_DB", groupName, success);
	GroupManager GM;
	GM.groupDelete("SystemData\\GroupInfo.VOID_DB", groupName);
}

char * Group::getGroupName()
{
	return groupName;
}
