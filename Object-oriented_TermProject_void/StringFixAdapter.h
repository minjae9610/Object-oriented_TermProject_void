#pragma once
#include <iostream>
#include "StringFixClient.h"

class StringFixAdapter : public StringFixClient{
public:
	void split(const string &, char, vector<string>*) override;
	void removeCharInString(char*, char*) override;
};