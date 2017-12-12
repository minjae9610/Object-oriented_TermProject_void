#include "stdafx.h"
#include "Run.h"

void Run::mainMenu()
{
	while (true) {
		if (user == NULLuser) {
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
		PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL ���� ���α׷� ----------------------------------------");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine(" 1 : �α���");
		PFC.printCharArrayWithEndLine(" 2 : ȸ������");
		PFC.printCharArrayWithEndLine(" 0 : ����");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
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
		PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL ���� ���α׷� ----------------------------------------");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArray(" ���� �α��� �� ����� : ");
		PFC.printCharArrayWithEndLine(user->getUserName());
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine(" 1 : ���� ����");
		PFC.printCharArrayWithEndLine(" 2 : ���� �ۼ�");
		PFC.printCharArrayWithEndLine(" 3 : ���� �����ϱ�");
		PFC.printCharArrayWithEndLine(" 4 : �� ���� ����");
		PFC.printCharArrayWithEndLine(" 0 : ����");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
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
		case 4:
			userInfoMenu();
			break;
		case 0:
			delete user;
			user = NULLuser;
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

void Run::userInfoMenu()
{
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL ���� ���α׷� ----------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ���� �α��� �� ����� : ");
			PFC.printCharArrayWithEndLine(user->getUserName());
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 1 : �α׾ƿ�");
			PFC.printCharArrayWithEndLine(" 2 : ȸ��Ż��");
			PFC.printCharArrayWithEndLine(" 3 : ���� ������ �����ϱ�");
			PFC.printCharArrayWithEndLine(" 0 : ���� �޴��� ���ư���");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
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
				signOut();
				return;
			case 2:
				if (DeleteAccount())
					return;
				break;
			case 3:
				permissionManageMenu();
				break;
			case 0:
				return;
			default:
				throw "�Է��� �߸��Ǿ����ϴ�.";
			}
		}
		catch (const char* st) {
			PFC.printError(st);
		}
	}
}

void Run::permissionManageMenu()
{
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL ���� ���α׷� ----------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ���� �α��� �� ����� : ");
			PFC.printCharArrayWithEndLine(user->getUserName());
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 1 : ���� ������ �߰��ϱ�");
			PFC.printCharArrayWithEndLine(" 2 : ���� ������ �����ϱ�");
			PFC.printCharArrayWithEndLine(" 3 : ���� ������ ����Ʈ Ȯ���ϱ�");
			PFC.printCharArrayWithEndLine(" 4 : �� ���� ���� Ȯ���ϱ�");
			PFC.printCharArrayWithEndLine(" 0 : �� ���� ���� �޴��� ���ư���");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
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
				givePermission();
				break;
			case 2:
				removePermission();
				break;
			case 3:
				permissionOwnerList();
				break;
			case 4:
				permissionList();
				break;
			case 0:
				return;
			default:
				throw "�Է��� �߸��Ǿ����ϴ�.";
			}
		}
		catch (const char* st) {
			PFC.printError(st);
		}
	}
}

