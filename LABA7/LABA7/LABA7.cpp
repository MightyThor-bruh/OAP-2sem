// LABA7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Разработать функцию, которая удаляет первый повторяющийся элемент стека.

#include <iostream> //Основа 15 варик (доделать клир и ввод-вывод)
using namespace std;

struct Stack
{
	int data;
	Stack* head;
	Stack* next;
};

void show(Stack* myStk);
int pop(Stack* myStk);
void push(int x, Stack* myStk);
void povchk();
void removeMoreThan100(Stack* myStk);

int arr[10], k = 0, pos2, elem;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack;
	myStk->head = NULL;

	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в стек" << endl;
		cout << "2 - Извлечение элемента из стека" << endl;
		cout << "3 - Вывод стека" << endl;
		cout << "4 - Удаление повторяющегося элемента" << endl;
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
		case 5: return 0;
			break;
		case 4: removeMoreThan100(myStk); break;
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
	arr[k] = x;
	k++;
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

void povchk() {
	int pov = 0, pos = 0;
	for (int i = k; i > 0; i--)
	{
		for (int j = k; j > 0; j--)
		{
			if (arr[i] == arr[j])
			{
				pov++;
				pos = i;
			}
		}
	}
	pos2 = k - pos;
	elem = arr[pos];
}
void removeMoreThan100(Stack* myStk)
{
	int z = 1;
	Stack* e = myStk->head;
	Stack* pointer = myStk->head;
	povchk();
	if (myStk->head == NULL)
	{
		cout << "Стек пуст\n";
		return;
	}
	if (myStk->head->data == elem)
	{
		myStk->head = myStk->head->next;
		cout << "Удален элемент " << e->data << endl;
		delete e;
		return;
	}
	else
	{
		do {
			Stack* temp;
			if (pointer->data == elem && z == 2)
			{
				temp = pointer;
				e->next = pointer->next;
				pointer = pointer->next;
				cout << "Удален элемент " << temp->data << endl;
				delete temp;
				return;
			}
			z++;
			e = pointer;
			pointer = pointer->next;
		} while (pointer != NULL);

	}
	cout << "Такого элемента нет\n";
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
