// Task13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MATRIX_ROW = 3;
const int MATRIX_COLUMN = 3;

typedef float Matrix[MATRIX_ROW][MATRIX_COLUMN];

bool ReadMatrixFromFile(ifstream &inputFile, Matrix &matrix)
{
	char symbol[256];
	for (int row = 0; row < MATRIX_ROW; row++)
	{
		for (int col = 0; col < MATRIX_COLUMN; col++)
		{
			if (inputFile.eof())
			{
				cout << "Wrong input matrix\n";
				return false;
			}
			inputFile >> symbol;
			if ((symbol != "0") && (atoi(symbol) == 0))
			{
				cout << "Invalid character in the matrix\n";
				return false;
			}
			matrix[row][col] = atoi(symbol);
		}
	}
	return true;
}

void MatrixMultiplication(Matrix &matrix1, Matrix &matrix2, Matrix &resultMatrix)
{
	for (int row = 0; row < MATRIX_ROW; row++)
	{
		for (int col = 0; col < MATRIX_COLUMN; col++)
		{
			resultMatrix[row][col] = 0;
			for (int i = 0; i < 3; i++)
			{
				resultMatrix[row][col] += matrix1[row][i] * matrix2[i][col];
			}
		}
	}
}

void PrintMatrix(Matrix &matrix)
{
	for (int row = 0; row < MATRIX_ROW; row++)
	{
		for (int col = 0; col < MATRIX_COLUMN; col++)
		{
			printf("%.3f ", matrix[row][col]);
		}
		cout << '\n';
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

	Matrix matrix1;
	Matrix matrix2;
	Matrix resultMatrix;

	char symbol[256];
	//¬вод значений в матрицы из файлов
	if (!ReadMatrixFromFile(matrix1File, matrix1) || !ReadMatrixFromFile(matrix2File, matrix2))
	{
		return 1;
	}

	MatrixMultiplication(matrix1, matrix2, resultMatrix);

	PrintMatrix(resultMatrix);

	return 0;
}

