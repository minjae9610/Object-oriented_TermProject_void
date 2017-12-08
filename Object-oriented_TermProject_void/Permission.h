#pragma once
#include <iostream>

class Permission {
private:
	const char* permission;
public:
	Permission() {}
	Permission(const char*);
	const char* getPermission();
	bool operator ==(const Permission &) const;
	bool operator !=(const Permission &) const;
};