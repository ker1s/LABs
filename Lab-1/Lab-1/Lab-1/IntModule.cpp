#include "IntModule.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <sstream>
#include <algorithm>



void RandValues(vector<int>& ARR, int size) {

    random_device seed;
    mt19937 generator(seed());
    uniform_int_distribution<int> distribution(-100, 100);

    for (int i = 0; i < size; i++)
        ARR.push_back(distribution(generator));

}

bool Range(int index, int start, int end) {
    return (index >= start) && (index <= end);
}
int SumARR(vector<int>& ARR, int start, int end, bool(*pred)(int, int, int)) {
    int summ{ 0 };
    int size{static_cast<int>(ARR.size() - 1) };
    for (int i = 0; i < size; i++) {
        if ((*pred)(i, start, end)) {
            summ += ARR[i];
        }
    }
    return summ;
}
int MultARR(vector<int>& ARR, int start, int end, bool(*pred)(int, int, int)) {
    int mult{ 1 };
    int size{ static_cast<int>(ARR.size() - 1) };
    for (int i = start; i < size; i++) {
        if ((*pred)(i, start, end))
            mult *= ARR[i];
    }
    return mult;
}

void PasteARR(vector<int>& ARR, int index, int value) {
    int size = ARR.size();
    ARR.resize(size + 1);
    for (int i = size - 1; i >= index; i--) {
        ARR[i + 1] = ARR[i];
    }
    ARR[index] = value;
}
void DeleteARR(vector<int>& ARR, int index) {
    int size = ARR.size();

    for (int i = index; i < size - 1; i++) {
        ARR[i] = ARR[i + 1];
    }
    ARR.resize(size - 1);
}

void BubbleSort(vector<int>& ARR, int lengthARR) {
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
void ChoiceSort(vector<int>& ARR, int lenghtARR) {
    for (int i = 0; i < lenghtARR; i++) {
        int smallPos = MinValARR(ARR, i, lenghtARR);
        swap(ARR[i], ARR[smallPos]);
    }
}
void PasteSort(vector<int>& ARR, int lengthARR) {
    for (int i = 1; i < lengthARR; i++) {
        int j{ i - 1 };

        while (j >= 0 && ARR[j] > ARR[j + 1]) {
            swap(ARR[j], ARR[j + 1]);
            j--;
        }
    }
}

int MinValARR(vector<int>& ARR, int start, int lengthARR) {
    int smallPos = start;

    for (int i = start+1; i < lengthARR; i++) {
        if (ARR[i] < ARR[smallPos]) smallPos = i;
    }
    return smallPos;
}
int MaxValARR(vector<int>& ARR, int start, int lengthARR) {
    int largePos = start;
    for (int i = start; i < lengthARR; i++) {
        if (ARR[i] > ARR[largePos]) largePos = i;
    }
    return largePos;
}

int BinSerchARR(vector<int>& ARR, int value) {
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

bool Positive(int value) {
    return value >= 0;
}
bool NIGGAtive(int value) {
    return value < 0;
}
bool Zero(int value) {
    return value == 0;
}
bool MultF(int value, int factor) {
    
    return (value % factor) == 0;
}


int Count(vector<int>& ARR, bool(*pred)(int)) {
    int count{ 0 };
    for (int i = 0; i < static_cast<int>( ARR.size()); i++) {
        if ((*pred)(ARR[i]))count++;
    }
    return count;
}

int CountF(vector<int>& ARR, int factor, bool(*pred)(int, int)) {
    int count{ 0 };
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) {
        if ((*pred)(ARR[i], factor))count++;
    }
    return count;
}

void InputArr(vector<int>& ARR,int size) {
    ARR.resize(size);
    for (int i = 0; i < size; i++) {
        int temp;
        cout << endl << i+1 << "-й" << " элемент массива: ";
        cin >> temp;
        ARR.at(i) = temp;
    }
}
void InputFileARR(vector<int>& ARR,int size) {
    
    string line;
    int i{ 0 };
    ARR.resize(size);
    ifstream file("input.txt");
    if (!file) cerr << "Файл не открыт\n\n";
    
    while (getline(file, line, ';') && i < size) {
        if (i > static_cast<int>(ARR.size()) - 1)
            break;
    
        istringstream iss(line);
        int num;
        if (iss >> num) {
            num = stoi(line);
            ARR.at(i) = num;
            i++;
        }
    }
    file.close();
}

void ArrOut(vector<int>& ARR) {
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) cout << setw(12) << ARR[i];
    cout << endl;
}
void ArrOutFile(vector<int>& ARR) {
    ofstream out_file("ching-chong.txt");
    if (out_file.is_open()) {
        for (int value : ARR) {
            out_file << value << endl;
        }
        out_file.close();
        cout << "Значения были записаны в ching-chong.txt" << endl;
    }
    else cerr << "Неполучилось открыть файл";
}

void RegenARR(vector<int>& ARR, int size) {
    ARR.clear();
    RandValues(ARR, size);
    cout << endl;
    ArrOut(ARR);
}