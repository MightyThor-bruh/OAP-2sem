// LABA8_DOP1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;
struct Item
{
	int data;
	Item* next;
};
Item* head, * tail;

bool isNull(void)
{
	return (head == NULL);
}
void deletFirst()
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		Item* p = head;
		head = head->next;
		delete p;
	}
}
void getFromHead()
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
		cout << "Начало = " << head->data << endl;
}
void insertToQueue(int x)
{
	Item* p = new Item;
	p->data = x;
	p->next = NULL;
	Item* v = new Item;
	Item* p1 = new Item;
	Item* p2 = new Item;
	int i = 0;
	if (isNull())
		head = tail = p;
	else
	{
		p2 = head; p1 = head;
		while (p1 != NULL)
		{
			if (i == 1)
			{
				if (x > p1->data)
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				p2 = p2->next;
			}
			else
			{
				if (x >= p1->data)
				{
					v->data = x;
					v->next = p1;
					head = v;
					return;
				}
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail->next = p;
			tail = p;
		}
	}
}
void printQueue()
{
	Item* p = new Item;
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		cout << "Очередь = ";
		p = head;
		while (!isNull())
		{
			if (p != NULL)
			{
				cout << p->data << " "; cout << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clrQueue()
{
	while (!isNull()) deletFirst();
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1, z; head = NULL; tail = NULL;
	while (choice != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - получить элемент с начала" << endl;
		cout << "3 - извлечь элемент с начала" << endl;
		cout << "4 - вывести элементы" << endl;
		cout << "5 - очистить очередь" << endl;
		cout << "0 - выход" << endl;
		cout << "Выберите действие "; cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите элемент: "; cin >> z;
			insertToQueue(z); printQueue(); break;
		case 2: getFromHead(); break;
		case 3: deletFirst(); break;
		case 4: printQueue(); break;
		case 5: clrQueue(); break;
		}
	}
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
