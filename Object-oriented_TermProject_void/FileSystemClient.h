#pragma once
#include <vector>

using namespace std;

template <class T>
class FileSystemClient {
public:
	virtual void fileIn(const char *, T) = 0;
	virtual void fileOut(char *, T) = 0;
	virtual void fileRemove(const char* path, int* isFileRemoved) = 0;
	virtual bool fileFind(const char* path) = 0;
	virtual void fileListFind(const char* path, vector<const char *>* files) = 0;
	virtual void mkDir(const char* path) = 0;
};