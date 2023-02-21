#pragma once
#include <string>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int** InputRand(int** matrix, int countLines, int countColumns);

void OutputScreen(int** matrix, int countLines, int countColumns);
void OutVectorScreen(int* vector, int vectorSize);

int* Matrix2Vector(int** matrix, int newCountLines, int newCountCloums);
int** Vector2Matrix(int* vector, int countLines, int countColumns);

void SumMulLineMatrix(int** matrix, int line, int countColumns, int& sum, int& mult);
void SumMulColumnMatrix(int** matrix, int column, int countLines, int& sum, int& mult);
void SumMulMainDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);
void SumMulSaidDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);

string SearchLineMatrix(int** matrix, int line, int countColumns);
string SearchColumnMatrix(int** matrix, int column, int countLines);
string SearchMainDiag(int** matrix, int countLines, int countColumns);
string SearchSaidDiag(int** matrix, int countLines, int countColumns);
