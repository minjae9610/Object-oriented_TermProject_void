#pragma once
#include <iostream>
#include <vector>
//#include "StringFixClient.h"

using namespace std;

class StringFixAdapter {//: public StringFixClient{
public:
	void split(const string &, char, vector<string>*);// override;
	void removeCharInString(char*, char*);// override;
};