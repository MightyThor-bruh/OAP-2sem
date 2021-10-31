﻿// LABA10_DOP2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дано n различных натуральных чисел (n = 5). Напечатать все перестановки этих чисел.

#include <iostream>	
using namespace std;
const int n = 5;
int a[n];

void perm(int k) {
    int i, j, t, p;
    for (i = 0; i < n - k; i++) {
        if (k < n - 2)
            perm(k + 1); 
        else { 
            for (p = 0; p < n; p++) cout << " " << a[p];
            cout << endl;
        }
        t = a[k];
        for (j = k + 1; j < n; j++) a[j - 1] = a[j];
        a[j - 1] = t;
    }
}

int main(void)
{
    int i;
    for (i = 0; i < n; i++) a[i] = i + 1;
    perm(0);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