void Run::signUp()
{
	LoginProcessor LP;
	vector<const char*>* userList = new vector<const char*>();
	LP.getUserList(userList);
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------------------------------------------- ȸ������ ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ID �Է� : ");
			string ID;
			getline(cin, ID);
			for (int i = 0; i < userList->size(); i++)
				if (ID == userList->at(i))
					throw "�̹� �����ϴ� ID �Դϴ�.";
			PFC.printCharArray(" PassWord �Է� : ");
			string PW;
			getline(cin, PW);
			bool isAccountMaked = false;
			LP.signUp(ID.c_str(), PW.c_str(), &isAccountMaked);
			if (isAccountMaked) {
				StringFixAdapter SFA;
				char* id;
				SFA.constToNot(ID.c_str(), &id);
				user = new User(id);
				PFC.clearScrean();
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine(" ȸ�����Կ� �����߽��ϴ�.");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
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
			PFC.printCharArrayWithEndLine("\n---------------------------------------------- �α��� ----------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ID �Է� : ");
			string ID;
			getline(cin, ID);
			PFC.printCharArray(" PassWord �Է� : ");
			string PW;
			getline(cin, PW);
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			bool isAccountFind = false;
			char* id;
			StringFixAdapter SFA;
			SFA.constToNot(ID.c_str(), &id);
			LP.signIn(id, PW.c_str(), &isAccountFind);
			if (isAccountFind) {
				user = new User(id);
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine(" �α��ο� �����߽��ϴ�.");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
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

void Run::signOut()
{
	delete user;
	user = NULLuser;
}

bool Run::DeleteAccount()
{
	int select;
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------------------------------------------- ȸ��Ż�� ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" ���� : ȸ�� Ż�� �ص� �ۼ��� ������ ���� �ְ� �˴ϴ�.");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 1 : YES");
			PFC.printCharArrayWithEndLine(" 2 : NO");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArray(" �Է� : ");
			cin >> select;
			if (!cin || cin.get() != '\n') {
				cin.clear();
				cin.ignore(UINT_MAX, '\n');
				throw "�Է��� �߸��Ǿ����ϴ�.";
			}
			else if (select != 1 && select != 2) {
				throw "�Է��� �߸��Ǿ����ϴ�.";
			}
			if (select == 1) {
				PFC.clearScrean();
				PFC.printCharArrayWithEndLine("\n--------------------------------------------- ȸ��Ż�� ---------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArray(" ��й�ȣ �Է� : ");
				string PW;
				getline(cin, PW);
				LoginProcessor LP;
				bool success = false;
				LP.DeleteAccount(user->getUserName(), PW.c_str(), &success);
				if (success) {
					PFC.clearScrean();
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine(" ȸ�� Ż�� �����߽��ϴ�.");
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.pause();
					signOut();
				}
				else
					throw "��й�ȣ�� �ٸ��ϴ�.";
				return true;
			}
			return false;
		}
		catch (const char* st) {
			PFC.printError(st);
		}
	}
}

void Run::write()
{
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n-------------------------------------------- ���� �ۼ� ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" �ۼ��� ���� �̸� �Է� (-1 �Է½� �޴��� ����) : ");
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
			contents->clear();
			if (filePermission != NULLPermission && *filePermission != Permission(user->getUserName())) {
				delete contents;
				delete filePermission;
				delete NULLPermission;
				throw "�ٸ� ����ڰ� �ش� �̸��� ������ �̹� ��������ϴ�.";
			}
			else if (filePermission != NULLPermission && *filePermission == Permission(user->getUserName())) {
				delete filePermission;
				int select;
				while (true) {
					try {
						PFC.clearScrean();
						PFC.printCharArrayWithEndLine("\n-------------------------------------------- ���� �ۼ� ---------------------------------------------");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine(" �ش� �̸��� ������ �̹� �����մϴ�. ����ðڽ��ϱ�?");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine(" 1 : YES");
						PFC.printCharArrayWithEndLine(" 2 : NO");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
						PFC.printCharArray(" �Է� : ");
						cin >> select;
						if (!cin || cin.get() != '\n') {
							cin.clear();
							cin.ignore(UINT_MAX, '\n');
							throw "�Է��� �߸��Ǿ����ϴ�.";
						}
						else if (select != 1 && select != 2) {
							throw "�Է��� �߸��Ǿ����ϴ�.";
						}
						break;
					}
					catch (const char* st) {
						PFC.printError(st);
					}
				}
				if (select == 2) {
					delete NULLPermission;
					continue;
				}
				PFC.clearScrean();
				PFC.printCharArrayWithEndLine("\n-------------------------------------------- ���� �ۼ� ---------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArray(" �ۼ��� ���� �̸� �Է� (-1 �Է½� �޴��� ����) : ");
				PFC.printCharArrayWithEndLine(path.c_str());
			}
			delete NULLPermission;
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" ���� ���� �Է� (EOF �Է½� ���� �Է� ����)");
			PFC.printCharArrayWithEndLine("");
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
			PFC.printCharArrayWithEndLine("\n-------------------------------------------- ���� �˻� ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
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
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArray(" Ȯ���� ���� �̸� �Է� (-1 �Է½� �޴��� ����) : ");
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
			int findPermission = 0;
			user->searchPermission(filePermission, &findPermission);
			bool hasPermission = false;
			if (*filePermission == Permission(user->getUserName()) || findPermission != -1)
				hasPermission = true;
			delete filePermission;
			if(!hasPermission)
				throw "�ش� ������ ���� ���� ������ �����ϴ�.";
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ���� : ");
			PFC.printCharArray(path.c_str());
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("");
			for (int i = 0; i < contents->size(); i++) {
				PFC.printCharArray(" ");
				PFC.printCharArrayWithEndLine(contents->at(i));
			}
			delete contents;
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
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
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n-------------------------------------------- ���� ���� ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
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
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ������ ���� �̸� �Է� (-1 �Է½� �޴��� ����) : ");
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
			else if (filePermission != NULLPermission && *filePermission != Permission(user->getUserName())) {
				delete contents;
				delete filePermission;
				delete NULLPermission;
				throw "�ٸ� ������� ������ ������ �� �����ϴ�.";
			}
			delete filePermission;
			delete NULLPermission;
			int success = 0;
			FP.fileRemove(path.c_str(), &success);
			if (!success) {
				PFC.clearScrean();
				PFC.printCharArrayWithEndLine("\n-------------------------------------------- ���� ���� ---------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine(" ���� ����Ʈ");
				PFC.printCharArrayWithEndLine("");
				FP.fileList(fileList);
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
				delete contents;
				delete fileList;
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine(" �ش� ���� ������ �����߽��ϴ�.");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
				PFC.pause();
				break;
			}
			else {
				delete contents;
				throw "�ش� ���� ������ �����Ͽ����ϴ�.";
			}
		}
		catch (const char* st) {
			PFC.printError(st);
			break;
		}
	}
}

