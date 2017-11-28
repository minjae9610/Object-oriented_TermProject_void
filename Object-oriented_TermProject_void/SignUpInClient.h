#pragma once

class SignUpInClient {
public:
	virtual void signUp(const char *, const char *, bool *) = 0;
	virtual void signIn(char *, const char *, char **) = 0;
	virtual void signOut(char **) = 0;
	virtual void DeleteAccount(const char *, const char *, bool *) = 0;
};