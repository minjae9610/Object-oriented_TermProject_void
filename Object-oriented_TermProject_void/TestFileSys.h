#pragma once
#include "FileSystemAdapter.h"

class TestFileSys {
public:
	void test1() {
		vector<const char *>* contents = new vector<const char*>();
		contents->push_back("테스트1");
		contents->push_back("테스트2");
		FileSystemClient* fileSys = new FileSystemAdapter();
		fileSys->fileOut("test1\\test.txt", contents);
		delete fileSys;

		contents->clear();
		contents->push_back("테스트1");
		contents->push_back("테스트2");
		contents->push_back("테스트3");
		fileSys = new FileSystemAdapter();
		fileSys->fileOut("test1\\test2\\test.txt", contents);
		delete fileSys;

		contents->clear();
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("test1\\test.txt", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;

		contents->clear();
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("test1\\test2\\test.txt", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;

		contents->clear();
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("asadasd", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;

		delete contents;

		int isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("test1\\test2\\test.txt", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;

		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("test1\\test.txt", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;

		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("hguyguy", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;
	}
};