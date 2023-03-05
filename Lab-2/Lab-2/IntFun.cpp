#include "IntFun.h"
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>
#include <windows.h>

using namespace std;

int** InputKeyboard(int** matrix, int countLines, int countColumns)
{
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			cout << "[" << line << "] " << "[" << column << "] ";
			cin >> matrix[line][column];
			cout << endl;
		}
	}
	return matrix;

}
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
int* InputRandVector(int* vector, int vectorLength)
{
	random_device seed;
	mt19937 generator(seed());
	uniform_int_distribution<int> distribution(-100, 100);

	for (int i = 0; i < vectorLength; i++)
	{
		vector[i] = distribution(generator);
	}
	return vector;
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
	stringstream message;
	message << "Индекс минимального : [" << line << "][" << minC << "].\n";
	message << "Индекс максимального: [" << line << "][" << maxC << "]." << endl;
	return message.str();
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
	stringstream message;
	message << "Индекс минимального :[" << minL << "][" << column << "].\n";
	message << "Индекс максимального : [" << maxL << "][" << column << "]." << endl;
	return message.str();
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
	stringstream message;
	message << "Индекс минимального :[" << minL << "][" << minC << "].\n";
	message << "Индекс максимального : [" << maxL << "][" << maxC << "]." << endl;
	return message.str();
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
	stringstream message;
	message << "Индекс минимального :[" << minL << "][" << minC << "].\n";
	message << "Индекс максимального : [" << maxL << "][" << maxC << "]." << endl;
	return message.str();
}


bool MoreN(int value, int factor)
{
	return value >= factor;
}
bool LessN(int value, int factor)
{
	return value < factor;
}
bool MultN(int value, int factor)
{
	return (value % factor) == 0;
}
bool EquallyN(int value, int factor) {
	return value == factor;
}
string	FindCountQuan(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if ((*pred)(matrix[line][column], N))
			{
				quan++;
				message << "[" << line << "] [" << column << "]\n";
			}
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}

