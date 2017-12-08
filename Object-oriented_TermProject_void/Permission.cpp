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

bool Permission::operator==(const Permission& target) const
{
	return !strcmp(permission, target.permission);
}

bool Permission::operator!=(const Permission& target) const
{
	return strcmp(permission, target.permission);
}
