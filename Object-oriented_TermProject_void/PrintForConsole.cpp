#include "stdafx.h"
#include "PrintForConsole.h"

void PrintForConsole::printCharArray(const char* arr)
{
	cout << arr;
}

void PrintForConsole::printCharArrayWithEndLine(const char* arr)
{
	cout << arr << endl;
}

void PrintForConsole::endLine()
{
	cout << endl;
}

void PrintForConsole::clearScrean()
{
	system("cls");
}

void PrintForConsole::printError(const char* st)
{
	clearScrean();
	cout << endl << " ERR : " << st << endl;
	pause();
}

void PrintForConsole::pause()
{
	cout << "\n 계속하시려면 아무 키나 누르십시오 . . . ";
	_getch();
}
