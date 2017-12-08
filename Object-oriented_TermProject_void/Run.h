#pragma once
#include "PrintForConsole.h"
#include "Processor.h"
#include "User.h"
#include "TestFileSys.h"

class Run {
private:
	PrintForConsole PFC;
	User* user;
public:
	void mainMenu();
private:
	bool unLoginMenu();
	bool LoginMenu();
	void signUp();
	void signIn();
	void testCase();
};