string FindCountQuanLine(int** matrix, int countLines, int countColumns, int line ,bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int column = 0; column < countColumns; column++)
	{
		if ((*pred)(matrix[line][column], N))
		{
			quan++;
			message << "[" << line << "] [" << column << "]\n";
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanColumn(int** matrix, int countLines, int countColumns, int column, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countColumns; line++)
	{
		if ((*pred)(matrix[line][column], N))
		{
			quan++;
			message << "[" << line << "] [" << column << "]\n";
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanMainDiag(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countColumns; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			if (line == column)
			{
				if ((*pred)(matrix[line][column], N))
				{
					quan++;
					message << "[" << line << "] [" << column << "]\n";
				}
			}
		}
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanSaidDiag(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	int line{ countLines - 1 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int column = 0; column < countColumns; column++)
	{
		if ((*pred)(matrix[line][column], N))
		{
			quan++;
			message << "[" << line << "] [" << column << "]\n";
		}
		line--;
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanUp3(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	int saidCoeff{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countColumns; line++)
	{
		for (int column = saidCoeff; column < countColumns; column++)
		{
			if ((*pred)(matrix[line][column], N))
			{
				quan++;
				message << "[" << line << "] [" << column << "]\n";
			}
		}
		saidCoeff++;
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
}
string FindCountQuanUnder3(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N)
{
	int quan{ 0 };
	int saidCoeff{ 0 };
	stringstream message;
	message << " Имеют индексы: \n";

	for (int line = 0; line < countColumns; line++)
	{
		for (int column = 0; column < saidCoeff; column++)
		{
			if ((*pred)(matrix[line][column], N))
			{
				quan++;
				message << "[" << line << "] [" << column << "]\n";
			}
		}
		saidCoeff++;
	}
	message << "их общее колличество равно: " << quan;
	return message.str();
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
int** DeleteColMatrix(int** matrix, int countLines, int& countColumns, int deathColumn)
{
	int newColumn{ 0 };
	int** newArr{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		newArr[i] = new int[countColumns - 1];
	}
	for (int i = 0; i < countLines; i++)
	{
		newColumn = 0;
	for (int j = 0; j < countColumns; j++)
		{
			if (j != deathColumn)
			{
				newArr[i][newColumn] = matrix[i][j];
				newColumn++;
			}
		}
	}


	for (int i = 0; i < countLines; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	countColumns--;
	return newArr;
}

void PasteSortVector(int* vector, int vectorLenght)
{
	for (int i = 1; i < vectorLenght; i++) 
	{
		int j{ i - 1 };
		while (j >= 0 && vector[j] > vector[j + 1]) 
		{
			swap(vector[j], vector[j + 1]);
			j--;
		}
	}
}
                    
void PasteSortMatrix(int** matrix, int countLines, int countColumns, int& sortLine, int& sortColumn)
{
	if (sortLine > -1)
	{
		int* vector = new int[countColumns];
	
		for (int columnI = 0; columnI < countColumns; columnI++)
		{
			vector[columnI] = matrix[sortLine][columnI];
		}
		PasteSortVector(vector, countColumns);
		for (int column = 0; column < countColumns; column++)
		{
			matrix[sortLine][column] = vector[column];
		}
		delete[] vector;
	}
	if (sortColumn > -1)
	{
		int* vector = new int[countLines];

		for (int lineI = 0; lineI < countLines; lineI++)
		{
			vector[lineI] = matrix[lineI][sortColumn];
		}
		PasteSortVector(vector, countColumns);
		for (int line = 0; line < countLines; line++)
		{
			matrix[line][sortColumn] = vector[line];
		}
		delete[] vector;
	}
	if (sortLine == INT_MIN && sortColumn == INT_MIN)
	{
		int* vector = new int[countLines * countColumns];
		int vectorIndex{ 0 };
		vector = Matrix2Vector(matrix, countLines, countColumns);
		PasteSortVector(vector, countLines * countColumns);
		for (int line = 0; line < countLines; line++)
		{
			for (int column = 0; column < countColumns; column++)
			{
				matrix[line][column] = vector[vectorIndex];
				vectorIndex++;
			}
		}
		delete[] vector;
	}	
	sortLine = INT_MIN;
	sortColumn = INT_MIN;
}

int** multMtrix2Vector(int** matrix, int* vector, int countLines, int& countColumns)
{
	int** multVector{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		multVector[i] = new int[1];
	}

	for (int i = 0; i < countLines; i++)
	{
		multVector[i][0] = 0;
	}

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			multVector[line][0] += matrix[line][column] * vector[column];
		}
	}
	countColumns = 1;
	return multVector;
}

int** multMatrix2Matrix(int** matrix1, int** matrix2, int& countLines1, int& countColumns1,int countColumns1AndLines2, int countColumns2)
{
	int** multMatrix{ new int* [countLines1] };
	for (int i = 0; i < countLines1; i++)
	{
		multMatrix[i] = new int[countColumns2];
		for (int j = 0; j < countColumns2; j++)
		{
			multMatrix[i][j] = 0;
			for (int k = 0; k < countColumns1AndLines2; k++)
			{
				multMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	countColumns1 = countColumns2;
	return multMatrix;
}

void matrixTransformation(int** matrix, int countColumns, int transformationLine, int faactor, bool condition)
{
	if (condition == false )
	{
		for (int column = 0; column < countColumns; column++)
		{
			matrix[transformationLine][column] *= faactor;
		}
	}
	else
	{
		for (int column = 0; column < countColumns; column++)
		{
			matrix[transformationLine][column] /= faactor;
		}
	}
}

void Transportation(int** matrix, int countLines, int countColumns)
{
	int** tempMatrix{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		tempMatrix[i] = new int[countColumns];
	}
	
	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			tempMatrix[column][line] = matrix[line][column];
		}
	}

	for (int line = 0; line < countLines; line++)
	{
		for (int column = 0; column < countColumns; column++)
		{
			int value = tempMatrix[line][column];
			matrix[line][column] = value;
		}
	}
	for (int i = 0; i < countLines; i++) {
		delete[] tempMatrix[i];
	}
	delete[] tempMatrix;

}

int Bonus1(int** matrix, int countLines, int countColumns)
{
	int tempCount;
	int count{ 0 };

	for (int i = 0; i < countColumns ; i++)
	{
		for (int j = 0; j < countLines; j++)
		{
			if (matrix[j][i] == 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}

int Bonus2(int** matrix, int countLines, int countColumns)
{
	int biggerStrik{ 0 };
	int currentStrik{ 1 };
	int maxStrikLine{ -1 };
	for (int i = 0; i < countLines; i++)
	{
		for (int j = 1; j < countColumns; j++)
		{
			if (matrix[i][j - 1] == matrix[i][j])
			{
				currentStrik++;
			}
			if (currentStrik > biggerStrik)
			{
				biggerStrik = currentStrik;
				maxStrikLine = i;
			}
			currentStrik = 1;
		}
	}
	return maxStrikLine;
}