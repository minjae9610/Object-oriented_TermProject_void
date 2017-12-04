#pragma once
#include "Manager.h"

class TestFileSys {
public:
	void test1() {
		cout << "파일 쓰기 테스트 1 (test.txt 파일을 test1 폴더 안에 쓰기)" << endl;
		vector<const char *>* contents = new vector<const char*>();
		contents->push_back("테스트1");
		contents->push_back("테스트2");
		VectorFileSystemAdapter VFSA;
		VFSA.fileOut("test1\\test.txt", contents);
		contents->clear();
		cout << endl;

		cout << "파일 쓰기 테스트 2 (test.txt 파일을 test1 폴더 안의 test2 폴더 안에 쓰기)" << endl;
		contents->push_back("테스트1");
		contents->push_back("테스트2");
		contents->push_back("테스트3");
		VFSA.fileOut("test1\\test2\\test.txt", contents);
		contents->clear();
		cout << endl;

		cout << "파일 리스트 보기 테스트 1 (프로젝트 파일 전체 확인)" << endl;
		vector<const char *>* fileList = new vector<const char *>();
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

		cout << "파일 읽기 테스트 1 (test1 폴더 안의 test.txt 파일 읽기)" << endl;
		VFSA.fileIn("test1\\test.txt", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;

		cout << "파일 읽기 테스트 2 (test1 폴더 안의 test2 폴더 안의 test.txt 파일 읽기)" << endl;
		VFSA.fileIn("test1\\test2\\test.txt", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;

		cout << "파일 읽기 테스트 3 (존재하지 않는 파일 읽기)" << endl;
		VFSA.fileIn("asadasd", contents);
		for (int i = 0; i < contents->size(); i++)
			cout << contents->at(i) << endl;
		contents->clear();
		cout << endl;
		delete contents;

		cout << "파일 삭제 테스트 1 (test1 폴더 안의 test2 폴더 안의 test.txt 삭제)" << endl;
		int isFileRemoved = 0;
		VFSA.fileRemove("test1\\test2\\test.txt", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "파일 삭제 테스트 2 (test1 폴더 안의 test.txt 삭제)" << endl;
		isFileRemoved = 0;
		VFSA.fileRemove("test1\\test.txt", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "파일 삭제 테스트 3 (없는 파일 삭제)" << endl;
		isFileRemoved = 0;
		VFSA.fileRemove("hguyguy", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "회원 가입 테스트 1 (testID1, testPW1)" << endl;
		bool success = false;
		LoginManager LM;
		LM.signUp("testID1", "testPW1", &success);
		cout << success << endl;
		cout << endl;

		cout << "회원 가입 테스트 2 (testID2, testPW2)" << endl;
		success = false;
		LM.signUp("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "존재하는 아이디로 회원 가입 테스트 1 (testID1, testPW3)" << endl;
		success = false;
		LM.signUp("testID1", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "로그인 테스트 1 (없는 아이디로)" << endl;
		char* ID = "";
		LM.signIn("testID3", "testPW3", &ID);
		cout << ID << endl;
		cout << endl;

		cout << "로그인 테스트 2 (잘못된 비밀번호로)" << endl;
		LM.signIn("testID1", "testPW2", &ID);
		cout << ID << endl;
		cout << endl;

		cout << "로그인 테스트 3 (존재하는 아이디의 알맞은 비밀번호로)" << endl;
		LM.signIn("testID1", "testPW1", &ID);
		cout << ID << endl;
		cout << endl;

		cout << "로그아웃 테스트" << endl;
		LM.signOut(&ID);
		cout << ID << endl;
		cout << endl;

		cout << "회원 탈퇴 테스트 (testID2 틀린 비밀번호)" << endl;
		success = false;
		LM.DeleteAccount("testID2", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "회원 탈퇴 테스트 (testID2 맞는 비밀번호)" << endl;
		success = false;
		LM.DeleteAccount("testID2", "testPW2", &success);
		cout << success << endl;
		cout << endl;

		cout << "회원 탈퇴 테스트 (없는 아이디)" << endl;
		success = false;
		LM.DeleteAccount("testID3", "testPW3", &success);
		cout << success << endl;
		cout << endl;

		cout << "파일 매니저 파일 쓰기 테스트" << endl;
		isFileRemoved = 0;
		FileManager FM;
		vector<const char*>* tempContents = new vector<const char*>();
		tempContents->push_back("장실좀 - 황동준");
		tempContents->push_back("배고파 - 마니마니");
		tempContents->push_back("배그합시다 여러분 - 김민재");
		vector<const char*>* tempPermissions = new vector<const char*>();
		tempPermissions->push_back("황동준");
		tempPermissions->push_back("김민재");
		tempPermissions->push_back("이병만");
		tempPermissions->push_back("허효선");
		FM.fileWirte("testFMFile", tempContents, tempPermissions);
		tempContents->clear();
		tempPermissions->clear();
		cout << endl;

		cout << "파일 매니저 파일 읽기 테스트" << endl;
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

		cout << "파일 매니저 파일 리스트 보기 테스트" << endl;
		fileList = new vector<const char *>();
		FM.fileList(fileList);
		for (int i = 0; i < fileList->size(); i++)
			cout << fileList->at(i) << endl;
		fileList->clear();
		delete fileList;
		cout << endl;

		cout << "파일 매니저 파일 삭제 테스트 1 (없는 파일 삭제)" << endl;
		isFileRemoved = 0;
		FM.fileRemove("dasijmi", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;

		cout << "파일 매니저 파일 삭제 테스트 2 (testFMFile 파일 삭제)" << endl;
		isFileRemoved = 0;
		FM.fileRemove("testFMFile", &isFileRemoved);
		cout << isFileRemoved << endl;
		cout << endl;
	}
};