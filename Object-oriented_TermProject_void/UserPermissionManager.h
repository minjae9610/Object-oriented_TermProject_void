#pragma once
#include <vector>
#include "StringFixAdapter.h"
#include "VectorBinaryFileSystemAdapter.h"
#include "Permission.h"

class UserPermissionManager {
public:
	void fileExtraction(char *, vector<Permission*>*);
	void fileRenewal(char *, vector<Permission*>*);
};