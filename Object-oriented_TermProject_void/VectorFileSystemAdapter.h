#pragma once
#include <direct.h>
#include "FileSystemForWindow.h"
#include "StringFixAdapter.h"

class VectorFileSystemAdapter : public FileSystemForWindow<vector<const char *>*> {
public:
	void fileIn(const char *, vector<const char *>*) override;
	void fileOut(char *, vector<const char *>*) override;
};