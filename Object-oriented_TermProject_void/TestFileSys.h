#pragma once
#include "SignUpInAdapter.h"

class TestFileSys {
public:
	void test1() {
		cout << "���� ���� �׽�Ʈ 1 (test.txt ������ test1 ���� �ȿ� ����)" << endl;
		vector<const char *>* contents = new vector<const char*>();
		contents->push_back("�׽�Ʈ1");
		contents->push_back("�׽�Ʈ2");
		FileSystemClient* fileSys = new FileSystemAdapter();
		fileSys->fileOut("test1\\test.txt", contents);
		contents->clear();
		delete fileSys;
		cout << endl;

		cout << "���� ���� �׽�Ʈ 2 (test.txt ������ test1 ���� ���� test2 ���� �ȿ� ����)" << endl;
		contents->push_back("�׽�Ʈ1");
		contents->push_back("�׽�Ʈ2");
		contents->push_back("�׽�Ʈ3");
		fileSys = new FileSystemAdapter();
		fileSys->fileOut("test1\\test2\\test.txt", contents);
		contents->clear();
		delete fileSys;
		cout << endl;

		cout << "���� �б� �׽�Ʈ 1 (test1 ���� ���� test.txt ���� �б�)" << endl;
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("test1\\test.txt", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;
		contents->clear();

		cout << "���� �б� �׽�Ʈ 2 (test1 ���� ���� test2 ���� ���� test.txt ���� �б�)" << endl;
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("test1\\test2\\test.txt", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;
		contents->clear();

		cout << "���� �б� �׽�Ʈ 3 (�������� �ʴ� ���� �б�)" << endl;
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("asadasd", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;
		contents->clear();
		delete contents;

		cout << "���� ���� �׽�Ʈ 1 (test1 ���� ���� test2 ���� ���� test.txt ����)" << endl;
		int isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("test1\\test2\\test.txt", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� ���� �׽�Ʈ 2 (test1 ���� ���� test.txt ����)" << endl;
		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("test1\\test.txt", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� ���� �׽�Ʈ 3 (���� ���� ����)" << endl;
		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("hguyguy", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 1 (testID1, testPW1)" << endl;
		SignUpInClient* sign = new SignUpInAdapter();
		bool success = false;
		sign->signUp("testID1", "testPW1", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 2 (testID2, testPW2)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->signUp("testID2", "testPW2", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "�����ϴ� ���̵�� ȸ�� ���� �׽�Ʈ 1 (testID1, testPW3)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->signUp("testID1", "testPW3", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "�α��� �׽�Ʈ 1 (���� ���̵��)" << endl;
		sign = new SignUpInAdapter();
		char* ID = "";
		sign->signIn("testID3", "testPW3", &ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "�α��� �׽�Ʈ 2 (�߸��� ��й�ȣ��)" << endl;
		sign = new SignUpInAdapter();
		sign->signIn("testID1", "testPW2", &ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "�α��� �׽�Ʈ 3 (�����ϴ� ���̵��� �˸��� ��й�ȣ��)" << endl;
		sign = new SignUpInAdapter();
		sign->signIn("testID1", "testPW1", &ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "�α׾ƿ� �׽�Ʈ" << endl;
		sign = new SignUpInAdapter();
		sign->signOut(&ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 Ʋ�� ��й�ȣ)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->DeleteAccount("testID2", "testPW3", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 �´� ��й�ȣ)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->DeleteAccount("testID2", "testPW2", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (���� ���̵�)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->DeleteAccount("testID3", "testPW3", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "���� ������ ���̽� ����" << endl;
		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("SystemData\\UserLoginInfo.LoginInfoDB", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;
	}
};