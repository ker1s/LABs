#include <vector>
#include <chrono>
using namespace std;

int MultEvenARR(vector<int>& ARR) {
    int answ{ 1 };
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) {
        if (i % 2 == 0) {
            answ *= ARR[i];
        }
    }
    return answ;
}
int SumZero2Zero(vector<int>& ARR) {
    int answ{ 0 };
    int indexFirstZero;
    int indexLastZero;
    for (int i = 0; i < static_cast<int>(ARR.size()); i++) {
        if (ARR[i] == 0) {
            indexFirstZero = i;
            break;
        }
    }

    for (int i = 0; i < static_cast<int>(ARR.size()); i++) {
        if (ARR[i] == 0) {
            indexLastZero = i;
        }
    }

    for (int i = indexFirstZero; i <= indexLastZero; i++) {
        answ += ARR[i];
    }
    return answ;
}
void ConverARR(vector<int>& ARR) {
    vector <int> temp (static_cast<int> (ARR.size()));
    int indexPositive{ 0 };
    int indexNIGGAtive{ static_cast<int> (ARR.size()) };

    for (int i = 0; i < ARR.size(); i++) {
        if (ARR[i] >= 0) {
            temp[indexPositive] = ARR[i];
            indexPositive++;
        }
        else {
            temp[indexNIGGAtive] = ARR[i];
            indexNIGGAtive--;
        }
    }
    
    ARR.assign(temp.begin(), temp.end());

}