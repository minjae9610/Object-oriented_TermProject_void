#pragma once
#include <vector>

using namespace std;

class StringFixClient {
public:
	virtual void split(const string &, char, vector<string>*) = 0;
	virtual void removeCharInString(char* , char*) = 0;
	virtual void intToChar(const int, char**) = 0;
	virtual void charToInt(int*, const char*) = 0;
};