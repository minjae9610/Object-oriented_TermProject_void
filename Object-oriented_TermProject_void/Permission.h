#pragma once
#include <iostream>

class Permission {
private:
	const char* permission;
public:
	Permission(const char*);
	const char* getPermission();
	bool operator== (Permission &);
};