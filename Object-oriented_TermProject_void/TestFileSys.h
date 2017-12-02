#pragma once
#include "SignUpInAdapter.h"
#include "VectorFileSystemAdapter.h"
#include "FileManager.h"

class TestFileSys {
public:
	void test1() {
		cout << "���� ���� �׽�Ʈ 1 (test.txt ������ test1 ���� �ȿ� ����)" << endl;
		vector<const char *>* contents = new vector<const char*>();
		contents->push_back("�׽�Ʈ1");
		contents->push_back("�׽�Ʈ2");
		VectorFileSystemAdapter fileSys;
		fileSys.fileOut("test1\\test.txt", contents);
		contents->clear();
		cout << endl;

		cout << "���� ���� �׽�Ʈ 2 (test.txt ������ test1 ���� ���� test2 ���� �ȿ� ����)" << endl;
		contents->push_back("�׽�Ʈ1");
		contents->push_back("�׽�Ʈ2");
		contents->push_back("�׽�Ʈ3");
		fileSys.fileOut("test1\\test2\\test.txt", contents);
		contents->clear();
		cout << endl;

		cout << "���� ����Ʈ ���� �׽�Ʈ 1 (������Ʈ ���� ��ü Ȯ��)" << endl;
		vector<const char *>* fileList = new vector<const char *>();
		fileSys.fileListFind("*.*", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		cout << endl;

		cout << "���� ����Ʈ ���� �׽�Ʈ 2 (��� ���� ��ü Ȯ��)" << endl;
		fileSys.fileListFind("*.h", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		cout << endl;

		cout << "���� ����Ʈ ���� �׽�Ʈ 3 (cpp ���� ��ü Ȯ��)" << endl;
		fileSys.fileListFind("*.cpp", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		delete fileList;
		cout << endl;

		cout << "���� �б� �׽�Ʈ 1 (test1 ���� ���� test.txt ���� �б�)" << endl;
		fileSys.fileIn("test1\\test.txt", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;

		cout << "���� �б� �׽�Ʈ 2 (test1 ���� ���� test2 ���� ���� test.txt ���� �б�)" << endl;
		fileSys.fileIn("test1\\test2\\test.txt", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;

		cout << "���� �б� �׽�Ʈ 3 (�������� �ʴ� ���� �б�)" << endl;
		fileSys.fileIn("asadasd", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;
		delete contents;

		cout << "���� ���� �׽�Ʈ 1 (test1 ���� ���� test2 ���� ���� test.txt ����)" << endl;
		int isFileRemoved = 0;
		fileSys.fileRemove("test1\\test2\\test.txt", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� ���� �׽�Ʈ 2 (test1 ���� ���� test.txt ����)" << endl;
		isFileRemoved = 0;
		fileSys.fileRemove("test1\\test.txt", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� ���� �׽�Ʈ 3 (���� ���� ����)" << endl;
		isFileRemoved = 0;
		fileSys.fileRemove("hguyguy", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 1 (testID1, testPW1)" << endl;
		bool success = false;
		SignUpInClient* sign = new SignUpInAdapter();
		sign->signUp("testID1", "testPW1", &success);
		delete sign;
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 2 (testID2, testPW2)" << endl;
		success = false;
		sign = new SignUpInAdapter();
		sign->signUp("testID2", "testPW2", &success);
		delete sign;
		cout << success << endl;
		cout << endl;

		cout << "�����ϴ� ���̵�� ȸ�� ���� �׽�Ʈ 1 (testID1, testPW3)" << endl;
		success = false;
		sign = new SignUpInAdapter();
		sign->signUp("testID1", "testPW3", &success);
		delete sign;
		cout << success << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 1 (���� ���̵��)" << endl;
		char* ID = "";
		sign = new SignUpInAdapter();
		sign->signIn("testID3", "testPW3", &ID);
		delete sign;
		cout << ID << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 2 (�߸��� ��й�ȣ��)" << endl;
		sign = new SignUpInAdapter();
		sign->signIn("testID1", "testPW2", &ID);
		delete sign;
		cout << ID << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 3 (�����ϴ� ���̵��� �˸��� ��й�ȣ��)" << endl;
		sign = new SignUpInAdapter();
		sign->signIn("testID1", "testPW1", &ID);
		delete sign;
		cout << ID << endl;
		cout << endl;

		cout << "�α׾ƿ� �׽�Ʈ" << endl;
		sign = new SignUpInAdapter();
		sign->signOut(&ID);
		delete sign;
		cout << ID << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 Ʋ�� ��й�ȣ)" << endl;
		success = false;
		sign = new SignUpInAdapter();
		sign->DeleteAccount("testID2", "testPW3", &success);
		delete sign;
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 �´� ��й�ȣ)" << endl;
		success = false;
		sign = new SignUpInAdapter();
		sign->DeleteAccount("testID2", "testPW2", &success);
		delete sign;
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (���� ���̵�)" << endl;
		success = false;
		sign = new SignUpInAdapter();
		sign->DeleteAccount("testID3", "testPW3", &success);
		delete sign;
		cout << success << endl;
		cout << endl;

		cout << "���� ������ ���̽� ����" << endl;
		isFileRemoved = 0;
		fileSys.fileRemove("SystemData\\UserLoginInfo.LoginInfoDB", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� �Ŵ��� ���� ���� �׽�Ʈ" << endl;
		isFileRemoved = 0;
		FileManager FM;
		vector<const char*>* tempContents = new vector<const char*>();
		tempContents->push_back("����� - Ȳ����");
		tempContents->push_back("����� - ���ϸ���");
		tempContents->push_back("����սô� ������ - �����");
		vector<const char*>* tempPermissions = new vector<const char*>();
		tempPermissions->push_back("Ȳ����");
		tempPermissions->push_back("�����");
		tempPermissions->push_back("�̺���");
		tempPermissions->push_back("��ȿ��");
		FM.fileWirte("testFMFile", tempContents, tempPermissions);
		tempContents->clear();
		tempPermissions->clear();
		cout << endl;

		cout << "���� �Ŵ��� ���� �б� �׽�Ʈ" << endl;
		FM.fileRead("testFMFile", tempContents, tempPermissions);
		for (int i = 0; i < tempPermissions->size(); i++)
			cout << tempPermissions->at(i) << endl;
		for (int i = 0; i < tempContents->size(); i++)
			cout << tempContents->at(i) << endl;
		tempContents->clear();
		tempPermissions->clear();
		delete tempContents;
		delete tempPermissions;
		cout << endl;
	}
};