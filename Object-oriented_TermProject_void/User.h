#pragma once
#include <vector>
#include "Permission.h"
#include "Processor.h"

class User {
private:
	char* userName;
	vector<Permission*>* permissions;
public:
	~User();
	User() {}
	User(char*);
	void addPermission(Permission *);
	void deletePermission(Permission *, bool *);
	void searchPermission(Permission *, int *);
	char* getUserName();
};