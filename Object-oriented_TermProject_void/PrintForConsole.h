#pragma once
#include "PrintClient.h"
#include <iostream>
#include <conio.h>

class PrintForConsole : public PrintClient {
public:
	void printCharArray(const char *) override;
	void printCharArrayWithEndLine(const char *) override;
	void endLine() override;
	void clearScrean() override;
	void printError(const char *) override;
	void pause() override;
};