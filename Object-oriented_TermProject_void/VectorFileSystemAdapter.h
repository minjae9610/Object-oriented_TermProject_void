#pragma once
#include <vector>
#include <direct.h>
#include "FileSystemClient.h"
#include "StringFixAdapter.h"

class VectorFileSystemAdapter : public FileSystemClient<vector<const char *>*> {
public:
	void fileIn(const char *, vector<const char *>*) override;
	void fileOut(char *, vector<const char *>*) override;
};