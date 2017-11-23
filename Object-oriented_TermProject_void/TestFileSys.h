#pragma once
#include "SignUpInAdapter.h"

class TestFileSys {
public:
	void test1() {
		cout << "파일 쓰기 테스트 1 (test.txt 파일을 test1 폴더 안에 쓰기)" << endl;
		vector<const char *>* contents = new vector<const char*>();
		contents->push_back("테스트1");
		contents->push_back("테스트2");
		FileSystemClient* fileSys = new FileSystemAdapter();
		fileSys->fileOut("test1\\test.txt", contents);
		contents->clear();
		delete fileSys;
		cout << endl;

		cout << "파일 쓰기 테스트 2 (test.txt 파일을 test1 폴더 안의 test2 폴더 안에 쓰기)" << endl;
		contents->push_back("테스트1");
		contents->push_back("테스트2");
		contents->push_back("테스트3");
		fileSys = new FileSystemAdapter();
		fileSys->fileOut("test1\\test2\\test.txt", contents);
		contents->clear();
		delete fileSys;
		cout << endl;

		cout << "파일 읽기 테스트 1 (test1 폴더 안의 test.txt 파일 읽기)" << endl;
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("test1\\test.txt", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;
		contents->clear();

		cout << "파일 읽기 테스트 2 (test1 폴더 안의 test2 폴더 안의 test.txt 파일 읽기)" << endl;
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("test1\\test2\\test.txt", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;
		contents->clear();

		cout << "파일 읽기 테스트 3 (존재하지 않는 파일 읽기)" << endl;
		fileSys = new FileSystemAdapter();
		fileSys->fileIn("asadasd", contents);
		delete fileSys;
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		cout << endl;
		contents->clear();
		delete contents;

		cout << "파일 삭제 테스트 1 (test1 폴더 안의 test2 폴더 안의 test.txt 삭제)" << endl;
		int isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("test1\\test2\\test.txt", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "파일 삭제 테스트 2 (test1 폴더 안의 test.txt 삭제)" << endl;
		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("test1\\test.txt", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "파일 삭제 테스트 3 (없는 파일 삭제)" << endl;
		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("hguyguy", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "회원 가입 테스트 1 (testID1, testPW1)" << endl;
		SignUpInClient* sign = new SignUpInAdapter();
		bool success = false;
		sign->signUp("testID1", "testPW1", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "회원 가입 테스트 2 (testID2, testPW2)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->signUp("testID2", "testPW2", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "존재하는 아이디로 회원 가입 테스트 1 (testID1, testPW3)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->signUp("testID1", "testPW3", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "로그인 테스트 1 (없는 아이디로)" << endl;
		sign = new SignUpInAdapter();
		char* ID = "";
		sign->signIn("testID3", "testPW3", &ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "로그인 테스트 2 (잘못된 비밀번호로)" << endl;
		sign = new SignUpInAdapter();
		sign->signIn("testID1", "testPW2", &ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "로그인 테스트 3 (존재하는 아이디의 알맞은 비밀번호로)" << endl;
		sign = new SignUpInAdapter();
		sign->signIn("testID1", "testPW1", &ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "로그아웃 테스트" << endl;
		sign = new SignUpInAdapter();
		sign->signOut(&ID);
		cout << ID << endl;
		delete sign;
		cout << endl;

		cout << "회원 탈퇴 테스트 (testID2 틀린 비밀번호)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->DeleteAccount("testID2", "testPW3", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "회원 탈퇴 테스트 (testID2 맞는 비밀번호)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->DeleteAccount("testID2", "testPW2", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "회원 탈퇴 테스트 (없는 아이디)" << endl;
		sign = new SignUpInAdapter();
		success = false;
		sign->DeleteAccount("testID3", "testPW3", &success);
		cout << success << endl;
		delete sign;
		cout << endl;

		cout << "유져 데이터 베이스 삭제" << endl;
		isFileRemoved = 0;
		fileSys = new FileSystemAdapter();
		fileSys->fileRemove("SystemData\\UserLoginInfo.LoginInfoDB", &isFileRemoved);
		delete fileSys;
		cout << isFileRemoved << endl;
		cout << endl;
	}
};