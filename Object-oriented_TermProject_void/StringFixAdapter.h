#pragma once
#include <sstream>
#include <iostream>
#include "StringFixClient.h"

class StringFixAdapter : public StringFixClient{
public:
	void split(const string &, char, vector<string>*) override;
	void removeCharInString(char*, char*) override;
	void intToChar(const int, char**) override;
	void charToInt(int*, const char*) override;
	void constToNot(const char*, char**) override;
};