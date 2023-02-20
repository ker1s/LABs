#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <algorithm>
#include "IntModule.h"
#include "FloatModule.h"
#include "Bonus.h"


using namespace std;




int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    int task;
    int enter{ 1 };
    while (enter == 1)
    {
        cout << "INT - 1 \nFLOAT - 2 \nBONUS - 3\n\n"; cin >> task;
        switch (task) {
        case 1: {
            int size;
            int start;
            int end;
            int quan;
            int searchVal;
            int factor;

            cout << "Введите размер массива ";
            cin >> size;
            vector<int> X;
            X.reserve(size);

            //Заполенение случайными значениями
            RandValues(X, size);
            //Вывод на экран
            ArrOut(X);
            

            //Сумма и умножение
            cout << "\nВведите диапазон (через пробел, или enter)\n";
            cin >> start >> end;
            while (start > end) {
                cout << "Ошибка!!! Попробуйте ещё раз.\n";
                cin >> start >> end;
            }

            cout << "\nСумма элементов из заданного диапазона равна " << SumARR(X, start - 1, end - 1, Range) << endl;
            cout << "\nПроизведение элементов из заданного диапазона равно " << MultARR(X, start - 1, end - 1, Range) << endl;

            //Вставка
            cout << "\nСколько элементов хотите вставить? \n";
            cin >> quan;
            for (int i = 0; i < quan; i++) {
                int tempValue;
                int tempIndex;
                cout << i + 1 << " значение равно "; cin >> tempValue;
                cout << "\nНа какое место хотите его поставить? \n"; cin >> tempIndex;
                PasteARR(X, tempIndex - 1, tempValue);
            }
            ArrOut(X);

            //Удаление
            cout << "\nСколько элементов хотите удалить? \n";
            cin >> quan;
            for (int i = 0; i < quan; i++) {
                int tempIndex;
                cout << "\nКакой элемент хотите удалить? \n"; cin >> tempIndex;
                DeleteARR(X, tempIndex - 1);
            }
            ArrOut(X);

            //Метод ПУЗЫРЬКОВОЙ сортировки
            cout << "\n\nМетод ПУЗЫРЬКОВОЙ сортировки \n";
            BubbleSort(X, X.size());
            ArrOut(X);

            RegenARR(X, X.size());

            //Метод сортировки ВЫБОРОМ
            cout << "\n\nМетод сортировки ВЫБОРОМ \n";
            ChoiceSort(X, X.size());
            ArrOut(X);

            RegenARR(X, X.size());

            //Метод сортировки ВСТАВКАМИ
            cout << "\n\nМетод сортировки ВСТАВКАМИ \n";
            PasteSort(X, X.size());
            ArrOut(X);

            //Бинарный поиск
            cout << "Введите искомое значение "; cin >> searchVal;
            if (BinSerchARR(X, searchVal) == 404) cout << "Нет такого" << endl;
            else cout << "Значение имеет индекс " << BinSerchARR(X, searchVal) << endl;


            X.clear();
            
            //Ввод массива с клавиатуры
            InputArr(X, size);
            ArrOut(X);
            //Вывод в файл
            ArrOutFile(X);
            
            X.clear();
            
            //Ввод массива из файла
            InputFileARR(X, size);
            X.shrink_to_fit();
            ArrOut(X);

            cout << endl << endl;
            system("pause");
            //Линейный поиск
            cout << "\n\nМинимальное значение данного массива равно " << X[MinValARR(X, 0, X.size())] << endl;
            cout << "\n\nМаксимальное значение данного массива равно " << X[MaxValARR(X, 0, X.size())];

            //Подсчет количества элементов с указанной  характеристикой
            //Положительных
            cout << "Колличество положительных числе в данном массиве равно " << Count(X, Positive) << endl;

            //Отрицательных
            cout << "Колличество положительных числе в данном массиве равно " << Count(X, NIGGAtive) << endl;

            //Нулевые
            cout << "Колличество нулевых числе в данном массиве равно " << Count(X, Zero) << endl;

            //Кратные произвольному числу
            cout << "\nКратных какому числу нужно найти? \n"; cin >> factor;
            cout << "Колличество положительных числе в данном массиве равно " << CountF(X, factor, MultF) << endl;

           

        }
              break;

        case 2: {
            int size;
            int start;
            int end;
            int quan;
            float searchVal;
            int factor;
              
            cout << "Введите размер массива ";
            cin >> size;
            vector<float> X;
            X.reserve(size);
              
            //Заполенение случайными значениями
            RandValues(X, size);
            //Вывод на экран
            ArrOut(X);
            cout << endl << X.size();

            //Сумма и умножение
            cout << "\nВведите диапазон (через пробел, или enter)\n";
            cin >> start >> end;
            while (start > end) {
                cout << "Ошибка!!! Попробуйте ещё раз.\n";
                cin >> start >> end;
            }

            cout << "\nСумма элементов из заданного диапазона равна " << SumARR(start - 1, end - 1, X, Range) << endl;
            cout << "\nПроизведение элементов из заданного диапазона равно " << MultARR(start - 1, end - 1, X, Range) << endl;

            // Вставка
            cout << "\nСколько элементов хотите вставить? \n";
            cin >> quan;
            for (int i = 0; i < quan; i++) {
                float tempValue;
                int tempIndex;
                cout << i + 1 << " значение равно "; cin >> tempValue;
                cout << "\nНа какое место хотите его поставить? \n"; cin >> tempIndex;
                PasteARR(X, tempIndex - 1, tempValue);
            }
            ArrOut(X);

            //Удаление
            cout << "\nСколько элементов хотите удалить? \n";
            cin >> quan;
            for (int i = 0; i < quan; i++) {
                int tempIndex;
                cout << "\nКакой элемент хотите удалить? \n"; cin >> tempIndex;
                DeleteARR(X, tempIndex - 1);
            }
            ArrOut(X);
            
            //Метод ПУЗЫРЬКОВОЙ сортировки
            cout << "\n\nМетод ПУЗЫРЬКОВОЙ сортировки \n";
            BubbleSort(X);
            ArrOut(X);

            X.clear();
            RandValues(X, size);
            cout << endl;

            ArrOut(X);

            //Метод сортировки ВЫБОРОМ
            cout << "\n\nМетод сортировки ВЫБОРОМ \n";
            ChoiceSort(X, size);
            ArrOut(X);

            RegenARR(X, X.size());

            //Метод сортировки ВСТАВКАМИ
            cout << "\n\nМетод сортировки ВСТАВКАМИ \n";
            PasteSort(X);
            ArrOut(X);


            cout << endl << X.size();
            cout << endl << MinValARR(0, X, X.size()) << endl;


            //Бинарный поиск
            cout << "Введите искомое значение "; cin >> searchVal;
            if (BinSerchARR(X, searchVal) == 404) cout << "Нет такого" << endl;
            else cout << "Значение имеет индекс " << BinSerchARR(X, searchVal) << endl;


            X.clear();
            //Ввод массива с клавиатуры
            InputArr(size, X);
            ArrOut(X);
            //Вывод в файл
            ArrOutFile(X);

            X.clear();
            //Ввод массива из файла
            InputFileARR(size,X);
            ArrOut(X);



            //Линейный поиск
            cout << "\n\nМинимальное значение данного массива равно " << X[MinValARR(0, X, X.size())] << endl;
            cout << "\n\nМаксимальное значение данного массива равно " << X[MaxValARR(0, X,X.size())] << endl;

            //Подсчет количества элементов с указанной  характеристикой
            //Положительных
            cout << "Колличество положительных числе в данном массиве равно " << Count(Positive, X) << endl;

            //Отрицательных
            cout << "Колличество положительных числе в данном массиве равно " << Count(NIGGAtive, X) << endl;

            //Нулевые
            cout << "Колличество положительных числе в данном массиве равно " << Count(Zero, X) << endl;

            //Кратные произвольному числу
            cout << "\nКратных какому числу нужно найти? \n"; cin >> factor;
            cout << "Колличество чисел кратных введёному числу в данном массиве равно " << CountF(X, MultF, factor) << endl;


        }
                  break; 
    
        case 3: {
            int size;

            cout << "Введите размер массива ";
            cin >> size;
            vector<int> X;
            X.reserve(size);

            //Заполенение 
            InputArr(X,size);
            //Вывод на экран
            ArrOut(X);

            cout << "Произведение элементов массива с четными номерами: " <<MultEvenARR(X)<< endl;
            cout << "Сумма элементов массива, расположенных между первым и последним нулевыми элементами: " << SumZero2Zero(X) << endl;
            ConverARR(X);
            cout << endl << "Преобразованный массив:" << endl;
            ArrOut(X);




        }
              break;

        default: {
            system("cls");
            cout << "Нет такого!!!";
            system("pause");
        }
               break;
        }

        
        system("pause");
        system("cls");
        cout << "Для продолжения нажмите 1.";
        cin >> enter;
    }
    return 0;
}
