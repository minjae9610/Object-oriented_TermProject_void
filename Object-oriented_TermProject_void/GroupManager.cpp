#include "stdafx.h"
#include "GroupManager.h"

void GroupManager::fileExtraction(char* path, char* name, vector<Group*>* groups) {
	vector<const char*>* groupFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn(path, groupFile);
	for (int i = 0; i + 1 < groupFile->size(); i++) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, groupFile->at(i + 1));
		if (!strcmp(groupFile->at(i), name)) {
			for (int j = 0; j < temp; j++) {
				string temp = groupFile->at(i + 2 + j);
				vector<char> writable(temp.begin(), temp.end());
				writable.push_back('\0');
				char* ptr = &writable[0];
				groups->push_back(new Group(ptr));
			}
		}
		else {
			i += temp + 1;
		}
	}
}

void GroupManager::fileRenewal(char* path, char* name, vector<Group*>* groups)
{
	vector<const char*>* groupFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn(path, groupFile);
	bool find = false;
	int index = 0;
	for (int i = 0; i < groupFile->size(); i++) {
		if (!strcmp(groupFile->at(i), name)) {
			find = true;
			index = i + 1;
			break;
		}
		else {
			StringFixAdapter SFA;
			int temp = 0;
			SFA.charToInt(&temp, groupFile->at(i + 1));
			i += temp + 1;
		}
	}
	vector<const char*>* groupList = new vector<const char*>();
	for (int i = 0; i < groups->size(); i++)
		groupList->push_back(groups->at(i)->getGroupName());
	if (find) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, groupFile->at(index));
		groupFile->erase(groupFile->begin() + index, groupFile->begin() + index + temp + 1);
		char* groupSize;
		SFA.intToChar(groupList->size(), &groupSize);
		groupFile->insert(groupFile->begin() + index, groupSize);
		for (int i = 0; i < groupList->size(); i++)
			if (groupFile->size() > index + i + 1)
				groupFile->insert(groupFile->begin() + index + i + 1, groupList->at(i));
			else
				groupFile->push_back(groupList->at(i));
	}
	else {
		groupFile->push_back(name);
		StringFixAdapter SFA;
		char* groupSize;
		SFA.intToChar(groupList->size(), &groupSize);
		groupFile->push_back(groupSize);
		for (int i = 0; i < groupList->size(); i++)
			groupFile->push_back(groupList->at(i));
	}
	delete groupList;
	VBFSA.fileOut(path, groupFile);
	delete groupFile;
}

void GroupManager::subjectList(char* path, vector<const char*>* subjects)
{
	vector<const char*>* groupFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn(path, groupFile);
	for (int i = 0; i < groupFile->size(); i++) {
		subjects->push_back(groupFile->at(i));
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, groupFile->at(i + 1));
		i += temp + 1;
	}
	delete groupFile;
}

void GroupManager::subjectDelete(char* path, char* name, bool* success)
{
	*success = false;
	vector<const char*>* groupFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn(path, groupFile);
	for (int i = 0; i < groupFile->size(); i++) {
		StringFixAdapter SFA;
		int temp = 0;
		SFA.charToInt(&temp, groupFile->at(i + 1));
		if (!strcmp(groupFile->at(i), name)) {
			groupFile->erase(groupFile->begin() + i, groupFile->begin() + i + temp + 2);
			*success = true;
			break;
		}
		else
			i += temp + 1;
	}
	VBFSA.fileOut(path, groupFile);
	delete groupFile;
}

void GroupManager::groupDelete(char* path, char* name)
{
	vector<const char*>* groupFile = new vector<const char*>();
	VectorBinaryFileSystemAdapter VBFSA;
	VBFSA.fileIn(path, groupFile);
	for (int i = 0; i + 1 < groupFile->size(); i++) {
		StringFixAdapter SFA;
		int tempInt = 0;
		SFA.charToInt(&tempInt, groupFile->at(i + 1));
		groupFile->erase(groupFile->begin() + i + 1);
		for (int j = i + 1; j < i + 1 + tempInt; j++) {
			if (!strcmp(groupFile->at(j), name)) {
				groupFile->erase(groupFile->begin() + j);
				tempInt--;
			}
		}
		char* tempChar;
		SFA.intToChar(tempInt, &tempChar);
		groupFile->insert(groupFile->begin() + i + 1, tempChar);
		i += 1 + tempInt;
	}
	VBFSA.fileOut(path, groupFile);
	delete groupFile;
}
