#pragma once
#include <vector>
#include "Permission.h"

using namespace std;

class Group {
private:
	char* groupName;
	vector<Permission*>* permissions;
public:
	Group(char*);
	void addPermission(Permission *);
	void deletePermission(const char *, bool *);
	void searchPermission(const char *, int *);
	void deleteGroup(bool *);
	char* getGroupName();
};