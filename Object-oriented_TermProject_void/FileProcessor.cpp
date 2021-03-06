#include "stdafx.h"
#include "FileProcessor.h"

void FileProcessor::fileRead(const char* fileName, vector<const char*>* contents, Permission** permissions)
{
	contents->clear();
	string tempPath = "SystemData\\VOID\\";
	tempPath += fileName;
	if (strcmp(&tempPath.at(tempPath.length() - 5), ".VOID"))
		tempPath += ".VOID";
	vector<const char*>* allContents = new vector<const char*>();
	VectorFileSystemAdapter VFSA;
	VFSA.fileIn(tempPath.c_str(), allContents);
	if (allContents->size() != 0) {
		*permissions = new Permission(allContents->at(0));
		for (int i = 1; i < allContents->size(); i++)
			contents->push_back(allContents->at(i));
	}
}

void FileProcessor::fileWirte(char* fileName, vector<const char*>* contents, Permission* permissions)
{
	vector<const char*>* finalContents = new vector<const char*>();
	finalContents->reserve(contents->size() + 1);
	finalContents->push_back(permissions->getPermission());
	finalContents->insert(finalContents->end(), contents->begin(), contents->end());
	string tempPath = "SystemData\\VOID\\";
	tempPath += fileName;
	if (strcmp(&tempPath.at(tempPath.length() - 5), ".VOID"))
		tempPath += ".VOID";
	char* ptr;
	StringFixAdapter SFA;
	SFA.constToNot(tempPath.c_str(), &ptr);
	VectorFileSystemAdapter VFSA;
	VFSA.fileOut(ptr, finalContents);
	delete finalContents;
}

void FileProcessor::fileRemove(const char* fileName, int* isFileRemoved)
{
	string temp = "SystemData\\VOID\\";
	temp += fileName;
	temp += ".VOID";
	VectorFileSystemAdapter VFSA;
	VFSA.fileRemove(temp.c_str(), isFileRemoved);
}

void FileProcessor::fileList(vector<const char*>* fileList)
{
	fileList->clear();
	VectorFileSystemAdapter VFSA;
	VFSA.fileListFind("SystemData\\VOID\\*.VOID", fileList);
}
