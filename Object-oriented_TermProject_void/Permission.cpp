#include "stdafx.h"
#include "Permission.h"

Permission::Permission(const char* per)
{
	permission = per;
}

const char * Permission::getPermission()
{
	return permission;
}

bool Permission::operator==(Permission& target)
{
	if (!strcmp(permission, target.getPermission()))
		return true;
	else
		return false;
}
