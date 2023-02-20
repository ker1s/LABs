#include "IntFun.h"
#include <iostream>
#include <random>
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

