#include "stdafx.h"
#include "MapBinaryFileSystemAdapter.h"

void MapBinaryFileSystemAdapter::fileIn(const char * path, map<const char*, const char*>* st) {
	if (fileFind(path)) {
		ifstream inFile(path, ios::in | ios::binary);
		int sizeMap = 0;
		inFile.read((char *)&sizeMap, sizeof(sizeMap));
		for (int i = 0; i < sizeMap; i++)
		{
			int sizeStrKey = 0;
			inFile.read((char *)&sizeStrKey, sizeof(sizeStrKey));
			char* tempKey = new char[sizeStrKey + 1]();
			inFile.read(tempKey, sizeStrKey);

			int sizeStrValue = 0;
			inFile.read((char *)&sizeStrValue, sizeof(sizeStrValue));
			char* tempValue = new char[sizeStrValue + 1]();
			inFile.read(tempValue, sizeStrValue);

			st->insert(map<const char *, const char *>::value_type(tempKey, tempValue));
		}
		inFile.close();
	}
}

void MapBinaryFileSystemAdapter::fileOut(char * path, map<const char*, const char*>* st)
{
	if (!fileFind(path))
		mkDir(path);
	ofstream outFile(path, ios::out | ios::binary);
	int sizeMap = st->size();
	outFile.write((const char *)&sizeMap, sizeof(sizeMap));
	for (map<const char *, const char *>::iterator it = st->begin(); it != st->end(); ++it)
	{
		string tempKey = it->first;
		int sizeStrKey = tempKey.length() + 1;
		outFile.write((const char *)&sizeStrKey, sizeof(sizeStrKey));
		outFile.write(tempKey.c_str(), sizeStrKey);

		string tempValue = it->second;
		int sizeStrValue = tempValue.length() + 1;
		outFile.write((const char *)&sizeStrValue, sizeof(sizeStrValue));
		outFile.write(tempValue.c_str(), sizeStrValue);
	}
	outFile.close();
}