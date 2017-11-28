#pragma once
#include <map>
#include <direct.h>
#include "FileSystemClient.h"
#include "StringFixAdapter.h"

class BinaryFileSystemAdapter : public FileSystemClient<map<const char *, const char *>*> {
public:
	void fileIn(const char *, map<const char *, const char *>*) override;
	void fileOut(char*, map<const char *, const char *>*) override;
};