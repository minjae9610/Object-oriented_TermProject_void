#pragma once
#include <map>
#include <fstream>
#include <direct.h>
#include "BinaryFileSystemClient.h"
#include "StringFixAdapter.h"

class BinaryFileSystemAdapter : public BinaryFileSystemClient<map<const char *, const char *>*> {
public:
	void fileIn(const char* path, map<const char *, const char *>* st) override {
		if (fileFind(path)) {
			ifstream inFile(path, ios::in | ios::binary);
			int32_t sizeMap = 0;
			inFile.read((char *)&sizeMap, sizeof(sizeMap));
			for (int i = 0; i < sizeMap; i++)
			{
				int32_t sizeStrKey = 0;
				inFile.read((char *)&sizeStrKey, sizeof(sizeStrKey));
				string tempKey = "";
				inFile.read((char *)&tempKey, sizeStrKey);

				int32_t sizeStrValue = 0;
				inFile.read((char *)&sizeStrValue, sizeof(sizeStrValue));
				string tempValue = "";
				inFile.read((char *)&tempValue, sizeStrKey);

//				st->insert({ tempKey, tempValue });
			}
			inFile.close();
		}
	}
	void fileOut(char* path, map<const char *, const char *>* st) override {
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
		int32_t sizeMap = st->size();
		outFile.write((const char *)&sizeMap, sizeof(sizeMap));
		for (map<const char *, const char *>::iterator it = st->begin(); it != st->end(); ++it)
		{
			string tempKey = it->first;
			int32_t sizeStrKey = tempKey.length() + 1;
			outFile.write((const char *)&sizeStrKey, sizeof(sizeStrKey));
			outFile.write(tempKey.c_str(), sizeStrKey);

			string tempValue = it->second;
			int32_t sizeStrValue = tempValue.length() + 1;
			outFile.write((const char *)&sizeStrValue, sizeof(sizeStrValue));
			outFile.write(tempValue.c_str(), sizeStrValue);
		}
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