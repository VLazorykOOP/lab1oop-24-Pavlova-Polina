 // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

#include <locale>

using namespace std;
//
// Задача 1  (якщо к-сть непарна то перша частина буде меншою)
// 
void task1() {
    int N;
    cout << "Введіть розмір масиву N: ";
    cin >> N;
    int A[100];
    cout << "Введіть елементи масиву A:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
    // множення першої половини на 2
    for (int i = 0; i < N / 2; ++i) {
        A[i] *= 2;
    }
    // множ другої половини на 3
    for (int i = N / 2; i < N; ++i) {
        A[i] *= 3;
    }
    // виведення
    cout << "Змінений масив A:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
}
//
// Задача 2(Знайти номер останнього мінімального елемента серед парних доданих елементів, що лежать правіше першого від'ємного елемента)
//
void task2() {
    int N;
    cout << "Введіть розмір масиву N: ";
    cin >> N;
    int A[100];
    cout << "Введіть елементи масиву A:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
    // пошук індексу першого від'ємного елемента
    int firstNegIndex = -1;// це перше негативне
    for (int i = 0; i < N; ++i) {
        if (A[i] < 0) {
            firstNegIndex = i;
            break;
        }
    }
    // пошук індексу останнього мін ел серед парних додатніх
    int lastMinIndex = -1;  //це останнє мінімальне(індекс)
    int minEl = INT_MAX;    //це мін елемент серед парних додатніх
    for (int i = firstNegIndex + 1; i < N; ++i) {
        if (A[i] > 0 && A[i] % 2 == 0) {
            if (A[i] <= minEl) {
                minEl = A[i];
                lastMinIndex = i;
            }
        }
    }
    // виведення(індекс починається з 0)
    if (lastMinIndex != -1) {
        cout << "Номер останнього мін. елемента серед парних додатних, що лежать правіше першого від’ємного елемента: " << lastMinIndex << endl;
    }
    else {
        cout << "Не знайдено парних додатних елементів правіше першого від'ємного елемента." << endl;
    }
}
int main() {
    setlocale(LC_CTYPE, "Ukr");
    int task;
    cout << "Введіть номер завдання (1, 2): ";
    cin >> task;
    switch (task) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    default:
        cout << "Невірний номер завдання." << endl;
    }
    return 0;
}
