#include "IntFun.h"
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

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
int** Vector2Matrix(int* vector, int countLines, int countColumns, int vectorSize)
{
	int size( countLines*countColumns);
	int index( 0 );
	int line{ 0 };
	int column{ 0 };
	int** matrix{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		matrix[i] = new int[countColumns];
		memset(matrix[i], 0, sizeof(int) * countColumns);
	}
	for (int line = 0; line < countLines; line++) {
		for (int column = 0; column < countColumns; column++) {
			if (index >= vectorSize) {
				break;
			}
			matrix[line][column] = vector[index];
			index++;
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
		if (matrix[line][i] == 0)
		{
			continue;
		}
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
		if (matrix[i][column] == 0)
		{
			continue;
		}
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
				if (matrix[line][column] == 0)
				{
					continue;
				}
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
		if (matrix[line][column] == 0)
		{
			continue;
		}
		sum += matrix[line][column];
		mult *= matrix[line][column];
		line--;
	}
}


string SearchLineMatrix(int** matrix, int line, int countColumns)
{
	int min{ matrix[0][0] };
	int max{ matrix[0][0] };
	int minC{ 0 };
	int maxC{ 0 };
	for (int i = 0; i < countColumns; i++)
	{
		if (matrix[line][i] == 0)
		{
			continue;
		}
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
	ss << "Минимальное значение в главной диагонали имеет индексы: [" << line << "][" << minC << "].\n";
	ss << "Максимальное значение в главной диагонали имеет индексы: [" << line << "][" << maxC << "]." << endl;
	return ss.str();
}
string SearchColumnMatrix(int** matrix, int column, int countLines)
{
	int min{ matrix[0][0] };
	int max{ matrix[0][0] };
	int minL{ 0 };
	int maxL{ 0 };
	for (int i = 0; i < countLines; i++)
	{
		if (matrix[i][column] == 0)
		{
			continue;
		}
		if (matrix[i][column] < min)
		{
			minL = i;
		}

		if (matrix[i][column] > max)
		{
			maxL = i;
		}
	}
	stringstream ss;
	ss << "Минимальное значение в выбранном столбце имеет индексы: [" << minL << "][" << column << "].\n";
	ss << "Максимальное значение в выбранном столбце имеет индексы: [" << maxL << "][" << column << "]." << endl;
	return ss.str();
}
string SearchMainDiag(int** matrix, int countLines, int countColumns)
{
	int min = matrix[0][0];
	int max = matrix[0][0];
	int minC{ 0 };
	int minL{ 0 };
	int maxL{ 0 };
	int maxC{ 0 };
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (line == column)
			{
				if (matrix[line][column] == 0)
				{
					continue;
				}
				if (matrix[line][column] < min)
				{
					minL = line;
					minC = column;
				}

				if (matrix[line][column > max])
				{
					maxL = line;
					maxC = column;
				}
			}
		}
	}
	stringstream ss;
	ss << "Минимальное значение в выбранном столбце имеет индексы: [" << minL << "][" << minC << "].\n";
	ss << "Максимальное значение в выбранном столбце имеет индексы: [" << maxL << "][" << maxC << "]." << endl;
	return ss.str();
}
string SearchSaidDiag(int** matrix, int countLines, int countColumns)
{
	int min = matrix[0][0];
	int max = matrix[0][0];
	int minC{ 0 };
	int minL{ 0 };
	int maxL{ 0 };
	int maxC{ 0 };
	int line{ countLines - 1 };
	for (int column = 0; column < countColumns; column++)
	{
		if (matrix[line][column] == 0)
		{
			continue;
		}
		if (matrix[line][column] < min)
		{
			minL = line;
			minC = column;
		}

		if (matrix[line][column > max])
		{
			maxL = line;
			maxC = column;
		}
		line--;
	}
	stringstream ss;
	ss << "Минимальное значение в выбранном столбце имеет индексы: [" << minL << "][" << minC << "].\n";
	ss << "Максимальное значение в выбранном столбце имеет индексы: [" << maxL << "][" << maxC << "]." << endl;
	return ss.str();
}

int** DeleteStrMatrix(int** matrix, int& countLines, int countColumns, int deathLine)
{
	int newLine{ 0 };
	int** newArr{ new int* [countLines-1] };
	for (int i = 0; i < countLines-1; i++)
	{
		newArr[i] = new int[countColumns];
	}

	for (int i = 0; i < countLines; i++)
	{
		if (i == deathLine)
		{
			continue;
		}

		for (int j = 0; j < countColumns; j++)
		{

			newArr[newLine][j] = matrix[i][j];
		}
		newLine++;
	}
	countLines--;
	return newArr;
}
int** DeleteColMatrix(int** matrix, int& countLines, int countColumns, int deathColumn)
{
	int newColumn{ 0 };
	int** newArr{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		newArr[i] = new int[countColumns-1];
	}

	for (int i = 0; i < countLines; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			if (j == deathColumn)
			{
				continue;
			}
		

			newArr[i][newColumn] = matrix[i][j];
		}
		newColumn++;
	}
	countLines--;
	return newArr;
}