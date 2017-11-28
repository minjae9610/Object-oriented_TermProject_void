#pragma once
#include <fstream>

using namespace std;

template <class T>
class FileSystemClient {
public:
	virtual void fileIn(const char *, T) = 0;
	virtual void fileOut(char *, T) = 0;
	void fileRemove(const char* path, int* isFileRemoved) {
		*isFileRemoved = remove(path);
	}
	bool fileFind(const char* path) {
		ifstream fileFind(path);
		bool find = fileFind.is_open();
		fileFind.close();
		return find;
	}
};