void Run::givePermission()
{
	try {
		vector<const char*>* userList = new vector<const char*>();
		PermissionProcessor PP;
		PP.subjectList(userList);
		PFC.clearScrean();
		PFC.printCharArrayWithEndLine("\n--------------------------------------- ���� ������ �߰��ϱ� ---------------------------------------");
		PFC.printCharArrayWithEndLine("");
		for (int i = 0; i < userList->size(); i++)
			if (strcmp(userList->at(i), user->getUserName())) {
				PFC.printCharArray(" ");
				PFC.printCharArrayWithEndLine(userList->at(i));
			}
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArray(" ���� �����ڷ� �߰��� ����� : ");
		string ID;
		getline(cin, ID);
		for (int i = 0; i < userList->size(); i++)
			if (ID == userList->at(i))
				if (strcmp(userList->at(i), user->getUserName())) {
					StringFixAdapter SFA;
					char* temp;
					SFA.constToNot(userList->at(i), &temp);
					vector<Permission*>* permissions = new vector<Permission*>();
					PP.fileExtraction(temp, permissions);
					bool alreadyOwn = false;
					for (int j = 0; j < permissions->size(); j++) {
						if (*permissions->at(j) == Permission(user->getUserName()))
							alreadyOwn = true;
						delete permissions->at(j);
					}
					delete permissions;
					PFC.clearScrean();
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArray(" ");
					PFC.printCharArray(userList->at(i));
					if (alreadyOwn)
						PFC.printCharArrayWithEndLine(" ���� �̹� ���� �����ڿ� �߰��Ǿ� �ֽ��ϴ�.");
					else {
						PFC.printCharArrayWithEndLine(" ���� ���� �����ڿ� �߰��Ͽ����ϴ�.");
						User(temp).addPermission(new Permission(user->getUserName()));
					}
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.pause();
					delete userList;
					return;
				}
				else
					throw "�����θ� �߰��� �� �����ϴ�.";
		throw "�������� �ʴ� ������Դϴ�.";
		delete userList;
	}
	catch (const char* st) {
		PFC.printError(st);
	}
}

void Run::removePermission()
{
	try {
		vector<const char*>* userList = new vector<const char*>();
		PermissionProcessor PP;
		PP.permissionOwnerList(&Permission(user->getUserName()), userList);
		PFC.clearScrean();
		PFC.printCharArrayWithEndLine("\n--------------------------------------- ���� ������ �����ϱ� ---------------------------------------");
		PFC.printCharArrayWithEndLine("");
		for (int i = 0; i < userList->size(); i++) {
			PFC.printCharArray(" ");
			PFC.printCharArrayWithEndLine(userList->at(i));
		}
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArray(" ���� �����ڿ��� ������ ����� : ");
		string ID;
		getline(cin, ID);
		for (int i = 0; i < userList->size(); i++)
			if (ID == userList->at(i)) {
				StringFixAdapter SFA;
				char* temp;
				SFA.constToNot(userList->at(i), &temp);
				bool success = false;
				User(temp).deletePermission(&Permission(user->getUserName()), &success);
				if (success) {
					PFC.clearScrean();
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArray(" ");
					PFC.printCharArray(userList->at(i));
					PFC.printCharArrayWithEndLine(" ���� ���� �����ڿ��� �����Ͽ����ϴ�.");
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.pause();
				}
				else
					throw "������ �����Ͽ����ϴ�.";
				delete userList;
				return;
			}
		throw "�������� �ʴ� ������Դϴ�.";
		delete userList;
	}
	catch (const char* st) {
		PFC.printError(st);
	}
}

void Run::permissionOwnerList()
{
	vector<const char*>* userList = new vector<const char*>();
	PermissionProcessor PP;
	PP.permissionOwnerList(&Permission(user->getUserName()), userList);
	PFC.clearScrean();
	PFC.printCharArrayWithEndLine("\n---------------------------------------- ���� ������ ����Ʈ ----------------------------------------");
	PFC.printCharArrayWithEndLine("");
	for (int i = 0; i < userList->size(); i++) {
		PFC.printCharArray(" ");
		PFC.printCharArrayWithEndLine(userList->at(i));
	}
	PFC.printCharArrayWithEndLine("");
	PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
	PFC.pause();
	delete userList;
}

void Run::permissionList()
{
	vector<Permission*>* permissionList = new vector<Permission*>();
	PermissionProcessor PP;
	PP.fileExtraction(user->getUserName(), permissionList);
	PFC.clearScrean();
	PFC.printCharArrayWithEndLine("\n-------------------------------------- �� ���� ���� Ȯ���ϱ� ---------------------------------------");
	PFC.printCharArrayWithEndLine("");
	for (int i = 0; i < permissionList->size(); i++) {
		PFC.printCharArray(" ");
		PFC.printCharArrayWithEndLine(permissionList->at(i)->getPermission());
	}
	PFC.printCharArrayWithEndLine("");
	PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
	PFC.pause();
	delete permissionList;
}
