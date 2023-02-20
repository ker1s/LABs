#include <iostream>
#include "IntFun.h"

using namespace std;

int main()
{
	setlocale(0, "rus");
	
	int countLines;
	int countColumns;
	int vectorSeize;
	int* vector = new int;
	cout << "Колличество срок: "; cin >> countLines;
	cout << endl <<"Колличество столбцов: "; cin >> countColumns;

	int** matrix{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		matrix[i] = new int[countColumns];
	}

	matrix = InputRand(matrix, countLines, countColumns);
	OutputScreen(matrix, countLines, countColumns);
	cout << endl;

	vector = Matrix2Vector(matrix, countLines, countColumns);
	vectorSeize = countLines * countColumns;
	OutVectorScreen(vector, vectorSeize);
	cout << endl;

	cout << "Новое колличество срок: "; cin >> countLines;
	cout << endl << "Новое колличество столбцов: "; cin >> countColumns;
	matrix = Vector2Matrix(vector, countLines, countColumns);
	OutputScreen(matrix,countLines, countColumns);

}
