#pragma once
#include "VectorFileSystemAdapter.h"
#include "Permission.h"

class FileProcessor {
public:
	void fileRead(const char *, vector<const char *>*, Permission**);
	void fileWirte(char *, vector<const char *>*, Permission*);
	void fileRemove(const char *, int *);
	void fileList(vector<const char *>*);
};