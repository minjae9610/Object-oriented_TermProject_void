#include "stdafx.h"
#include "VectorFileSystemAdapter.h"

void VectorFileSystemAdapter::fileIn(const char* path, vector<const char*>* contents)
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

void VectorFileSystemAdapter::fileOut(char* path, vector<const char*>* contents)
{
	if (!fileFind(path))
		mkDir(path);
	ofstream outFile(path);
	for (int i = 0; i < contents->size() - 1; i++)
		outFile << contents->at(i) << endl;
	outFile << contents->at(contents->size() - 1);
	outFile.close();
}