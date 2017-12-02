#pragma once
#include <vector>
#include <direct.h>
#include "StringFixAdapter.h"
#include "VectorFileSystemAdapter.h"

class FileManager {
public:
	void fileRead(const char *, vector<const char *>*, vector<const char *>*);
	void fileWirte(char *, vector<const char *>*, vector<const char *>*);
	void fileRemove(const char *, int *);
	void fileList(vector<const char *>*);
};