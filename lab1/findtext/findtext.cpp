#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	string line;
	int lineNumberFoundString = 0;
	int lineNumber = 0;

	while (getline(inputFile, line))
	{
		lineNumber++;
		if (line.find(argv[2]) != string::npos)
		{
			lineNumberFoundString = lineNumber;
			cout << lineNumberFoundString << endl;
		}
	}

	if (lineNumberFoundString == 0)
	{
		cout << "Text not found\n";
		return 1;
	}

	inputFile.close();

	return 0;
}

