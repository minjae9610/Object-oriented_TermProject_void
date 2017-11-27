#pragma once
#include <fstream>
#include <direct.h>
#include "BinaryFileSystemClient.h"
#include "StringFixAdapter.h"

template <class T>
class BinaryFileSystemAdapter : public BinaryFileSystemClient<T> {
public:
	void fileIn(const char* path, T st) override {
		if (fileFind(path)) {
			ifstream inFile(path, ios::in | ios::binary);
			inFile.read((char *)st, sizeof(*st));
			inFile.close();
		}
	}
	void fileOut(char* path, T st) override {
		if (!fileFind(path)) {
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
		ofstream outFile(path, ios::out | ios::binary);
		outFile.write((const char *)st, sizeof(*st));
		outFile.close();
	}
private:
	bool fileFind(const char* path) override {
		ifstream fileFind(path);
		bool find = fileFind.is_open();
		fileFind.close();
		return find;
	}
};