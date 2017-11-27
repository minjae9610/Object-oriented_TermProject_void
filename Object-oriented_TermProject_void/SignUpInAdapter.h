#pragma once
#include "FileSystemAdapter.h"
#include "BinaryFileSystemAdapter.h"
#include "SignUpInClient.h"

class SignUpInAdapter : public SignUpInClient {
public:
	~SignUpInAdapter();
	SignUpInAdapter();
	void signUp(const char *, const char *, bool *) override;
	void signIn(char *, const char *, char **) override;
	void signOut(char **) override;
	void DeleteAccount(const char *, const char *, bool *) override;
private:
	map<const char*, const char*>* userLoginInfo;
	char* path;
};