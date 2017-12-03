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
