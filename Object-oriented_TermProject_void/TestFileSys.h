#pragma once
#include "Manager.h"

class TestFileSys {
public:
	void test1() {
		cout << "���� ���� �׽�Ʈ 1 (test.txt ������ test1 ���� �ȿ� ����)" << endl;
		vector<const char *>* contents = new vector<const char*>();
		contents->push_back("�׽�Ʈ1");
		contents->push_back("�׽�Ʈ2");
		VectorFileSystemAdapter VFSA;
		VFSA.fileOut("test1\\test.txt", contents);
		contents->clear();
		cout << endl;

		cout << "���� ���� �׽�Ʈ 2 (test.txt ������ test1 ���� ���� test2 ���� �ȿ� ����)" << endl;
		contents->push_back("�׽�Ʈ1");
		contents->push_back("�׽�Ʈ2");
		contents->push_back("�׽�Ʈ3");
		VFSA.fileOut("test1\\test2\\test.txt", contents);
		contents->clear();
		cout << endl;

		cout << "���� ����Ʈ ���� �׽�Ʈ 1 (������Ʈ ���� ��ü Ȯ��)" << endl;
		vector<const char *>* fileList = new vector<const char *>();
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

		cout << "���� �б� �׽�Ʈ 1 (test1 ���� ���� test.txt ���� �б�)" << endl;
		VFSA.fileIn("test1\\test.txt", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;

		cout << "���� �б� �׽�Ʈ 2 (test1 ���� ���� test2 ���� ���� test.txt ���� �б�)" << endl;
		VFSA.fileIn("test1\\test2\\test.txt", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;

		cout << "���� �б� �׽�Ʈ 3 (�������� �ʴ� ���� �б�)" << endl;
		VFSA.fileIn("asadasd", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;
		delete contents;

		cout << "���� ���� �׽�Ʈ 1 (test1 ���� ���� test2 ���� ���� test.txt ����)" << endl;
		int isFileRemoved = 0;
		VFSA.fileRemove("test1\\test2\\test.txt", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� ���� �׽�Ʈ 2 (test1 ���� ���� test.txt ����)" << endl;
		isFileRemoved = 0;
		VFSA.fileRemove("test1\\test.txt", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� ���� �׽�Ʈ 3 (���� ���� ����)" << endl;
		isFileRemoved = 0;
		VFSA.fileRemove("hguyguy", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 1 (testID1, testPW1)" << endl;
		bool success = false;
		LoginManager LM;
		LM.signUp("testID1", "testPW1", &success);
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� ���� �׽�Ʈ 2 (testID2, testPW2)" << endl;
		success = false;
		LM.signUp("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "�����ϴ� ���̵�� ȸ�� ���� �׽�Ʈ 1 (testID1, testPW3)" << endl;
		success = false;
		LM.signUp("testID1", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 1 (���� ���̵��)" << endl;
		char* ID = "";
		LM.signIn("testID3", "testPW3", &ID);
		cout << ID << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 2 (�߸��� ��й�ȣ��)" << endl;
		LM.signIn("testID1", "testPW2", &ID);
		cout << ID << endl;
		cout << endl;

		cout << "�α��� �׽�Ʈ 3 (�����ϴ� ���̵��� �˸��� ��й�ȣ��)" << endl;
		LM.signIn("testID1", "testPW1", &ID);
		cout << ID << endl;
		cout << endl;

		cout << "�α׾ƿ� �׽�Ʈ" << endl;
		LM.signOut(&ID);
		cout << ID << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 Ʋ�� ��й�ȣ)" << endl;
		success = false;
		LM.DeleteAccount("testID2", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (testID2 �´� ��й�ȣ)" << endl;
		success = false;
		LM.DeleteAccount("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "ȸ�� Ż�� �׽�Ʈ (���� ���̵�)" << endl;
		success = false;
		LM.DeleteAccount("testID3", "testPW3", &success);
		cout << success << endl;
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

		cout << "���� �Ŵ��� ���� ����Ʈ ���� �׽�Ʈ" << endl;
		fileList = new vector<const char *>();
		FM.fileList(fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		delete fileList;
		cout << endl;

		cout << "���� �Ŵ��� ���� ���� �׽�Ʈ 1 (���� ���� ����)" << endl;
		isFileRemoved = 0;
		FM.fileRemove("dasijmi", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "���� �Ŵ��� ���� ���� �׽�Ʈ 2 (testFMFile ���� ����)" << endl;
		isFileRemoved = 0;
		FM.fileRemove("testFMFile", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;
	}
};