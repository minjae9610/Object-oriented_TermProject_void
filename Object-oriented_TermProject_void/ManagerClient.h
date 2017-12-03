#pragma once

using namespace std;

template <class T>
class ManagerClient {
public:
	void fileRead(const char *, vector<const char *>*, vector<const char *>*);
	void fileWirte(char *, vector<const char *>*, vector<const char *>*);
};