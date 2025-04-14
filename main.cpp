// /*************************************************************
//  * ДЗ-2 Примитивная рекурсия (Вариант 2.10)
//  * Студент: Батычков Вячеслав Геннадьевич, КТбо1-7
//  * Программа: Реализует вычисление функции f(x1, x2),
//  * полученной из базовых функций:
//  *   g(x) = x
//  *   h(x, y, z) = x + y
//  * по схеме примитивной рекурсии:
//  *   1) f(0, x2) = x2
//  *   2) f(x1 + 1, x2) = x1 + f(x1, x2)
//  * Аналитическая формула (для x1 ≥ 0):
//  *   f(x1, x2) = x2 + (x1 * (x1 - 1)) / 2
//  *************************************************************/

#include <iostream>
#include <clocale>
#include <windows.h>
#include <string>
#include <limits>

using namespace std;

// Структура для хранения результата рекурсивной функции
struct RecurResult {
    int value;       // Вычисленное значение функции
    wstring trace;   // Пошаговое описание вычислений
};

// Примитивно-рекурсивная реализация функции F(n, x)
// Ввод: шаг рекурсии и параметр
// Вывод: занчение примитивно-рекурсивной функции
RecurResult recurFunc(int x1, int x2);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    wcout << L"Схема рекурсии:\n1) f(0, x2) = x2\n2) f(x1 + 1, x2) = x1 + f(x1, x2)\n"
          << L"Аналитическая формула: f(x1, x2) = x2 + (x1 * (x1 - 1)) / 2\n\n";

    bool programRunning = true;
    while (programRunning) {
        int x1, x2;
        bool inputValid = true;
        wcout << L"Введите x1: ";
        if (!(cin >> x1)) {
            wcout << L"Ошибка: введите целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inputValid = false;
        }
        if (inputValid) {
            wcout << L"Введите x2: ";
            if (!(cin >> x2)) {
                wcout << L"Ошибка: введите целое число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                inputValid = false;
            }
        }
        bool flag = inputValid;
        if (inputValid && x1 < 0) {
            wcout << L"Ошибка: x1 должен быть неотрицательным." << endl;
            flag = false;
        }
        if (!flag) {
            bool validChoice = false;
            int choice = 0;
            while (!validChoice) {
                wcout << L"Повторить ввод? (1 - да, 2 - нет): ";
                if (cin >> choice && (choice == 1 || choice == 2))
                    validChoice = true;
                else {
                    wcout << L"Ошибка: введите 1 или 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            programRunning = (choice == 1);
        }
        if (flag) {
            RecurResult recursionResult = recurFunc(x1, x2);
            wcout << L"--- Пошаговое вычисление ---\n" << recursionResult.trace << endl;
            int analiticResult = x2 + (x1 * (x1 - 1)) / 2;
            wcout << L"--- Сравнение с аналитической формулой ---\n"
                  << L"f(" << x1 << L"," << x2 << L") по рекурсии = " << recursionResult.value << endl
                  << L"f(" << x1 << L"," << x2 << L") по аналитической формуле = " << analiticResult << endl
                  << (recursionResult.value == analiticResult ? L"Результаты совпадают!\n" : L"Результаты НЕ совпадают!\n");
            bool validChoice = false;
            int choice = 0;
            while (!validChoice) {
                wcout << L"Повторить ввод? (1 - да, 2 - нет): ";
                if (cin >> choice && (choice == 1 || choice == 2))
                    validChoice = true;
                else {
                    wcout << L"Ошибка: введите 1 или 2." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            programRunning = (choice == 1);
        }
    }
    wcout << L"Программа завершена." << endl;
    return 0;
}

RecurResult recurFunc(int x1, int x2) {
    if (x1 == 0) {
        RecurResult result;
        result.value = x2;
        result.trace = L"f(0," + to_wstring(x2) + L") = " + to_wstring(x2) + L"\n";
        return result;
    }
    RecurResult prev = recurFunc(x1 - 1, x2);
    RecurResult current;
    current.value = x1 - 1 + prev.value;
    current.trace = prev.trace + L"f(" + to_wstring(x1) + L"," + to_wstring(x2) 
        + L") = h(" + to_wstring(x1 - 1) + L", f(" + to_wstring(x1 - 1) + L"," 
        + to_wstring(x2) + L"), " + to_wstring(x2) + L") = h(" + to_wstring(x1 - 1) 
        + L"," + to_wstring(prev.value) + L"," + to_wstring(x2) + L") = " 
        + to_wstring(current.value) + L"\n";

    return current;
}