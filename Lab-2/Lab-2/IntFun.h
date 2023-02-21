#pragma once
#include <string>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <iomanip>

int** InputRand(int** matrix, int countLines, int countColumns);

void OutputScreen(int** matrix, int countLines, int countColumns);
void OutVectorScreen(int* vector, int vectorSize);

int* Matrix2Vector(int** matrix, int newCountLines, int newCountCloums);
int** Vector2Matrix(int* vector, int countLines, int countColumns);

void SumMulLineMatrix(int** matrix, int line, int countColumns, int& sum, int& mult);
void SumMulColumnMatrix(int** matrix, int column, int countLines, int& sum, int& mult);
void SumMulMainDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);
void SumMulSaidDiag(int** matrix, int countLines, int countColumns, int& sum, int& mult);

string SearchLineMatrix(int line, int countColumns, int** matrix);
string SearchColumnMatrix(int column, int countLines, int** matrix);
void SearchMainDiag(int** matrix, int countLines, int countColumns, int& min, int& max);
void SearchSaidDiag(int** matrix, int countLines, int countColumns, int& min, int& max);

string concatenateStrings(const std::string& str1, const std::string& str2);