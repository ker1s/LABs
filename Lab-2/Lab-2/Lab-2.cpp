#include "IntFun.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	//	setlocale(0, "rus");

	int countLines;
	int countColumns;
	int countLines2;
	int countColumns2;
	int vectorSeize;
	int line;
	int column;
	int sum;
	int mult;
	int iteration;
	int factor;
	cout << "Колличество срок: "; cin >> countLines;
	cout << endl << "Колличество столбцов: "; cin >> countColumns;
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
	matrix = Vector2Matrix(vector, countLines, countColumns, vectorSeize);
	OutputScreen(matrix, countLines, countColumns);


	//Вычисление суммы, произведения
	cout << "\n\n---------------------Вычисление суммы, произведения---------------------\n\n";
	cout << endl << "Строка: "; cin >> line;
	cout << endl << "Столбец: "; cin >> column;
	SumMulLineMatrix(matrix, line, countColumns, sum, mult);
	cout << endl << "Сумма по заданной строке " << sum << endl << "Произведение по заданной строке " << mult << endl;

	SumMulColumnMatrix(matrix, column, countLines, sum, mult);
	cout << endl << "Сумма по заданному столбцу " << sum << endl << "Произведение по заданному столбцу " << mult << endl;

	SumMulMainDiag(matrix, countLines, countColumns, sum, mult);
	cout << endl << "Сумма по главной диагонали " << sum << endl << "Произведение по главной диагонали " << mult << endl;

	SumMulSaidDiag(matrix, countLines, countColumns, sum, mult);
	cout << endl << "Сумма по побочной диагонали " << sum << endl << "Произведение по побочной диагонали " << mult << endl;

	//Поиск минимального и максимального
	cout << "\n\n---------------------Поиск минимального и максимального---------------------\n\n";
	cout << endl << "Строка: "; cin >> line;
	cout << endl << "Столбец: "; cin >> column;

	cout << SearchLineMatrix(matrix, line, countColumns) << endl;
	cout << SearchColumnMatrix(matrix, column, countLines) << endl;
	cout << SearchMainDiag(matrix, countLines, countColumns) << endl;
	cout << SearchSaidDiag(matrix, countLines, countColumns) << endl;


	//поиск и подсчет количества
	cout << "\n\n---------------------Поиск и подсчет количества в строке---------------------\n\n";
	cout << "Искать числа в строке "; cin >> line;
	cout << "Искомы числа больше чем - "; cin >> factor;
	cout << "Числа большие чем " << factor << FindCountQuanLine(matrix, countLines, countColumns, line, MoreN, factor) << endl;

	cout << "Искомы числа меньше чем - "; cin >> factor;
	cout << "Числа меньше чем " << factor << FindCountQuanLine(matrix, countLines, countColumns, line, LessN, factor) << endl;

	cout << "Искомы числа кратны - "; cin >> factor;
	cout << "Числа кртные " << factor << FindCountQuanLine(matrix, countLines, countColumns, line, MultN, factor) << endl;

	cout << "Искомы числа равны- "; cin >> factor;
	cout << "Числа равные " << factor << FindCountQuanLine(matrix, countLines, countColumns, line,EquallyN, factor) << endl;




	cout << "\n\n---------------------Поиск и подсчет количества в столбце---------------------\n\n";
	cout << "Искать числа в столбце "; cin >> column;
	cout << "Искомы числа больше чем - "; cin >> factor;
	cout << "Числа большие чем " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, MoreN, factor) << endl;

	cout << "Искомы числа меньше чем - "; cin >> factor;
	cout << "Числа меньше чем " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, LessN, factor) << endl;

	cout << "Искомы числа кратны - "; cin >> factor;
	cout << "Числа кртные " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, MultN, factor) << endl;

	cout << "Искомы числа равны- "; cin >> factor;
	cout << "Числа равные " << factor << FindCountQuanColumn(matrix, countLines, countColumns, column, EquallyN, factor) << endl;




	cout << "\n\n---------------------Поиск и подсчет количества в главной диагонали---------------------\n\n";
	cout << "Искомы числа больше чем - "; cin >> factor;
	cout << "Числа большие чем " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, MoreN, factor) << endl;

	cout << "Искомы числа меньше чем - "; cin >> factor;
	cout << "Числа меньше чем " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, LessN, factor) << endl;

	cout << "Искомы числа кратны - "; cin >> factor;
	cout << "Числа кртные " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, MultN, factor) << endl;

	cout << "Искомы числа равны- "; cin >> factor;
	cout << "Числа равные " << factor << FindCountQuanMainDiag(matrix, countLines, countColumns, EquallyN, factor) << endl;




	cout << "\n\n---------------------Поиск и подсчет количества в побочной диагонали---------------------\n\n";
	cout << "Искомы числа больше чем - "; cin >> factor;
	cout << "Числа большие чем " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, MoreN, factor) << endl;

	cout << "Искомы числа меньше чем - "; cin >> factor;
	cout << "Числа меньше чем " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, LessN, factor) << endl;

	cout << "Искомы числа кратны - "; cin >> factor;
	cout << "Числа кртные " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, MultN, factor) << endl;

	cout << "Искомы числа равны- "; cin >> factor;
	cout << "Числа равные " << factor << FindCountQuanSaidDiag(matrix, countLines, countColumns, EquallyN, factor) << endl;




	cout << "\n\n---------------------Поиск и подсчет количества в верхнем треугольнике---------------------\n\n";
	cout << "Искомы числа больше чем - "; cin >> factor;
	cout << "Числа большие чем " << factor << FindCountQuanUp3(matrix, countLines, countColumns, MoreN, factor) << endl;

	cout << "Искомы числа меньше чем - "; cin >> factor;
	cout << "Числа меньше чем " << factor << FindCountQuanUp3(matrix, countLines, countColumns, LessN, factor) << endl;

	cout << "Искомы числа кратны - "; cin >> factor;
	cout << "Числа кртные " << factor << FindCountQuanUp3(matrix, countLines, countColumns, MultN, factor) << endl;

	cout << "Искомы числа равны- "; cin >> factor;
	cout << "Числа равные " << factor << FindCountQuanUp3(matrix, countLines, countColumns, EquallyN, factor) << endl;




	cout << "\n\n---------------------Поиск и подсчет количества в нижнем треугольнике---------------------\n\n";
	cout << "Искомы числа больше чем - "; cin >> factor;
	cout << "Числа большие чем " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, MoreN, factor) << endl;

	cout << "Искомы числа меньше чем - "; cin >> factor;
	cout << "Числа меньше чем " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, LessN, factor) << endl;

	cout << "Искомы числа кратны - "; cin >> factor;
	cout << "Числа кртные " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, MultN, factor) << endl;

	cout << "Искомы числа равны- "; cin >> factor;
	cout << "Числа равные " << factor << FindCountQuanUnder3(matrix, countLines, countColumns, EquallyN, factor) << endl;

	//Удление строки в динамическом массиве
	cout << "\n\n---------------------Удление строки в динамическом массиве---------------------\n\n";
	cout << "Сколько строк удалить?"; cin >> iteration;
	for (int i = 0; i < iteration; i++)
	{
		line = 0;
		cout << "Удаляема строка : "; cin >> line;
		matrix = DeleteStrMatrix(matrix, countLines, countColumns, line);
		OutputScreen(matrix, countLines, countColumns);
		cout << endl;
	}

	//Удление столбца в динамическом массиве

	cout << "\n\n---------------------Удление столбца в динамическом массиве---------------------\n\n";
	cout << "Сколько столбцов удалить? "; cin >> iteration;
	for (int i = 0; i < iteration; i++)
	{
		cout << "Удаляемый столбец : "; cin >> column;
		matrix = DeleteColMatrix(matrix, countLines, countColumns, column);
		OutputScreen(matrix, countLines - i, countColumns);
		cout << endl;
	}
	
	//Сортировка

	cout << "\n\n---------------------Сортировка строки---------------------\n\n";
	cout << "Сортируемая строка: "; cin >> line;
	PasteSortMatrix(matrix, countLines, countColumns, line, column);
	OutputScreen(matrix, countLines, countColumns);

	cout << "\n\n---------------------Сортировка столбца---------------------\n\n";
	cout << "Сортируемый столбец: "; cin >> column;
	PasteSortMatrix(matrix, countLines, countColumns,line, column);
	OutputScreen(matrix, countLines, countColumns);

	cout << "\n\n---------------------Сортировка всего массива---------------------\n\n";
	PasteSortMatrix(matrix, countLines, countColumns, line ,column);
	OutputScreen(matrix, countLines, countColumns);
	

	//Умножение матрицы на вектор
	cout << "\n\n---------------------Умножение матрицы на вектор---------------------\n\n";
	int* vector2{ new int[countLines] };
	vector2 = InputRandVector(vector2, countLines);
	OutVectorScreen(vector2, countLines);
	matrix = multMtrix2Vector(matrix, vector2, countLines, countColumns);
	OutputScreen(matrix, countLines, countColumns);

	cout << "\n\n---------------------Умножение матрицы на матрицу---------------------\n\n";
	

	cout << "Колличество срок: "; cin >> countLines2;
	cout << endl << "Колличество столбцов: "; cin >> countColumns2;
	int** matrix2{ new int* [countLines2] };
	for (int i = 0; i < countLines2; i++)
	{
		matrix2[i] = new int[countColumns2];
	}
	matrix2 = InputRand(matrix2, countLines2, countColumns2);
	OutputScreen(matrix2, countLines2, countColumns2);
	cout << endl;
	matrix = multMatrix2Matrix(matrix, matrix2, countLines,countColumns, countLines2, countColumns2);
	OutputScreen(matrix, countLines, countColumns);


	//Преобразование матрицы 
	cout << "\n\n---------------------Преобразование матрицы---------------------\n\n";
	cout << "Номер строки: "; cin >> line;
	cout << "Умнжить на: "; cin >> factor;
	matrixTransformation(matrix, countColumns, line, factor, 0);
	OutputScreen(matrix, countLines, countColumns);

	cout << "Номер строки: "; cin >> line;
	cout << "Поделить на: "; cin >> factor;
	matrixTransformation(matrix, countColumns, line, factor, 1);
	OutputScreen(matrix, countLines, countColumns);

	//Транспорирование

	cout << "\n\n---------------------транспорирование---------------------\n\n";
	matrix = InputRand(matrix, countLines, countColumns);
	OutputScreen(matrix, countLines, countColumns);
	cout << endl;
	Transportation(matrix, countLines, countColumns);
	OutputScreen(matrix, countLines, countColumns);
	cout << endl;
	system("pause");

	//Бонус
	InputKeyboard(matrix, countLines, countColumns);
	cout << endl << endl;
	OutputScreen(matrix, countLines, countColumns);
	cout << "Количество столбцов, содержащих хотя бы один нулевой элемент: " << Bonus1(matrix, countLines, countColumns) << endl;
	cout << "номер строки, в которой находится самая длинная серия одинаковых элементов: " << Bonus2(matrix, countLines, countColumns) << endl;
	system("pause");



	return 0;
}
