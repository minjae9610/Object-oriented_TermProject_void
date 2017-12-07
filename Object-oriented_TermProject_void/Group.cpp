#include "stdafx.h"
#include "Group.h"
#include "Processor.h"

Group::Group(char* name)
{
	groupName = name;
	permissions = new vector<Permission*>();
	PermissionProcessor PP;
	PP.fileExtraction("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
	if (permissions->size() == 0)
		PP.fileRenewal("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
}

void Group::addPermission(Permission* permission)
{
	permissions->push_back(permission);
	PermissionProcessor PP;
	PP.fileRenewal("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
}

void Group::deletePermission(const char* name, bool* success)
{
	int perNum;
	searchPermission(name, &perNum);
	if (perNum != -1) {
		permissions->erase(permissions->begin() + perNum);
		PermissionProcessor PP;
		PP.fileRenewal("SystemData\\GroupPermissionInfo.VOID_DB", groupName, permissions);
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
	PermissionProcessor PP;
	PP.subjectDelete("SystemData\\GroupPermissionInfo.VOID_DB", groupName, success);
	GroupProcessor GP;
	GP.groupDelete("SystemData\\GroupInfo.VOID_DB", groupName);
}

char * Group::getGroupName()
{
	return groupName;
}
