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
		PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL 관리 프로그램 ----------------------------------------");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine(" 1 : 로그인");
		PFC.printCharArrayWithEndLine(" 2 : 회원가입");
		PFC.printCharArrayWithEndLine(" 0 : 종료");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArray(" 메뉴 선택 : ");
		int menuSelect;
		cin >> menuSelect;
		if (!cin || cin.get() != '\n') {
			cin.clear();
			cin.ignore(UINT_MAX, '\n');
			throw "입력이 잘못되었습니다.";
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
			throw "입력이 잘못되었습니다.";
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
		PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL 관리 프로그램 ----------------------------------------");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArray(" 현재 로그인 한 사용자 : ");
		PFC.printCharArrayWithEndLine(user->getUserName());
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine(" 1 : 문서 보기");
		PFC.printCharArrayWithEndLine(" 2 : 문서 작성");
		PFC.printCharArrayWithEndLine(" 3 : 문서 삭제하기");
		PFC.printCharArrayWithEndLine(" 4 : 내 정보 설정");
		PFC.printCharArrayWithEndLine(" 0 : 종료");
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArray(" 메뉴 선택 : ");
		int menuSelect;
		cin >> menuSelect;
		if (!cin || cin.get() != '\n') {
			cin.clear();
			cin.ignore(UINT_MAX, '\n');
			throw "입력이 잘못되었습니다.";
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
			throw "입력이 잘못되었습니다.";
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
			PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL 관리 프로그램 ----------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" 현재 로그인 한 사용자 : ");
			PFC.printCharArrayWithEndLine(user->getUserName());
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 1 : 로그아웃");
			PFC.printCharArrayWithEndLine(" 2 : 회원탈퇴");
			PFC.printCharArrayWithEndLine(" 3 : 공동 관리자 관리하기");
			PFC.printCharArrayWithEndLine(" 0 : 메인 메뉴로 돌아가기");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArray(" 메뉴 선택 : ");
			int menuSelect;
			cin >> menuSelect;
			if (!cin || cin.get() != '\n') {
				cin.clear();
				cin.ignore(UINT_MAX, '\n');
				throw "입력이 잘못되었습니다.";
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
				throw "입력이 잘못되었습니다.";
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
			PFC.printCharArrayWithEndLine("\n---------------------------------------- NULL 관리 프로그램 ----------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" 현재 로그인 한 사용자 : ");
			PFC.printCharArrayWithEndLine(user->getUserName());
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 1 : 공동 관리자 추가하기");
			PFC.printCharArrayWithEndLine(" 2 : 공동 관리자 삭제하기");
			PFC.printCharArrayWithEndLine(" 3 : 공동 관리자 리스트 확인하기");
			PFC.printCharArrayWithEndLine(" 4 : 내 관리 권한 확인하기");
			PFC.printCharArrayWithEndLine(" 0 : 내 정보 설정 메뉴로 돌아가기");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArray(" 메뉴 선택 : ");
			int menuSelect;
			cin >> menuSelect;
			if (!cin || cin.get() != '\n') {
				cin.clear();
				cin.ignore(UINT_MAX, '\n');
				throw "입력이 잘못되었습니다.";
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
				throw "입력이 잘못되었습니다.";
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
			PFC.printCharArrayWithEndLine("\n--------------------------------------------- 회원가입 ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ID 입력 : ");
			string ID;
			getline(cin, ID);
			for (int i = 0; i < userList->size(); i++)
				if (ID == userList->at(i))
					throw "이미 존재하는 ID 입니다.";
			PFC.printCharArray(" PassWord 입력 : ");
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
				PFC.printCharArrayWithEndLine(" 회원가입에 성공했습니다.");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
				PFC.pause();
				break;
			}
			else
				throw "회원가입에 실패했습니다.";
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
			PFC.printCharArrayWithEndLine("\n---------------------------------------------- 로그인 ----------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" ID 입력 : ");
			string ID;
			getline(cin, ID);
			PFC.printCharArray(" PassWord 입력 : ");
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
				PFC.printCharArrayWithEndLine(" 로그인에 성공했습니다.");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
				PFC.pause();
				break;
			}
			else
				throw "로그인에 실패했습니다.";
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
			PFC.printCharArrayWithEndLine("\n--------------------------------------------- 회원탈퇴 ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 주의 : 회원 탈퇴를 해도 작성한 문서는 남아 있게 됩니다.");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 1 : YES");
			PFC.printCharArrayWithEndLine(" 2 : NO");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArray(" 입력 : ");
			cin >> select;
			if (!cin || cin.get() != '\n') {
				cin.clear();
				cin.ignore(UINT_MAX, '\n');
				throw "입력이 잘못되었습니다.";
			}
			else if (select != 1 && select != 2) {
				throw "입력이 잘못되었습니다.";
			}
			if (select == 1) {
				PFC.clearScrean();
				PFC.printCharArrayWithEndLine("\n--------------------------------------------- 회원탈퇴 ---------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArray(" 비밀번호 입력 : ");
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
					PFC.printCharArrayWithEndLine(" 회원 탈퇴에 성공했습니다.");
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.pause();
					signOut();
				}
				else
					throw "비밀번호가 다릅니다.";
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
			PFC.printCharArrayWithEndLine("\n-------------------------------------------- 문서 작성 ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" 작성할 문서 이름 입력 (-1 입력시 메뉴로 복귀) : ");
			string path;
			getline(cin, path);
			if (path.length() >= 120)
				throw "문서 이름은 120자 이하여야 합니다.";
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
				throw "다른 사용자가 해당 이름의 문서를 이미 만들었습니다.";
			}
			else if (filePermission != NULLPermission && *filePermission == Permission(user->getUserName())) {
				delete filePermission;
				int select;
				while (true) {
					try {
						PFC.clearScrean();
						PFC.printCharArrayWithEndLine("\n-------------------------------------------- 문서 작성 ---------------------------------------------");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine(" 해당 이름의 문서가 이미 존재합니다. 덮어쓰시겠습니까?");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine(" 1 : YES");
						PFC.printCharArrayWithEndLine(" 2 : NO");
						PFC.printCharArrayWithEndLine("");
						PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
						PFC.printCharArray(" 입력 : ");
						cin >> select;
						if (!cin || cin.get() != '\n') {
							cin.clear();
							cin.ignore(UINT_MAX, '\n');
							throw "입력이 잘못되었습니다.";
						}
						else if (select != 1 && select != 2) {
							throw "입력이 잘못되었습니다.";
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
				PFC.printCharArrayWithEndLine("\n-------------------------------------------- 문서 작성 ---------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArray(" 작성할 문서 이름 입력 (-1 입력시 메뉴로 복귀) : ");
				PFC.printCharArrayWithEndLine(path.c_str());
			}
			delete NULLPermission;
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 문서 내용 입력 (EOF 입력시 문서 입력 종료)");
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
			PFC.printCharArrayWithEndLine("\n-------------------------------------------- 문서 검색 ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 문서 리스트");
			PFC.printCharArrayWithEndLine("");
			FileProcessor FP;
			vector<const char*>* fileList = new vector<const char*>();
			FP.fileList(fileList);
			vector<const char*>* contents = new vector<const char*>();
			for (int i = 0; i < fileList->size(); i++) {
				PFC.printCharArray(" ");
				PFC.printCharArray(fileList->at(i));
				PFC.printCharArray(" - 작성자 : ");
				Permission* fileWriter;
				FP.fileRead(fileList->at(i), contents, &fileWriter);
				PFC.printCharArrayWithEndLine(fileWriter->getPermission());
				contents->clear();
				delete fileWriter;
			}
			delete fileList;
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArray(" 확인할 문서 이름 입력 (-1 입력시 메뉴로 복귀) : ");
			string path;
			getline(cin, path);
			if (path.length() >= 120)
				throw "문서 이름은 120자 이하여야 합니다.";
			if (path == "-1")
				break;
			Permission* NULLPermission = new Permission();
			Permission* filePermission = NULLPermission;
			FP.fileRead(path.c_str(), contents, &filePermission);
			if (filePermission == NULLPermission) {
				delete contents;
				delete NULLPermission;
				throw "해당 문서가 없습니다.";
			}
			delete NULLPermission;
			int findPermission = 0;
			user->searchPermission(filePermission, &findPermission);
			bool hasPermission = false;
			if (*filePermission == Permission(user->getUserName()) || findPermission != -1)
				hasPermission = true;
			delete filePermission;
			if(!hasPermission)
				throw "해당 문서에 대한 접근 권한이 없습니다.";
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" 제목 : ");
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
			PFC.printCharArrayWithEndLine("\n-------------------------------------------- 문서 삭제 ---------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine(" 문서 리스트");
			PFC.printCharArrayWithEndLine("");
			FileProcessor FP;
			vector<const char*>* fileList = new vector<const char*>();
			FP.fileList(fileList);
			vector<const char*>* contents = new vector<const char*>();
			for (int i = 0; i < fileList->size(); i++) {
				PFC.printCharArray(" ");
				PFC.printCharArray(fileList->at(i));
				PFC.printCharArray(" - 작성자 : ");
				Permission* fileWriter;
				FP.fileRead(fileList->at(i), contents, &fileWriter);
				PFC.printCharArrayWithEndLine(fileWriter->getPermission());
				contents->clear();
				delete fileWriter;
			}
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
			PFC.printCharArrayWithEndLine("");
			PFC.printCharArray(" 삭제할 문서 이름 입력 (-1 입력시 메뉴로 복귀) : ");
			string path;
			getline(cin, path);
			if (path.length() >= 120)
				throw "문서 이름은 120자 이하여야 합니다.";
			if (path == "-1")
				break;
			Permission* NULLPermission = new Permission();
			Permission* filePermission = NULLPermission;
			FP.fileRead(path.c_str(), contents, &filePermission);
			if (filePermission == NULLPermission) {
				delete contents;
				delete NULLPermission;
				throw "해당 문서가 없습니다.";
			}
			else if (filePermission != NULLPermission && *filePermission != Permission(user->getUserName())) {
				delete contents;
				delete filePermission;
				delete NULLPermission;
				throw "다른 사용자의 문서는 삭제할 수 없습니다.";
			}
			delete filePermission;
			delete NULLPermission;
			int success = 0;
			FP.fileRemove(path.c_str(), &success);
			if (!success) {
				PFC.clearScrean();
				PFC.printCharArrayWithEndLine("\n-------------------------------------------- 문서 삭제 ---------------------------------------------");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine(" 문서 리스트");
				PFC.printCharArrayWithEndLine("");
				FP.fileList(fileList);
				for (int i = 0; i < fileList->size(); i++) {
					PFC.printCharArray(" ");
					PFC.printCharArray(fileList->at(i));
					PFC.printCharArray(" - 작성자 : ");
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
				PFC.printCharArrayWithEndLine(" 해당 문서 삭제에 성공했습니다.");
				PFC.printCharArrayWithEndLine("");
				PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
				PFC.pause();
				break;
			}
			else {
				delete contents;
				throw "해당 문서 삭제에 실패하였습니다.";
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
		PFC.printCharArrayWithEndLine("\n--------------------------------------- 공동 관리자 추가하기 ---------------------------------------");
		PFC.printCharArrayWithEndLine("");
		for (int i = 0; i < userList->size(); i++)
			if (strcmp(userList->at(i), user->getUserName())) {
				PFC.printCharArray(" ");
				PFC.printCharArrayWithEndLine(userList->at(i));
			}
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArray(" 공동 관리자로 추가할 사용자 : ");
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
						PFC.printCharArrayWithEndLine(" 님은 이미 공동 관리자에 추가되어 있습니다.");
					else {
						PFC.printCharArrayWithEndLine(" 님을 공동 관리자에 추가하였습니다.");
						User(temp).addPermission(new Permission(user->getUserName()));
					}
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.pause();
					delete userList;
					return;
				}
				else
					throw "스스로를 추가할 수 없습니다.";
		throw "존재하지 않는 사용자입니다.";
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
		PFC.printCharArrayWithEndLine("\n--------------------------------------- 공동 관리자 삭제하기 ---------------------------------------");
		PFC.printCharArrayWithEndLine("");
		for (int i = 0; i < userList->size(); i++) {
			PFC.printCharArray(" ");
			PFC.printCharArrayWithEndLine(userList->at(i));
		}
		PFC.printCharArrayWithEndLine("");
		PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
		PFC.printCharArray(" 공동 관리자에서 삭제할 사용자 : ");
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
					PFC.printCharArrayWithEndLine(" 님을 공동 관리자에서 삭제하였습니다.");
					PFC.printCharArrayWithEndLine("");
					PFC.printCharArrayWithEndLine("----------------------------------------------------------------------------------------------------");
					PFC.pause();
				}
				else
					throw "삭제에 실패하였습니다.";
				delete userList;
				return;
			}
		throw "존재하지 않는 사용자입니다.";
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
	PFC.printCharArrayWithEndLine("\n---------------------------------------- 공동 관리자 리스트 ----------------------------------------");
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
	PFC.printCharArrayWithEndLine("\n-------------------------------------- 내 관리 권한 확인하기 ---------------------------------------");
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
