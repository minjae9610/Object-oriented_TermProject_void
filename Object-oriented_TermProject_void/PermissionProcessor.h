#pragma once
#include "VectorBinaryFileSystemAdapter.h"
#include "Permission.h"

class PermissionProcessor {
public:
	void fileExtraction(char *, vector<Permission*>*);
	void fileRenewal(char *, vector<Permission*>*);
	void subjectList(vector<const char*>*);
	void subjectDelete(char *, bool *);
};