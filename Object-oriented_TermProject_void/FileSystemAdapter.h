#pragma once
#include <fstream>
#include <direct.h>
#include "FileSystemClient.h"
#include "StringFixAdapter.h"

class FileSystemAdapter : public FileSystemClient {
public:
	void fileIn(const char *, vector<const char *>*) override;
	void fileOut(char *, vector<const char *>*) override;
	void fileRemove(const char *, int *) override;
private:
	bool fileFind(const char *) override;
};