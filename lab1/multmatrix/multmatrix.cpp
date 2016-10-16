// Task13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkSymbol(char *symbol)
{
	if ((symbol != "0") && (atoi(symbol) == 0))
	{
		cout << "Invalid character in the matrix\n";
		return 1;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
		return 1;
	}

	ifstream matrix1File(argv[1]);
	if (!matrix1File.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ifstream matrix2File(argv[2]);
	if (!matrix2File.is_open())
	{
		cout << "Failed to open " << argv[2] << " for reading\n";
		return 1;
	}

	float matrix1[3][3];
	float matrix2[3][3];
	float resultMatrix[3][3];

	char symbol[256];
	//¬вод значений в матрицы из файлов
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (matrix1File.eof() || matrix2File.eof())
			{
				cout << "Wrong input matrix\n";
				return 1;
			}
			matrix1File >> symbol;
			checkSymbol(symbol);
			matrix1[row][col] = atoi(symbol);
			matrix2File >> symbol;
			checkSymbol(symbol);
			matrix2[row][col] = atoi(symbol);
		}
	}

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			resultMatrix[row][col] = 0;
			for (int i = 0; i < 3; i++)
			{
				resultMatrix[row][col] += matrix1[row][i] * matrix2[i][col];
			}
			cout << resultMatrix[row][col] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

