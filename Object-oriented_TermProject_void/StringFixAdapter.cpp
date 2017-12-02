#include "stdafx.h"
#include "StringFixAdapter.h"

void StringFixAdapter::split(const string & str, char delim, vector<string>* tokens)
{
	size_t start = 0, end = 0;
	while ((end = str.find(delim, start)) != string::npos) {
		tokens->push_back(str.substr(start, end - start));
		start = end + 1;
	}
	tokens->push_back(str.substr(start));
}

void StringFixAdapter::removeCharInString(char * str, char * ch)
{
	char* sptr = nullptr;
	for (int i = 0; ch[i] != NULL; i++) {
		while ((sptr = strchr(str, ch[i])) != NULL)
			memmove(sptr, sptr + 1, strlen(sptr));
	}
	delete sptr;
}

void StringFixAdapter::intToChar(const int value, char** str)
{
	stringstream ss;
	ss << value;
	string temp = ss.str();
	vector<char>* writable = new vector<char>(temp.begin(), temp.end());
	writable->push_back('\0');
	*str = &writable->at(0);
}

void StringFixAdapter::charToInt(int* value, const char* str)
{
	stringstream ss(str);
	ss >> *value;
}
