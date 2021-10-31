// LABA17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Сортировка подсчетом, сортировка выбором, сортировка слиянием

#include<iostream>
#include <ctime>
using namespace std;

void countSort(int in[], int out[], int size)
{
	int i, j, count;
	for (i = 0; i < size; ++i)
	{
		for (count = 0, j = 0; j < size; ++j)
			if (in[j] < in[i] || (in[j] == in[i] && i < j))
				count++;
		out[count] = in[i];
	}
}
void selectionSort(int data[], int lenD)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i < lenD; i++) {
		j = i;
		for (int k = i; k < lenD; k++) {
			if (data[j] > data[k]) {
				j = k;
			}
		}
		tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
}

void Merger(int arr[], int lo, int  mi, int hi) {
	int* temp = new int[hi - lo + 1];
	int i = lo, j = mi + 1;
	int k = 0;
	while (i <= mi && j <= hi) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mi)
		temp[k++] = arr[i++];
	while (j <= hi)
		temp[k++] = arr[j++];
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];
	delete[]temp;
}
void MergeSortHelper(int arr[], int lo, int hi) {
	int mid;
	if (lo < hi) {
		mid = (lo + hi) >> 1;
		MergeSortHelper(arr, lo, mid);
		MergeSortHelper(arr, mid + 1, hi);
		Merger(arr, lo, mid, hi);
	}
}
void MergeSort(int arr[], int arr_size) {
	MergeSortHelper(arr, 0, arr_size - 1);
}

int main()
{
	int n;
	clock_t t1 = 0, t2 = 0;
	cout << "Введите кол-во элементов: "; cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	int* d = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 20001 - 10000;
		c[i] = rand() % 20001 - 10000;
		d[i] = rand() % 20001 - 10000;
	}
	t1 = clock();
	countSort(a, b, n);
	t2 = clock();
	cout << t2 - t1 << endl;
	t1 = clock();
	selectionSort(c, n);
	t2 = clock();
	cout << t2 - t1 << endl;
	t1 = clock();
	MergeSort(d, n);
	t2 = clock();
	cout << t2 - t1 << endl;
	for (int i = 0; i < n; i++)
		cout << d[i] << ' ';
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
