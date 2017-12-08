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
		PFC.printCharArrayWithEndLine(" 1 : 로그인");
		PFC.printCharArrayWithEndLine(" 2 : 회원가입");
		PFC.printCharArrayWithEndLine(" 3 : 테스트 케이스 실행");
		PFC.printCharArrayWithEndLine(" 0 : 종료");
		PFC.printCharArrayWithEndLine("------------------------");
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
		case 3:
			TestFileSys TFS;
			TFS.test1();
			PFC.pause();
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
		PFC.printCharArrayWithEndLine("\n--------- VOID ----------");
		PFC.printCharArray(" 현재 로그인 한 사용자 : ");
		PFC.printCharArrayWithEndLine(user->getUserName());
		PFC.printCharArrayWithEndLine("------------------------");
		PFC.printCharArrayWithEndLine(" 1 : 문서 보기");
		PFC.printCharArrayWithEndLine(" 2 : 문서 작성");
		PFC.printCharArrayWithEndLine(" 3 : 문서 삭제하기");
		PFC.printCharArrayWithEndLine(" 4 : 내 정보 설정");
		PFC.printCharArrayWithEndLine(" 0 : 종료");
		PFC.printCharArrayWithEndLine("------------------------");
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
		case 0:
			delete user;
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

void Run::signUp()
{
	LoginProcessor LP;
	vector<const char*>* userList = new vector<const char*>();
	LP.getUserList(userList);
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------- 회원가입 ----------");
			PFC.printCharArray(" ID 입력 : ");
			string ID;
			getline(cin, ID);
			for (int i = 0; i < userList->size(); i++)
				if (ID == userList->at(i))
					throw "이미 존재하는 ID 입니다.";
			PFC.printCharArray(" PassWord 입력 : ");
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
				PFC.printCharArrayWithEndLine(" 회원가입에 성공했습니다.");
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
			PFC.printCharArrayWithEndLine("\n--------- 로그인 ----------");
			PFC.printCharArray(" ID 입력 : ");
			string ID;
			getline(cin, ID);
			PFC.printCharArray(" PassWord 입력 : ");
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
				PFC.printCharArrayWithEndLine(" 로그인에 성공했습니다.");
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

void Run::write()
{
	while (true) {
		try {
			PFC.clearScrean();
			PFC.printCharArrayWithEndLine("\n--------- 문서 작성 ----------");
			PFC.printCharArray(" 작성할 문서 이름 입력 (확장자 제외) (-1 입력시 메뉴로 복귀) : ");
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
			if (filePermission != NULLPermission && *filePermission != Permission(user->getUserName())) {
				delete contents;
				delete filePermission;
				delete NULLPermission;
				throw "다른 사용자가 해당 이름의 파일을 이미 만들었습니다.";
			}
			delete NULLPermission;
			contents->clear();
			PFC.printCharArrayWithEndLine("------------------------");
			PFC.printCharArrayWithEndLine(" 문서 내용 입력 (EOF 입력시 문서 입력 종료)");
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
			PFC.printCharArrayWithEndLine("\n--------- 문서 작성 ----------");
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
			PFC.printCharArrayWithEndLine("------------------------");
			PFC.printCharArray(" 확인할 문서 이름 입력 (확장자 제외) (-1 입력시 메뉴로 복귀) : ");
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
				throw "해당 파일이 없습니다.";
			}
			delete NULLPermission;
			if (*filePermission != Permission(user->getUserName())) {
				throw "해당 파일에 대한 접근 권한이 없습니다.";
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
