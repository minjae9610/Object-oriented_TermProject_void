#pragma once
#include <vector>

class Permission {
private:
	const char* permission;
public:
	Permission(const char*);
	const char* getPermission();
};