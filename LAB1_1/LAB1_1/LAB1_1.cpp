﻿// LAB1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

double f1(double x)
{
	return pow(x, 3) + x - 2; /* уравнение 1*/
}
double f2(double x)
{
	return sin(x) + 0.3; /* уравнение 2*/
}
double fun(double(*f)(double), double a, double b) /* функция для решения метода дихотомии*/
{
	double x, e = pow(10, -3);
	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0)
		{
			b = x;
		}
		else a = x;
	}
	return x;
}
void main()
{
	double c;
	c = fun(f1, 0, 1); /* при отделении корней а=0, в=1*/
	cout << "koren 1 funkcii= " << c << endl;
	c = fun(f2, -2, 0); /* при отделении корней а=-2, в=0*/
	cout << "koren 2 funkcii= " << c << endl;
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