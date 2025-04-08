/*************************************************************
 * ДЗ-2 Примитивная рекурсия (Вариант 2.10)
 *
 * Студент: Батычков Вячеслав Геннадьевич, Группа: КТбо1-7
 *
 * Программа: Реализует вычисление функции f(n, x),
 * полученной из базовых функций:
 *   g(x) = x 
 *   h(x, y, z) = x + y
 * по схеме примитивной рекурсии.
 *
 * Используются два способа:
 * 1) Рекурсивное определение (recurFunc).
 * 2) Аналитическая формула (analiticFunc).
 *************************************************************/

#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

// Примитивно-рекурсивная реализация функции F(n, x)
// Ввод: шаг рекурсии и параметр
// Вывод: занчение примитивно-рекурсивной функции
int recurFunc(int, int);
  
// Аналитическая формула F(n, x) = x + (n * (n - 1)) / 2
// Ввод: шаг и параметр
// Вывод: значние по аналитической функции
int analiticFunc(int, int);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);      
    setlocale(LC_ALL, "Russian");

    int n, x;
    wcout << L"Введите n: ";
    cin >> n;
    wcout << L"Введите x: ";
    cin >> x;

    int recurResult    = recurFunc(n, x);
    int analiticResult = analiticFunc(n, x);

    wcout << L"f(" << n << L", " << x << L") по рекурсии = " << recurResult << endl;
    wcout << L"f(" << n << L", " << x << L") по аналитической формуле = " << analiticResult << endl;

    (recurResult == analiticResult) ? wcout << L"YES" : wcout << L"NO";
    wcout << endl;
    return 0;
}

int recurFunc(int n, int x) {
    return (n == 0) ? x : ((n - 1) + recurFunc(n - 1, x));
}

int analiticFunc(int n, int x) {
    return x + (n * (n - 1)) / 2;
}

