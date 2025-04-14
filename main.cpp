/*************************************************************
 * ДЗ-2 Примитивная рекурсия (Вариант 2.10)
 * Студент: Батычков Вячеслав Геннадьевич, КТбо1-7
 * Программа: Реализует вычисление функции f(x1, x2),
 * полученной из базовых функций:
 *   g(x) = x
 *   h(x, y, z) = x + y
 * по схеме примитивной рекурсии:
 *   1) f(0, x2) = x2
 *   2) f(x1 + 1, x2) = x1 + f(x1, x2)
 * Аналитическая формула (для x1 ≥ 0):
 *   f(x1, x2) = x2 + (x1 * (x1 - 1)) / 2
 *
 *************************************************************/

#include <iostream>
#include <clocale>
#include <windows.h>
#include <string>

using namespace std;

// Структура для хранения результата рекурсивной функции и её пошагового описания
struct RecurResult {
    int value;       // Итоговое вычисленное значение f(x1, x2)
    wstring trace;   // Пошаговый "след" вычислений
};

// Примитивно-рекурсивная реализация функции F(n, x)
// Ввод: шаг рекурсии и параметр
// Вывод: занчение примитивно-рекурсивной функции
RecurResult recurFunc(int x1, int x2);
 
// Аналитическая формула F(x1, x2) = x2 + (x1 * (x1 - 1)) / 2
// Ввод: шаг и параметр
// Вывод: значние по аналитической функции
int analiticFunc(int n, int x);

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
        wcout << L"Введите x1: ";
        cin >> x1;
        wcout << L"Введите x2: ";
        cin >> x2;

        if (x1 < 0) {
            wcout << L"Ошибка: x1 должен быть неотрицательным." << endl;
            wcout << L"Повторить ввод? (y/n): ";
            char choice; cin >> choice;
            if (choice == 'n' || choice == 'N') {
                wcout << L"Программа завершена." << endl;
                keepWorking = false;
            }
        } else {
            RecurResult recursionResult = recurFunc(x1, x2);
            wcout << L"--- Пошаговое вычисление ---" << endl;
            wcout << recursionResult.trace << endl;
            int analiticResult = analiticFunc(x1, x2);

            wcout << L"--- Сравнение с аналитической формулой ---" << endl;
            wcout << L"f(" << x1 << L"," << x2 << L") по рекурсии = "
                  << recursionResult.value << endl;
            wcout << L"f(" << x1 << L"," << x2 << L") по аналитической формуле = "
                  << analiticResult << endl;

            (recursionResult.value == analiticResult) ? wcout << L"Результаты совпадают!" << endl : wcout << L"Результаты НЕ совпадают!" << endl;
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

RecurResult recurFunc(int x1, int x2) {
    if (x1 == 0) {
        RecurResult res;
        res.value = x2;
        res.trace = L"f(0," + to_wstring(x2) + L") = " + to_wstring(x2) + L"\n";
        return res;
   }

    RecurResult prev = recurFunc(x1 - 1, x2);
    RecurResult curr;
    curr.value = (x1 - 1) + prev.value;
    curr.trace = prev.trace
        + L"f(" + to_wstring(x1) + L"," + to_wstring(x2) + L") = h("
        + to_wstring(x1 - 1) + L", f("
        + to_wstring(x1 - 1) + L"," + to_wstring(x2) + L"), "
        + to_wstring(x2) + L") = h("
        + to_wstring(x1 - 1) + L"," + to_wstring(prev.value) + L","
        + to_wstring(x2) + L") = " + to_wstring(curr.value) + L"\n";

    return curr;
}

int analiticFunc(int x1, int x2) {
    return x2 + (x1 * (x1 - 1)) / 2;
}