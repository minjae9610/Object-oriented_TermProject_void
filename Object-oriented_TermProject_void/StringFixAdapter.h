#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringFixAdapter {
public:
	void split(const string &str, char delim, vector<string>* tokens);
	void removeCharInString(char* str, char* ch);
};