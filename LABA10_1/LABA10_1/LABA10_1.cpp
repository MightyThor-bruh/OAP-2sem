﻿// LABA10_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//1 основное

#include<iostream>  
using namespace std;

int recf(int x);

int main()
{
	setlocale(LC_ALL, "RUS");
	int x;
	cout << "Введите число x: "; cin >> x;
	cout << recf(x);
}
int recf(int x)
{
	if (x > 100)
		return x + 10;
	else
		return recf(recf(x + 4));
	cout << x;
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