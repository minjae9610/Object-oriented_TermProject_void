#pragma once
#include <map>
#include <direct.h>
#include "FileSystemForWindow.h"
#include "StringFixAdapter.h"

class MapBinaryFileSystemAdapter : public FileSystemForWindow<map<const char *, const char *>*> {
public:
	void fileIn(const char *, map<const char *, const char *>*) override;
	void fileOut(char*, map<const char *, const char *>*) override;
};