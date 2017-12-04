#pragma once
#include "MapBinaryFileSystemAdapter.h"
#include "Manager.h"

class LoginManager {
public:
	void signUp(const char *, const char *, bool *);
	void signIn(char *, const char *, char **);
	void signOut(char **);
	void DeleteAccount(const char *, const char *, bool *);
};