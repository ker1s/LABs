#include <vector>
#include <chrono>
#include <format>
using namespace std;
#pragma once

void RandValues(vector<float>& ARR, int size);
void RoundArrValues(vector<float>& ARR);

//bool Diap(int index, int start, int end);
float SumARR(int start, int end, vector<float>& ARR, bool(*pred)(int,int,int) );
float MultARR(int start, int end, vector<float>& ARR, bool(*pred)(int, int, int));

void PasteARR(vector<float>& ARR, int index, float value);
void DeleteARR(vector<float>& ARR, int index);
void swap(float& a, float& b);
void BubbleSort(vector<float>& ARR);
void ChoiceSort(vector<float>& ARR, int lengthARR);
void PasteSort(vector<float>& ARR);

int MaxValARR(int start, vector<float>& ARR, int lengthARR);
int MinValARR(int start, vector<float>& ARR, int lengthARR);

int BinSerchARR(vector<float>& ARR, float value);

int Count(bool(*pred)(int), vector<float>& ARR);
int CountF(vector<float>& ARR, bool(*pred)(int, int), int factor);

void InputArr(int size, vector<float>& ARR);
void InputFileARR(int size, vector<float>& ARR);
void ArrOut(vector<float>& ARR);
void ArrOutFile(vector<float>& ARR);

void RegenARR(vector<float>& ARR, int old_size);
