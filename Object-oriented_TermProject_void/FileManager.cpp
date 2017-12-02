#include "stdafx.h"
#include "FileManager.h"

void FileManager::fileRead(const char* fileName, vector<const char*>* contents, vector<const char*>* permissions)
{
	string temp = "SystemData\\VOIDFiles\\";
	temp += fileName;
	temp += ".VOID";
	vector<const char*>* allContents = new vector<const char*>();
	VectorFileSystemAdapter fileSys;
	fileSys.fileIn(temp.c_str(), allContents);
	int permissionsSize = 0;
	StringFixAdapter fix;
	fix.charToInt(&permissionsSize, allContents->at(0));
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
	StringFixAdapter fix;
	fix.intToChar(permissions->size(), &permissionsSize);
	finalContents->push_back(permissionsSize);
	finalContents->insert(finalContents->end(), permissions->begin(), permissions->end());
	finalContents->insert(finalContents->end(), contents->begin(), contents->end());
	string temp = "SystemData\\VOIDFiles\\";
	temp += fileName;
	temp += ".VOID";
	vector<char> writable(temp.begin(), temp.end());
	writable.push_back('\0');
	char* ptr = &writable[0];
	VectorFileSystemAdapter fileSys;
	fileSys.fileOut(ptr, finalContents);
	delete finalContents;
}

void FileManager::fileRemove(const char* fileName, int* isFileRemoved)
{
	VectorFileSystemAdapter fileSys;
	string temp = "SystemData\\VOIDFiles\\";
	temp += fileName;
	temp += ".VOID";
	fileSys.fileRemove(temp.c_str(), isFileRemoved);
}

void FileManager::fileList(vector<const char*>* fileList)
{
	VectorFileSystemAdapter fileSys;
	fileSys.fileListFind("SystemData\\VOIDFiles\\*.VOID", fileList);
}
