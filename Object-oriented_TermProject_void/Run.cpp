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
		PFC.printCharArrayWithEndLine("------------------------");
		PFC.printCharArrayWithEndLine(" 1 : ���� ����");
		PFC.printCharArrayWithEndLine(" 2 : ���� �ۼ�");
		PFC.printCharArrayWithEndLine(" 3 : ���� �����ϱ�");
		PFC.printCharArrayWithEndLine(" 4 : �� ���� ����");
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
			read();
			break;
		case 2:
			write();
			break;
		case 3:
			remove();
			break;
		case 0:
			delete user;
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
				if (ID == userList->at(i))
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
			break;
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
			break;
		}
	}
}

void Run::write()
{
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------- ���� �ۼ� ----------");
			PFC.printCharArray(" �ۼ��� ���� �̸� �Է� (Ȯ���� ����) (-1 �Է½� �޴��� ����) : ");
			string path;
			getline(cin, path);
			if (path.length() >= 120)
				throw "���� �̸��� 120�� ���Ͽ��� �մϴ�.";
			if (path == "-1")
				break;
			Permission* NULLPermission = new Permission();
			Permission* filePermission = NULLPermission;
			FileProcessor FP;
			vector<const char*>* contents = new vector<const char*>();
			FP.fileRead(path.c_str(), contents, &filePermission);
			if (filePermission != NULLPermission && *filePermission != Permission(user->getUserName())) {
				delete contents;
				delete filePermission;
				delete NULLPermission;
				throw "�ٸ� ����ڰ� �ش� �̸��� ������ �̹� ��������ϴ�.";
			}
			delete NULLPermission;
			contents->clear();
			PFC.printCharArrayWithEndLine("------------------------");
			PFC.printCharArrayWithEndLine(" ���� ���� �Է� (EOF �Է½� ���� �Է� ����)");
			PFC.printCharArrayWithEndLine("");
			while (true) {
				PFC.printCharArray(" ");
				string* contentsLine = new string();
				getline(cin, *contentsLine);
				if (*contentsLine == "EOF")
					break;
				contents->push_back(contentsLine->c_str());
			}
			StringFixAdapter SFA;
			char* str;
			SFA.constToNot(path.c_str(), &str);
			FP.fileWirte(str, contents, &Permission(user->getUserName()));
			delete contents;
			break;
		}
		catch (const char* st) {
			PFC.printError(st);
		}
	}
}

void Run::read()
{
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------- ���� �ۼ� ----------");
			PFC.printCharArrayWithEndLine(" ���� ����Ʈ");
			PFC.printCharArrayWithEndLine("");
			FileProcessor FP;
			vector<const char*>* fileList = new vector<const char*>();
			FP.fileList(fileList);
			vector<const char*>* contents = new vector<const char*>();
			for (int i = 0; i < fileList->size(); i++) {
				PFC.printCharArray(" ");
				PFC.printCharArray(fileList->at(i));
				PFC.printCharArray(" - �ۼ��� : ");
				Permission* fileWriter;
				FP.fileRead(fileList->at(i), contents, &fileWriter);
				PFC.printCharArrayWithEndLine(fileWriter->getPermission());
				contents->clear();
				delete fileWriter;
			}
			delete fileList;
			PFC.printCharArrayWithEndLine("------------------------");
			PFC.printCharArray(" Ȯ���� ���� �̸� �Է� (Ȯ���� ����) (-1 �Է½� �޴��� ����) : ");
			string path;
			getline(cin, path);
			if (path.length() >= 120)
				throw "���� �̸��� 120�� ���Ͽ��� �մϴ�.";
			if (path == "-1")
				break;
			Permission* NULLPermission = new Permission();
			Permission* filePermission = NULLPermission;
			FP.fileRead(path.c_str(), contents, &filePermission);
			if (filePermission == NULLPermission) {
				delete contents;
				delete NULLPermission;
				throw "�ش� ������ �����ϴ�.";
			}
			delete NULLPermission;
			if (*filePermission != Permission(user->getUserName())) {
				throw "�ش� ���Ͽ� ���� ���� ������ �����ϴ�.";
				delete filePermission;
			}
			delete filePermission;
			PFC.clearScrean();
			PFC.printCharArray("\n--------- ");
			PFC.printCharArray(path.c_str());
			PFC.printCharArrayWithEndLine(" ----------");
			PFC.printCharArrayWithEndLine("");
			for (int i = 0; i < contents->size(); i++) {
				PFC.printCharArray(" ");
				PFC.printCharArrayWithEndLine(contents->at(i));
			}
			delete contents;
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("------------------------");
			PFC.pause();
			break;
		}
		catch (const char* st) {
			PFC.printError(st);
		}
	}
}

void Run::remove()
{
}

void Run::testCase()
{
	TestFileSys TFS;
	TFS.test1();
}
