#pragma once
#include "VectorBinaryFileSystemAdapter.h"
#include "Permission.h"

class PermissionManager {
public:
	void fileExtraction(char *, char *, vector<Permission*>*);
	void fileRenewal(char *, char *, vector<Permission*>*);
	void subjectList(char *, vector<const char*>*);
	void subjectDelete(char *, char *, bool *);
};