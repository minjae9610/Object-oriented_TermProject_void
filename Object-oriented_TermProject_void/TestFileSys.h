#pragma once
#include "Processor.h"
#include <conio.h>

class TestFileSys {
public:
	void test1() {
		PrintForConsole PFC;
		PFC.clearScrean();

		cout << "파일 리스트 보기 테스트 1 (프로젝트 파일 전체 확인)" << endl;
		vector<const char *>* fileList = new vector<const char *>();
		VectorFileSystemAdapter VFSA;
		VFSA.fileListFind("*.*", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		cout << endl;

		cout << "파일 리스트 보기 테스트 2 (헤더 파일 전체 확인)" << endl;
		VFSA.fileListFind("*.h", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		cout << endl;

		cout << "파일 리스트 보기 테스트 3 (cpp 파일 전체 확인)" << endl;
		VFSA.fileListFind("*.cpp", fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		delete fileList;
		cout << endl;

		cout << "회원 가입 테스트 1 (testID1, testPW1)" << endl;
		bool success = false;
		LoginProcessor LP;
		LP.signUp("testID1", "testPW1", &success);
		cout << success << endl;
		cout << endl;

		cout << "회원 가입 테스트 2 (testID2, testPW2)" << endl;
		success = false;
		LP.signUp("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "존재하는 아이디로 회원 가입 테스트 1 (testID1, testPW3)" << endl;
		success = false;
		LP.signUp("testID1", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "사용자 목록 추출 테스트" << endl;
		vector<const char*>* userList = new vector<const char*>();
		LP.getUserList(userList);
		for (int i = 0; i < userList->size(); i++)
			cout << userList->at(i) << endl;
		delete userList;
		cout << endl;

		cout << "로그인 테스트 1 (없는 아이디로)" << endl;
		success = false;
		LP.signIn("testID3", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "로그인 테스트 2 (잘못된 비밀번호로)" << endl;
		success = false;
		LP.signIn("testID1", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "로그인 테스트 3 (존재하는 아이디의 알맞은 비밀번호로)" << endl;
		success = false;
		LP.signIn("testID1", "testPW1", &success);
		cout << success << endl;
		cout << endl;

		cout << "회원 탈퇴 테스트 (testID2 틀린 비밀번호)" << endl;
		success = false;
		LP.DeleteAccount("testID2", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "회원 탈퇴 테스트 (testID2 맞는 비밀번호)" << endl;
		success = false;
		LP.DeleteAccount("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "회원 탈퇴 테스트 (없는 아이디)" << endl;
		success = false;
		LP.DeleteAccount("testID3", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "파일 매니저 파일 쓰기 테스트" << endl;
		int isFileRemoved = 0;
		FileProcessor FP;
		vector<const char*>* tempContents = new vector<const char*>();
		tempContents->push_back("장실좀 - 황동준");
		tempContents->push_back("배고파 - 마니마니");
		tempContents->push_back("배그합시다 여러분 - 김민재");
		Permission* tempPermissions = new Permission("김민재");
		FP.fileWirte("testFPFile", tempContents, tempPermissions);
		tempContents->clear();
		delete tempPermissions;
		cout << endl;

		cout << "파일 매니저 파일 읽기 테스트" << endl;
		FP.fileRead("testFPFile", tempContents, &tempPermissions);
		cout << tempPermissions->getPermission() << endl;
		for (int i = 0; i < tempContents->size(); i++)
			cout << tempContents->at(i) << endl;
		tempContents->clear();
		delete tempContents;
		delete tempPermissions;
		cout << endl;

		cout << "파일 매니저 파일 리스트 보기 테스트" << endl;
		fileList = new vector<const char *>();
		FP.fileList(fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		delete fileList;
		cout << endl;

		cout << "파일 매니저 파일 삭제 테스트 1 (없는 파일 삭제)" << endl;
		isFileRemoved = 0;
		FP.fileRemove("dasijmi", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "파일 매니저 파일 삭제 테스트 2 (testFPFile 파일 삭제)" << endl;
		isFileRemoved = 0;
		FP.fileRemove("testFPFile", &isFileRemoved);
		cout << isFileRemoved << endl;
	}
};