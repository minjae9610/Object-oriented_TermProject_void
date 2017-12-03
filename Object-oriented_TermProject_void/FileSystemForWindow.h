#pragma once
#include <fstream>
#include <io.h>
#include <vector>
#include "FileSystemClient.h"

using namespace std;

template <class T>
class FileSystemForWindow : public FileSystemClient<T> {
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
	void fileListFind(const char* path, vector<const char *>* files) {
		_finddata_t fd;
		long handle = _findfirst(path, &fd);
		do {
			string* tempName = new string();
			*tempName = fd.name;
			files->push_back((*tempName).c_str());
		} while (_findnext(handle, &fd) != -1);
		_findclose(handle);
		return;
	}
	void mkDir(const char* path) {
		StringFixAdapter fix;
		vector<string>* tokens = new vector<string>();
		fix.split(path, '\\', tokens);
		for (int i = 0; i < tokens->size() - 1; i++) {
			string tempPath = tokens->at(0);
			for (int j = 1; j <= i; j++) {
				tempPath += "\\";
				tempPath += tokens->at(j);
			}
			_mkdir(tempPath.c_str());
		}
		delete tokens;
	}
};