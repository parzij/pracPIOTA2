/*************************************************************
 * ДЗ-2 Примитивная рекурсия (Вариант 2.10)
 *
 * Студент: Батычков Вячеслаав Геннадьевич, КТбо1-7
 *
 * Программа: Реализует вычисление функции f(x1, x2),
 * полученной из базовых функций:
 *   g(x) = x
 *   h(x, y, z) = x + y
 * по схеме примитивной рекурсии:
 *   1) f(0, x2) = x2
 *   2) f(x1 + 1, x2) = h(x1, f(x1, x2), x2) = x1 + f(x1, x2)
 *
 * Аналитическая формула (для x1 ≥ 0):
 *   f(x1, x2) = x2 + (x1 * (x1 - 1)) / 2
 *
 *************************************************************/

#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

// Примитивно-рекурсивная реализация функции F(n, x)
// Ввод: шаг рекурсии и параметр
// Вывод: занчение примитивно-рекурсивной функции
int recurFunc(int, int);
  
// Аналитическая формула F(x1, x2) = x2 + (x1 * (x1 - 1)) / 2
// Ввод: шаг и параметр
// Вывод: значние по аналитической функции
int analiticFunc(int, int);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    wcout << L"Схема рекурсии:" << endl;
    wcout << L"1) f(0, x2) = x2" << endl;
    wcout << L"2) f(x1 + 1, x2) = x1 + f(x1, x2)" << endl;
    wcout << L"Аналитическая формула: f(x1, x2) = x2 + (x1 * (x1 - 1)) / 2" << endl << endl;

    bool keepWorking = true;

    while (keepWorking) {
        int x1, x2;
        bool flag = true;

        wcout << L"Введите x1: ";
        cin >> x1;
        wcout << L"Введите x2: ";
        cin >> x2;

        if (x1 < 0) {
            wcout << L"Ошибка: x1 должен быть неотрицательным." << endl;
            wcout << L"Повторить ввод? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                wcout << L"Программа завершена." << endl;
                keepWorking = false;
            }
            flag = false;
        }

        if (keepWorking && flag) {
            wcout << endl << L"--- Рекурсивное вычисление ---" << endl;
            int recurResult = recurFunc(x1, x2);

            int analiticResult = analiticFunc(x1, x2);
            wcout << endl << L"--- Сравнение с аналитической формулой ---" << endl;
            wcout << L"f(" << x1 << L"," << x2 << L") по рекурсии = " 
                  << recurResult << endl;
            wcout << L"f(" << x1 << L"," << x2 << L") по аналитической формуле = " 
                  << analiticResult << endl;

            (recurResult == analiticResult) ? wcout << L"Результаты совпадают!" : wcout << L"Результаты НЕ совпадают!";
            wcout << endl;

            wcout << endl << L"Повторить ввод? (y/n): ";
            char again; cin >> again;
            if (again == 'n' || again == 'N') {
                wcout << L"Программа завершена." << endl;
                keepWorking = false;
            }
        }
    }
    return 0;
}

int recurFunc(int x1, int x2) {
    int result;
    if (x1 == 0) {
        wcout << L"f(0," << x2 << L") = " << x2 << endl;
        result = x2;
    } else {
        int prev = recurFunc(x1 - 1, x2);
        result = (x1 - 1) + prev;
        wcout << L"f(" << x1 << L"," << x2 << L") = h(" 
              << (x1 - 1) << L", f(" << (x1 - 1) << L"," 
              << x2 << L"), " << x2 << L") = h(" << (x1 - 1) 
              << L"," << prev << L"," << x2 << L") = " 
              << result << endl;
    }
    return result;
}

int analiticFunc(int n, int x) {
    int result = x + (n * (n - 1)) / 2;
    return result;
}