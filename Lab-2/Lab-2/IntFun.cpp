#include "IntFun.h"
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int** InputRand(int** matrix, int countLines, int countColumns)
{
	random_device seed;
	mt19937 generator(seed());
	uniform_int_distribution<int> distribution(-100, 100);

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			matrix[line][column] = distribution(generator);
		}
	}
	return matrix;
}


void OutputScreen(int** matrix, int countLines, int countColumns)
{
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			cout << setw(12) <<matrix[line][column];
		}
		cout << endl;
	}
}
void OutVectorScreen(int* vector, int vectorSize) {
	for (int i = 0; i < vectorSize; i++)
		cout << setw(12) << vector[i];
	cout << endl;
}

int *Matrix2Vector(int** matrix, int newCountLines, int newCountCloums) 
{
	int index{ 0 };
	int size{ newCountLines * newCountCloums};
	int* oneDimArr = new int[size];

	
		for (int line = 0; line < newCountLines; line++)
		{
			for (int column = 0; column < newCountCloums; column++)
			{
				oneDimArr[index] = matrix[line][column];
				index++;
			}
		}
	
	return oneDimArr;
}
int** Vector2Matrix(int* vector, int countLines, int countColumns)
{
	int size{ countLines*countColumns};
	int index{ 0 };
	int** matrix{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		matrix[i] = new int[countColumns];
	}

	for (int lines = 0; lines < countLines; lines++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (index >= size)
			{
				matrix[lines][column] = 0;
			}
			else
			{
				matrix[lines][column] = vector[index];
				index++;
			}
		}

	}
	return matrix;
}

void SumMulLineMatrix(int** matrix, int line, int countColumns, int& sum, int&mult)
{
	sum = 0;
	mult = 1;
	for (int i = 0; i < countColumns; i++)
	{
		sum += matrix[line][i];
		mult *= matrix[line][i];
	}
}
void SumMulColumnMatrix(int** matrix, int column, int countLines, int& sum, int& mult)
{
	sum = 0;
	mult = 1;
	for (int i = 0; i < countLines; i++)
	{
		sum += matrix[i][column];
		mult *= matrix[i][column];
	}
}
void SumMulMainDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult)
{
	sum = 0;
	mult = 1;
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (line == column)
			{
				sum += matrix[line][column];
				mult *= matrix[line][column];
			}
		}
	}

}
void SumMulSaidDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult)
{
	sum = 0;
	mult = 1;
	int line{ countLines - 1 };
	
	for (int column = 0; column < countColumns; column++)
	{
		sum += matrix[line][column];
		mult *= matrix[line][column];
		line--;
	}
}


string SearchLineMatrix(int line, int countColumns, int** matrix)
{
	int min{ matrix[0][0] };
	int max{ matrix[0][0] };
	int minC;
	int maxC;
	for (int i = 0; i < countColumns; i++)
	{
		if (matrix[line][i]<min)
		{
			minC = i;
		}
		
		if (matrix[line][i] > max)
		{
			maxC = i;
		}
	}
	stringstream ss;
	ss << "Минимальное значение в выбранной строке имеет индексы: [" << line << "][" << minC << "].\n";
	ss << "Максимальное значение в выбранной строке имеет индексы: [" << line << "][" << maxC << "].";
	return ss.str();
}
string SearchColumnMatrix(int column, int countLines, int** matrix)
{
	int min{ matrix[0][0] };
	int max{ matrix[0][0] };
	int minL;
	int maxL;
	for (int i = 0; i < countLines; i++)
	{
		if (matrix[i][column] < min)
		{
			min = matrix[i][column];
		}

		if (matrix[i][column] > max)
		{
			max = matrix[i][column];
		}
	}
	stringstream ss;
	ss << "Минимальное значение в выбранном столбце имеет индексы: [" << minL << "][" << column << "].\n";
	ss << "Максимальное значение в выбранном столбце имеет индексы: [" << maxL << "][" << column << "].";
	return ss.str();
}
void SearchMainDiag(int** matrix, int countLines, int countColumns, int& min, int& max)
{
	min = matrix[0][0];
	max = matrix[0][0];
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (line == column)
			{
				if (matrix[line][column] < min)
				{
					min = matrix[line][column];
				}

				if (matrix[line][column > max])
				{
					max = matrix[line][column];
				}
			}
		}
	}
}
void SearchSaidDiag(int** matrix, int countLines, int countColumns, int& min, int& max)
{
	min = matrix[0][0];
	max = matrix[0][0];
	int line{ countLines - 1 };
	for (int column = 0; column < countColumns; column++)
	{
		if (matrix[line][column] < min)
		{
			min = matrix[line][column];
		}

		if (matrix[line][column > max])
		{
			max = matrix[line][column];
		}
		line--;
	}
}

string concatenateStrings(const std::string& str1, const std::string& str2)
{
	return str1 + str2;
}



