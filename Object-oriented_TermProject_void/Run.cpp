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
		PFC.printCharArrayWithEndLine(" 1 : 문서 보기");
		PFC.printCharArrayWithEndLine(" 2 : 문서 쓰기");
		PFC.printCharArrayWithEndLine(" 3 : 문서 삭제하기");
		PFC.printCharArrayWithEndLine(" 4 : 내 문서를 볼 수 있는 사용자 관리하기");
		PFC.printCharArrayWithEndLine(" 5 : 내 권한 및 그룹 정보 보기");
		PFC.printCharArrayWithEndLine(" 6 : 로그아웃");
		PFC.printCharArrayWithEndLine(" 7 : 회원탈퇴");
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
				if (!strcmp(userList->at(i), ID.c_str()))
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
		}
	}
}

void Run::testCase()
{
	TestFileSys TFS;
	TFS.test1();
}
