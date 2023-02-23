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
int** Vector2Matrix(int* vector, int countLines, int countColumns, int vectorSize);

void SumMulLineMatrix(int** matrix, int line, int countColumns, int& sum, int& mult);
void SumMulColumnMatrix(int** matrix, int column, int countLines, int& sum, int& mult);
void SumMulMainDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);
void SumMulSaidDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);

string SearchLineMatrix(int** matrix, int line, int countColumns);
string SearchColumnMatrix(int** matrix, int column, int countLines);
string SearchMainDiag(int** matrix, int countLines, int countColumns);
string SearchSaidDiag(int** matrix, int countLines, int countColumns);

bool MoreN(int value, int factor);
bool LessN(int value, int factor);
bool MultN(int value, int factor);
bool EquallyN(int value, int factor);
string	FindCountQuan(int** matrix, int countLines, int countColumns, bool (*pred)(int, int), int N);

int** DeleteStrMatrix(int** matrix, int& countLines, int countColumns, int deathLine);
int** DeleteColMatrix(int** matrix, int countLines, int& countColumns, int deathColumn);