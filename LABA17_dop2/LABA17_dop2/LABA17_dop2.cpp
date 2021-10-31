﻿// LABA17_dop2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дан массив из 10 элементов. Первые 4 элемента упорядочить по возрастанию, последние 4 по убыванию.

#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] > a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}
void revBubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 7; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] < a[j])
			{
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
}

int main()
{
	int arr[10], i;
	for (i = 0; i < 10; i++)
		arr[i] = rand() % (61) - 20;
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	cout << endl;
	bubbleSort(arr, 4);
	revBubbleSort(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	cout << endl;
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
