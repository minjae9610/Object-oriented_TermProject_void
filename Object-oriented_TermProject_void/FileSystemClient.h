#pragma once
#include <vector>

using namespace std;

class FileSystemClient {
public:
	virtual void fileIn(const char *, vector<const char *>*) = 0;
	virtual void fileOut(char *, vector<const char *>*) = 0;
	virtual void fileRemove(const char *, int *) = 0;
private:
	virtual bool fileFind(const char *) = 0;
};