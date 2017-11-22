#pragma once
#include <fstream>
#include <direct.h>
#include "StringFixAdapter.h"

using namespace std;

class FileSystemAdapter{
public:
	void fileIn(const char *, vector<const char *>*);
	void fileOut(char *, vector<const char *>*);
	void fileRemove(const char *, int *);
private:
	bool fileFind(const char *);
};