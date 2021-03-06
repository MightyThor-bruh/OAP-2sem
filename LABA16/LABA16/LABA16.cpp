// LABA16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Ввести массивы А и В. В массив С перенести те элементы массива А, которые меньше максимального эле-мента 
//массива В. Массив С отсортировать по убыванию, используя алгоритмы сортировок: «пузырек», сорти-ровка Хоара.

#include<iostream>
#include<time.h>
using namespace std;
#define HOR

void hoarasort(int* a, int first, int last)
{

	int i = first, j = last;
	double tmp, x = a[(first + last) / 2];

	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i < j);

	if (i < last)
		hoarasort(a, i, last);
	if (first < j)
		hoarasort(a, first, j);
}
void buble(int c[], int cnt) {
	int i, j, t;
	for (i = 0; i < cnt; i++)
	{
		for (j = cnt - 1; j >= i; j--)
		{
			if (c[j - 1] > c[j])
			{
				t = c[j - 1];
				c[j - 1] = c[j];
				c[j] = t;
			}

		}
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int n, i, t = 0, cnt = 0, j;;
	cout << "Введите размерность массива: "; cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (i = 0; i < n; i++) {
		a[i] = rand() % 20001 - 10000;
		b[i] = rand() % 20001 - 10000;
	}
	for (i = 0; i < n; i++)
		if (b[i] > t)
			t = b[i];
	for (i = 0; i < n; i++)
		if (a[i] < t)
			cnt++;
	int* c = new int[cnt];
	int* d = new int[cnt];
	for (i = 0; i < n; i++)
		if (a[i] < t) {
			c[i] = a[i];
			d[i] = a[i];
		}
	cout << endl;
	for (i = 0; i < cnt; i++)
		cout << c[i] << " ";
	cout << endl;
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	t1 = clock();
	buble(c, cnt);
	t2 = clock();
	cout << "Время сортировки пузырьком в миллисекундах: " << t2 - t1 << endl;
	for (i = 0; i < cnt; i++)
		cout << c[i] << " ";
	cout << endl;
	t3 = clock();
	hoarasort(d, 0, cnt - 1);
	t4 = clock();
	cout << "Время сортировки методом Хора в миллисекундах: " << t4 - t3 << endl;
	for (i = 0; i < cnt; i++)
		cout << d[i] << " ";
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
