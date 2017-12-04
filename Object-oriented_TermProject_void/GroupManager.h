#pragma once
#include "VectorBinaryFileSystemAdapter.h"
#include "Group.h"

class GroupManager {
public:
	void fileExtraction(char *, char *, vector<Group*>*);
	void fileRenewal(char *, char *, vector<Group*>*);
	void subjectList(char *, vector<const char *>*);
	void subjectDelete(char *, char *, bool *);
	void groupDelete(char *, char *);
};