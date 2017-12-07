#pragma once
#include "VectorFileSystemAdapter.h"

class FileProcessor {
public:
	void fileRead(const char *, vector<const char *>*, vector<const char *>*);
	void fileWirte(char *, vector<const char *>*, vector<const char *>*);
	void fileRemove(const char *, int *);
	void fileList(vector<const char *>*);
};