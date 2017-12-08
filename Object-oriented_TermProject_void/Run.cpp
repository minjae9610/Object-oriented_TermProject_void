#include "stdafx.h"
#include "Run.h"

void Run::mainMenu()
{
	while (true) {
		if (!user) {
			if (unLoginMenu())
				break;
		}
		else {
			if (LoginMenu())
				break;
		}
	}
	PFC.clearScrean();
	delete user;
}

bool Run::unLoginMenu()
{
	try {
		PFC.clearScrean();
		PFC.printCharArrayWithEndLine("\n--------- VOID ----------");
		PFC.printCharArrayWithEndLine(" 1 : �α���");
		PFC.printCharArrayWithEndLine(" 2 : ȸ������");
		PFC.printCharArrayWithEndLine(" 3 : �׽�Ʈ ���̽� ����");
		PFC.printCharArrayWithEndLine(" 0 : ����");
		PFC.printCharArrayWithEndLine("------------------------");
		PFC.printCharArray(" �޴� ���� : ");
		int menuSelect;
		cin >> menuSelect;
		if (!cin || cin.get() != '\n') {
			cin.clear();
			cin.ignore(UINT_MAX, '\n');
			throw "�Է��� �߸��Ǿ����ϴ�.";
		}
		switch (menuSelect)
		{
		case 1:
			signIn();
			break;
		case 2:
			signUp();
			break;
		case 3:
			TestFileSys TFS;
			TFS.test1();
			PFC.pause();
			break;
		case 0:
			return true;
		default:
			throw "�Է��� �߸��Ǿ����ϴ�.";
		}
	}
	catch (const char* st) {
		PFC.printError(st);
	}
	return false;
}

bool Run::LoginMenu()
{
	try {
		PFC.clearScrean();
		PFC.printCharArrayWithEndLine("\n--------- VOID ----------");
		PFC.printCharArray(" ���� �α��� �� ����� : ");
		PFC.printCharArrayWithEndLine(user->getUserName());
		PFC.printCharArrayWithEndLine(" 1 : ���� ����");
		PFC.printCharArrayWithEndLine(" 2 : ���� ����");
		PFC.printCharArrayWithEndLine(" 3 : ���� �����ϱ�");
		PFC.printCharArrayWithEndLine(" 4 : �� ������ �� �� �ִ� ����� �����ϱ�");
		PFC.printCharArrayWithEndLine(" 5 : �� ���� �� �׷� ���� ����");
		PFC.printCharArrayWithEndLine(" 6 : �α׾ƿ�");
		PFC.printCharArrayWithEndLine(" 7 : ȸ��Ż��");
		PFC.printCharArrayWithEndLine(" 0 : ����");
		PFC.printCharArrayWithEndLine("------------------------");
		PFC.printCharArray(" �޴� ���� : ");
		int menuSelect;
		cin >> menuSelect;
		if (!cin || cin.get() != '\n') {
			cin.clear();
			cin.ignore(UINT_MAX, '\n');
			throw "�Է��� �߸��Ǿ����ϴ�.";
		}
		switch (menuSelect)
		{
		case 1:
			break;
		case 0:
			return true;
		default:
			throw "�Է��� �߸��Ǿ����ϴ�.";
		}
	}
	catch (const char* st) {
		PFC.printError(st);
	}
	return false;
}

void Run::signUp()
{
	LoginProcessor LP;
	vector<const char*>* userList = new vector<const char*>();
	LP.getUserList(userList);
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------- ȸ������ ----------");
			PFC.printCharArray(" ID �Է� : ");
			string ID;
			getline(cin, ID);
			for (int i = 0; i < userList->size(); i++)
				if (!strcmp(userList->at(i), ID.c_str()))
					throw "�̹� �����ϴ� ID �Դϴ�.";
			PFC.printCharArray(" PassWord �Է� : ");
			string PW;
			getline(cin, PW);
			PFC.printCharArrayWithEndLine("------------------------");
			bool isAccountMaked = false;
			LP.signUp(ID.c_str(), PW.c_str(), &isAccountMaked);
			if (isAccountMaked) {
				StringFixAdapter SFA;
				char* id;
				SFA.constToNot(ID.c_str(), &id);
				user = new User(id);
				PFC.printCharArrayWithEndLine(" ȸ�����Կ� �����߽��ϴ�.");
				PFC.pause();
				break;
			}
			else
				throw "ȸ�����Կ� �����߽��ϴ�.";
		}
		catch (const char* st) {
			PFC.printError(st);
		}
	}
	for (int i = 0; i < userList->size(); i++)
		delete userList->at(i);
	delete userList;
}

void Run::signIn()
{
	LoginProcessor LP;
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------- �α��� ----------");
			PFC.printCharArray(" ID �Է� : ");
			string ID;
			getline(cin, ID);
			PFC.printCharArray(" PassWord �Է� : ");
			string PW;
			getline(cin, PW);
			PFC.printCharArrayWithEndLine("------------------------");
			bool isAccountFind = false;
			char* id;
			StringFixAdapter SFA;
			SFA.constToNot(ID.c_str(), &id);
			LP.signIn(id, PW.c_str(), &isAccountFind);
			if (isAccountFind) {
				user = new User(id);
				PFC.printCharArrayWithEndLine(" �α��ο� �����߽��ϴ�.");
				PFC.pause();
				break;
			}
			else
				throw "�α��ο� �����߽��ϴ�.";
		}
		catch (const char* st) {
			PFC.printError(st);
		}
	}
}

void Run::testCase()
{
	TestFileSys TFS;
	TFS.test1();
}
