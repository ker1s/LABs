#include "IntFun.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "rus");
	
	int countLines;
	int countColumns;
	int vectorSeize;
	int line;
	int column;
	int sum;
	int mult;
	cout << "Колличество срок: "; cin >> countLines;
	cout << endl <<"Колличество столбцов: "; cin >> countColumns;
	int* vector = new int[countLines * countColumns];

	int** matrix{ new int* [countLines] };
	for (int i = 0; i < countLines; i++)
	{
		matrix[i] = new int[countColumns];
	}

	//заполнение и вывод
	cout << "\n\n---------------------заполнение и вывод---------------------\n\n";
	matrix = InputRand(matrix, countLines, countColumns);
	OutputScreen(matrix, countLines, countColumns);
	cout << endl;


	//Двумерный массив в одномерный
	cout << "\n\n---------------------Двумерный массив в одномерный---------------------\n\n";
	vector = Matrix2Vector(matrix, countLines, countColumns);
	vectorSeize = countLines * countColumns;
	OutVectorScreen(vector, vectorSeize);
	cout << endl;

	//Одномерный массив в двумерный
	cout << "\n\n---------------------Одномерный массив в двумерный---------------------\n\n";
	cout << "Новое колличество срок: "; cin >> countLines;
	cout << endl << "Новое колличество столбцов: "; cin >> countColumns;
	matrix = Vector2Matrix(vector, countLines, countColumns);
	OutputScreen(matrix,countLines, countColumns);


	//Вычисление суммы, произведения
	cout << "\n\n---------------------Вычисление суммы, произведения---------------------\n\n";
	cout << endl << "Строка: "; cin >> line;
	cout << endl << "Столбец: "; cin >> column;
	SumMulLineMatrix(matrix,line,countColumns,sum,mult);
	cout << endl << "Сумма по заданной строке " << sum << endl << "Произведение по заданной строке " << mult << endl;
	
	SumMulColumnMatrix(matrix,column,countLines,sum,mult);
	cout << endl << "Сумма по заданному столбцу " << sum << endl << "Произведение по заданному столбцу " << mult << endl;
	
	SumMulMainDiag(matrix,countLines,countColumns,sum,mult);
	cout << endl << "Сумма по главной диагонали " << sum << endl << "Произведение по главной диагонали " << mult << endl;
	
	SumMulSaidDiag(matrix, countLines, countColumns, sum, mult);
	cout << endl << "Сумма по побочной диагонали " << sum << endl << "Произведение по побочной диагонали " << mult << endl;

	//Поиск минимального и максимального

	cout << endl << "Строка: "; cin >> line;
	cout << endl << "Столбец: "; cin >> column;

	cout << SearchLineMatrix(matrix, line, countColumns) << endl;
	cout << SearchColumnMatrix(matrix, column, countLines) << endl;
	cout << SearchMainDiag(matrix,countLines ,countColumns) << endl;
	cout << SearchSaidDiag(matrix, countLines, countColumns) << endl;
	
}
