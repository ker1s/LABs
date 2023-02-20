#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <sstream>
#include "FloatModule.h"

void RandValues(vector<float>& ARR, int size) {

    default_random_engine generator(time(0));
    uniform_real_distribution<float> distribution(-100.0, 100.0);

    for (int i = 0; i < size; i++) {
        ARR.push_back(distribution(generator));
    }
    RoundArrValues(ARR);
}
void RoundArrValues(vector<float>& ARR) {
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) {
        ARR[i] = round(ARR[i] * 10000) / 10000;
    }
}

float SumARR(int start, int end, vector<float>& ARR, bool (*pred)(int,int,int)) {
    float summ{ 0.0 };
    int size{ static_cast<int>(ARR.size() - 1) };
    for (int i = start; i < size; i++) {
        if ((*pred)(i, start, end)){
            summ += ARR[i];
        }
    }
    return summ;
}
float MultARR(int start, int end, vector<float>& ARR, bool(*pred)(int, int, int)) {
    float mult{ 1.0 };
    int size{ static_cast<int>(ARR.size() - 1) };
    for (int i = start; i < size; i++) {
        if ((*pred)(i, start, end)){
            mult *= ARR[i];
        }
    }
    return mult;
}

void PasteARR(vector<float>& ARR, int index, float value) {
    int size = ARR.size();
    ARR.resize(size + 1);
    for (int i = size - 1; i >= index; i--) {
        ARR[i + 1] = ARR[i];
    }
    ARR[index] = value;
}
void DeleteARR(vector<float>& ARR, int index) {
    int size = ARR.size();

    for (int i = index; i < size - 1; i++) {
        ARR[i] = ARR[i + 1];
    }
    ARR.resize(size - 1);
}

void swap(float& a, float& b) {
    float temp = a;
    a = b;
    b = temp;
}
void BubbleSort(vector<float>& ARR) {
    int lengthARR{ static_cast<int>(ARR.size()) };
    while (lengthARR--)
    {
        bool swapped = false;

        for (int i = 0; i < lengthARR; i++)
        {
            if (ARR[i] > ARR[i + 1])
            {
                swap(ARR[i], ARR[i + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}
void ChoiceSort(vector<float>& ARR, int lengthARR) {
    for (int i = 0; i < lengthARR; i++) {
        int smallPos = MinValARR(i, ARR, lengthARR);
        for (int j = i + 1; j < lengthARR; j++) {
            if (ARR[j] < ARR[smallPos]) {
                smallPos = j;
            }
        }
        swap(ARR[i], ARR[smallPos]);
    }
}
void PasteSort(vector<float>& ARR) {
    int lengthARR{ static_cast<int>(ARR.size()) };
    for (int i = 1; i < lengthARR; i++) {
        int j{ i - 1 };

        while (j >= 0 && ARR[j] > ARR[j + 1]) {
            swap(ARR[j], ARR[j + 1]);
            j--;
        }
    }
}

int MaxValARR(int start, vector<float>& ARR, int lengthARR) {
    int largePos = start;
    for (int i = start; i < lengthARR; i++) {
        if (ARR[i] > ARR[largePos]) largePos = i;
    }
    return largePos;
}
int MinValARR(int start, vector<float>& ARR, int lengthARR) {
    int smallPos = start;

    for (int i = start; i < lengthARR; i++) {
        if (ARR[i] < ARR[smallPos]) smallPos = i;
    }
    return smallPos;
}

int BinSerchARR(vector<float>& ARR, float value) {
    bool complete{ false };
    int left{ 0 };
    int right{ static_cast <int> (ARR.size() - 1) };
    int mid;
    while ((left <= right) && (complete != true)) {
        mid = (left + right) / 2;
        if (ARR[mid] == value) complete = true;
        if (ARR[mid] > value) right = mid - 1;
        if (ARR[mid] < value) left = mid + 1;
    }
    if (complete == true) return mid;
    else return 404;
}

int Count(bool(*pred)(int), vector<float>& ARR) {
    int count{ 0 };
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) {
        if ((*pred)(ARR[i]))count++;
    }
    return count;
}
int CountF(vector<float>& ARR, bool(*pred)(int, int), int factor) {
    int count{ 0 };
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) {
        if ((*pred)(ARR[i], factor))count++;
    }
    return count;
}

void InputArr(int size, vector<float>& ARR) {
    ARR.resize(size);
    for (int i = 0; i < size; i++) {
        float temp;
        cout << endl << i+1 << "-й" << " элемент массива: ";
        cin >> temp;
        ARR.at(i) = temp;
    }
}
void InputFileARR(int size, vector<float>& ARR) {
    string line;
    int i{ 0 };
    ARR.resize(size);
    ifstream file("inputFLOAT.txt");
    if (!file) cerr << "Файл не открыт\n\n";

    while (getline(file, line, ';') && i < size) {
        if (i > static_cast<int>(ARR.size()) - 1)
            break;
        istringstream iss(line);
        float num;
        if (iss >> num) {
            ARR.at(i) = num;
            i++;
        }
    }
    file.close();
}
void ArrOut(vector<float>& ARR) {
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) cout << setw(12) << ARR[i];
    cout << endl;
}
void ArrOutFile(vector<float>& ARR) {
    ofstream out_file("ching-chong.txt");
    if (out_file.is_open()) {
        for (float value : ARR) {
            out_file << value << endl;
        }
        out_file.close();
        cout << "Значения были записаны в ching-chong-float.txt";
    }
    else cerr << "Неполучилось открыть файл";
}

void RegenARR(vector<float>& ARR, int old_size) {
    ARR.clear();
    RandValues(ARR, old_size);
    cout << endl;
    ArrOut(ARR);
}
