#pragma once
#include <vector>
#include <direct.h>
#include "StringFixAdapter.h"

class FileManager {
public:
	FileManager();
	void fileRead(const char *, vector<const char *>*);
	void fileWirte(char *, vector<const char *>*);
};