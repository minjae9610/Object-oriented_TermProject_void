#pragma once
#include "Processor.h"
#include <conio.h>

class TestFileSys {
public:
	void test1() {
		PrintForConsole PFC;
		PFC.clearScrean();

		cout << "���� ����Ʈ ���� �׽�Ʈ 1 (������Ʈ ���� ��ü Ȯ��)" << endl;
		vector<const char *>* fileList = new vector<const char *>();
		VectorFileSystemAdapter VFSA;
		VFSA.fileListFind("*.*", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		cout << endl;

		cout << "���� ����Ʈ ���� �׽�Ʈ 2 (��� ���� ��ü Ȯ��)" << endl;
		VFSA.fileListFind("*.h", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		cout << endl;

		cout << "���� ����Ʈ ���� �׽�Ʈ 3 (cpp ���� ��ü Ȯ��)" << endl;
		VFSA.fileListFind("*.cpp", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		delete fileList;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 1 (testID1, testPW1)" << endl;
		bool success = false;
		LoginProcessor LP;
		LP.signUp("testID1", "testPW1", &success);
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 2 (testID2, testPW2)" << endl;
		success = false;
		LP.signUp("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "�����ϴ� ���̵�� ȸ�� ���� �׽�Ʈ 1 (testID1, testPW3)" << endl;
		success = false;
		LP.signUp("testID1", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "����� ��� ���� �׽�Ʈ" << endl;
		vector<const char*>* userList = new vector<const char*>();
		LP.getUserList(userList);
		for (int i = 0; i < userList->size(); i++)
			cout << userList->at(i) << endl;
		delete userList;
		cout << endl;

		cout << "�α��� �׽�Ʈ 1 (���� ���̵��)" << endl;
		success = false;
		LP.signIn("testID3", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 2 (�߸��� ��й�ȣ��)" << endl;
		success = false;
		LP.signIn("testID1", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 3 (�����ϴ� ���̵��� �˸��� ��й�ȣ��)" << endl;
		success = false;
		LP.signIn("testID1", "testPW1", &success);
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 Ʋ�� ��й�ȣ)" << endl;
		success = false;
		LP.DeleteAccount("testID2", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 �´� ��й�ȣ)" << endl;
		success = false;
		LP.DeleteAccount("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (���� ���̵�)" << endl;
		success = false;
		LP.DeleteAccount("testID3", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "���� �Ŵ��� ���� ���� �׽�Ʈ" << endl;
		int isFileRemoved = 0;
		FileProcessor FP;
		vector<const char*>* tempContents = new vector<const char*>();
		tempContents->push_back("����� - Ȳ����");
		tempContents->push_back("����� - ���ϸ���");
		tempContents->push_back("����սô� ������ - �����");
		Permission* tempPermissions = new Permission("�����");
		FP.fileWirte("testFPFile", tempContents, tempPermissions);
		tempContents->clear();
		delete tempPermissions;
		cout << endl;

		cout << "���� �Ŵ��� ���� �б� �׽�Ʈ" << endl;
		FP.fileRead("testFPFile", tempContents, &tempPermissions);
		cout << tempPermissions->getPermission() << endl;
		for (int i = 0; i < tempContents->size(); i++)
			cout << tempContents->at(i) << endl;
		tempContents->clear();
		delete tempContents;
		delete tempPermissions;
		cout << endl;

		cout << "���� �Ŵ��� ���� ����Ʈ ���� �׽�Ʈ" << endl;
		fileList = new vector<const char *>();
		FP.fileList(fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		delete fileList;
		cout << endl;

		cout << "���� �Ŵ��� ���� ���� �׽�Ʈ 1 (���� ���� ����)" << endl;
		isFileRemoved = 0;
		FP.fileRemove("dasijmi", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� �Ŵ��� ���� ���� �׽�Ʈ 2 (testFPFile ���� ����)" << endl;
		isFileRemoved = 0;
		FP.fileRemove("testFPFile", &isFileRemoved);
		cout << isFileRemoved << endl;
	}
};