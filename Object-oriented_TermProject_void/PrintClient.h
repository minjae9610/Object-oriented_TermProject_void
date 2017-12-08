#pragma once

using namespace std;

class PrintClient {
public:
	virtual void printCharArray(const char *) = 0;
	virtual void printCharArrayWithEndLine(const char *) = 0;
	virtual void endLine() = 0;
	virtual void clearScrean() = 0;
	virtual void printError(const char *) = 0;
	virtual void pause() = 0;
};