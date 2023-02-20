#pragma once

int** InputRand(int** matrix, int countLines, int countColumns);


void OutputScreen(int** matrix, int countLines, int countColumns);
void OutVectorScreen(int* vector, int vectorSize);

int* Matrix2Vector(int** matrix, int newCountLines, int newCountCloums);
int** Vector2Matrix(int* vector, int countLines, int countColumns);