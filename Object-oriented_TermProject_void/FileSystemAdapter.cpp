#include "stdafx.h"
#include "FileSystemAdapter.h"

void FileSystemAdapter::fileIn(const char* path, vector<const char*>* contents)
{
	if (fileFind(path)) {
		ifstream inFile(path);
		while (!inFile.eof()) {
			char* line = new char[1000];
			inFile.getline(line, 1000);
			contents->push_back(line);
		}
		inFile.close();
	}
}

void FileSystemAdapter::fileOut(char* path, vector<const char*>* contents)
{
	if (!fileFind(path)) {
		StringFixAdapter* fix = new StringFixAdapter();
		vector<string>* tokens = new vector<string>();
		delete fix;
		fix->split(path, '\\', tokens);
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
	ofstream outFile(path);
	for (int i = 0; i < contents->size() - 1; i++)
		outFile << contents->at(i) << endl;
	outFile << contents->at(contents->size() - 1);
	outFile.close();
}

void FileSystemAdapter::fileRemove(const char* path, int* isFileRemoved)
{
	*isFileRemoved = remove(path);
}

bool FileSystemAdapter::fileFind(const char* path)
{
	ifstream fileFind(path);
	bool find = fileFind.is_open();
	fileFind.close();
	return find;
}