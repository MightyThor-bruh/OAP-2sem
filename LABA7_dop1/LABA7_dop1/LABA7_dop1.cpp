// LABA7_dop1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Создать стек с целочисленным информационным полем. Заполнить его длинами строк, считанных из файла. Распечатать 
//на экране содержимое стека. Указать номер и длину последней самой короткой строки файла.

#include <iostream> //Доп 
#include<fstream>
using namespace std;

struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};
int kolmas[5];
void show(Stack* myStk);         //прототип
int pop(Stack* myStk);           //прототип
void push(int x, Stack* myStk);  //прототип
void filecheck(Stack* myStk);

int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk->head = NULL;       //инициализация первого элемента	


	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - с файла" << endl;
		cout << "5 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: " << endl;
			cin >> choice;
			push(choice, myStk);
			break;
		case 2: choice = pop(myStk);
			if (choice != -1)
				cout << "Извлеченный элемент: " << choice << endl;
			break;
		case 3: cout << "Весь стек: " << endl;
			show(myStk);
			break;
		case 4: filecheck(myStk); break;
		case 5: return 0;
			break;
		}
	}
	return 0;
}
void push(int x, Stack* myStk)
{
	Stack* e = new Stack;
	e->data = x;
	e->next = myStk->head;
	myStk->head = e;

}
int pop(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;
	}
	else
	{
		Stack* e = myStk->head;
		int a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;
		return a;
	}
}

void show(Stack* myStk)
{
	Stack* e = myStk->head;
	int a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data;
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}
void filecheck(Stack* myStk)
{
	int i = 0, kol;
	int mint = 1000, minnum = 0;
	string str;
	ifstream file("text.txt");
	while (file >> str)
	{
		kol = str.length();
		push(kol, myStk);
		kolmas[i] = kol;
		if (kol < mint)
		{
			mint = kol;
			minnum = i;
		}
		i++;
	}
	show(myStk);
	cout << "Длина самой короткой строки: " << mint << endl;
	cout << "Номер самой короткой строки в файле: " << minnum + 1 << endl;
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
