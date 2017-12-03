#include "stdafx.h"
#include "VectorBinaryFileSystemAdapter.h"

void VectorBinaryFileSystemAdapter::fileIn(const char* path, vector<const char*>* st)
{
	if (fileFind(path)) {
		ifstream inFile(path, ios::in | ios::binary);
		int sizeVector = 0;
		inFile.read((char *)&sizeVector, sizeof(sizeVector));
		for (int i = 0; i < sizeVector; i++)
		{
			int sizeStr = 0;
			inFile.read((char *)&sizeStr, sizeof(sizeStr));
			char* tempStr = new char[sizeStr + 1]();
			inFile.read(tempStr, sizeStr);

			st->push_back(vector<const char *>::value_type(tempStr));
		}
		inFile.close();
	}
}

void VectorBinaryFileSystemAdapter::fileOut(char* path, vector<const char*>* st)
{
	if (!fileFind(path))
		mkDir(path);
	ofstream outFile(path, ios::out | ios::binary);
	int sizeVector = st->size();
	outFile.write((const char *)&sizeVector, sizeof(sizeVector));
	for (int i = 0; i < sizeVector; i++)
	{
		string tempStr = st->at(i);
		int sizeStr = tempStr.length() + 1;
		outFile.write((const char *)&sizeStr, sizeof(sizeStr));
		outFile.write(tempStr.c_str(), sizeStr);
	}
	outFile.close();
}
