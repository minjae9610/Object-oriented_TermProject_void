#pragma once
#include <vector>
#include "Permission.h"
#include "Group.h"

class User {
private:
	char* userName;
	vector<Permission*>* permissions;
	vector<Group*>* groups;
public:
	User(char*);
	void addPermission(Permission *);
	void deletePermission(const char *, bool *);
	void searchPermission(const char *, int *);
	void addGroup(Group *);
	void deleteGroup(const char *, bool *);
	void searchGroup(const char *, int *);
	char* getUserName();
};