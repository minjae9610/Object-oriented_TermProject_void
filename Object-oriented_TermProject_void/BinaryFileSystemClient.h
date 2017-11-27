#pragma once

using namespace std;

template <class T>
class BinaryFileSystemClient {
public:
	virtual void fileIn(const char *, T) = 0;
	virtual void fileOut(char *, T) = 0;
private:
	virtual bool fileFind(const char *) = 0;
};