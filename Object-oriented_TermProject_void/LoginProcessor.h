#pragma once
#include "MapBinaryFileSystemAdapter.h"
#include "Processor.h"

class LoginProcessor {
public:
	void signUp(const char *, const char *, bool *);
	void signIn(char *, const char *, bool *);
	void DeleteAccount(const char *, const char *, bool *);
	void getUserList(vector<const char*>*);
};