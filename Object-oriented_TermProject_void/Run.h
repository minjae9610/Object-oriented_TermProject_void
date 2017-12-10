#pragma once
#include "PrintForConsole.h"
#include "Processor.h"
#include "User.h"
#include "TestFileSys.h"

class Run {
private:
	PrintForConsole PFC;
	User* NULLuser = new User();;
	User* user = NULLuser;
public:
	void mainMenu();
private:
	bool unLoginMenu();
	bool LoginMenu();
	void userInfoMenu();
	void signUp();
	void signIn();
	void signOut();
	bool DeleteAccount();
	void write();
	void read();
	void remove();
};