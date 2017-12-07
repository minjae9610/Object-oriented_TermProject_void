#include "stdafx.h"
#include "FileManager.h"

void FileManager::fileRead(const char* fileName, vector<const char*>* contents, vector<const char*>* permissions)
{
	string temp = "SystemData\\VOID\\";
	temp += fileName;
	temp += ".VOID";
	vector<const char*>* allContents = new vector<const char*>();
	VectorFileSystemAdapter VFSA;
	VFSA.fileIn(temp.c_str(), allContents);
	int permissionsSize = 0;
	StringFixAdapter SFA;
	SFA.charToInt(&permissionsSize, allContents->at(0));
	for (int i = 1; i < permissionsSize + 1; i++)
		permissions->push_back(allContents->at(i));
	for (int i = permissionsSize + 1; i < allContents->size(); i++)
		contents->push_back(allContents->at(i));
}

void FileManager::fileWirte(char* fileName, vector<const char*>* contents, vector<const char*>* permissions)
{
	vector<const char*>* finalContents = new vector<const char*>();
	finalContents->reserve(permissions->size() + contents->size() + 1);
	char* permissionsSize;
	StringFixAdapter SFA;
	SFA.intToChar(permissions->size(), &permissionsSize);
	finalContents->push_back(permissionsSize);
	finalContents->insert(finalContents->end(), permissions->begin(), permissions->end());
	finalContents->insert(finalContents->end(), contents->begin(), contents->end());
	string temp = "SystemData\\VOID\\";
	temp += fileName;
	temp += ".VOID";
	char* ptr;
	SFA.constToNot(temp.c_str(), &ptr);
	VectorFileSystemAdapter VFSA;
	VFSA.fileOut(ptr, finalContents);
	delete finalContents;
}

void FileManager::fileRemove(const char* fileName, int* isFileRemoved)
{
	string temp = "SystemData\\VOID\\";
	temp += fileName;
	temp += ".VOID";
	VectorFileSystemAdapter VFSA;
	VFSA.fileRemove(temp.c_str(), isFileRemoved);
}

void FileManager::fileList(vector<const char*>* fileList)
{
	VectorFileSystemAdapter VFSA;
	VFSA.fileListFind("SystemData\\VOID\\*.VOID", fileList);
}
