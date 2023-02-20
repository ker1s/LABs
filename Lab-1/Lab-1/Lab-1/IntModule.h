#include <vector>
#include <chrono>
#include <format>
using namespace std;
#pragma once
void RandValues(vector<int>& ARR, int size);

bool Range(int index, int start, int end);
int SumARR(vector<int>& ARR, int start, int end, bool(*pred)(int, int, int));
int MultARR(vector<int>& ARR, int start, int end, bool(*pred)(int, int, int));

void PasteARR(vector<int>& ARR, int index, int value);
void DeleteARR(vector<int>& ARR, int index);

void BubbleSort(vector<int>& ARR, int lengthARR);
void ChoiceSort(vector<int>& ARR, int lenghtARR);
void PasteSort(vector<int>& ARR, int lengthARR);

int MinValARR(vector<int>& ARR, int start, int lengthARR);
int MaxValARR(vector<int>& ARR, int start, int lengthARR);

int BinSerchARR(vector<int>& ARR, int value);

bool Positive(int value);
bool NIGGAtive(int value);
bool Zero(int value);
bool MultF(int value, int factor);
int Count(vector<int>& ARR, bool(*pred)(int));
int CountF(vector<int>& ARR, int factor, bool(*pred)(int, int));

void InputArr(vector<int>& ARR, int size);
void InputFileARR(vector<int>& ARR, int size);
void ArrOut(vector<int>& ARR);
void ArrOutFile(vector<int>& ARR);

void RegenARR(vector<int>& ARR, int size);