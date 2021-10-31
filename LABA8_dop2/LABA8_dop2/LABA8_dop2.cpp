// LABA8_dop2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Создать очередь с вещественными числами, и заполнить ее с клавиатуры. Выполнить циклический сдвиг элементов 
//в очереди так, чтобы в ее начале был расположен наибольший элемент.

#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
	float Number;
	Node* next;
};

struct Queue {
	int size = 0;
	Node* head;
	Node* tail;
};
void CreateQueue(Queue* Q) {
	Q->head = new Node();
	Q->head->next = NULL;
	Q->tail = Q->head;
	Q->size = 0;
}
void AddElem(Queue* Q) {
	float newElem;
	cout << "Введите элемент:" << endl;
	cin >> newElem;
	cout << endl;
	Q->tail->next = new Node();
	Q->tail = Q->tail->next;
	Q->tail->Number = newElem;
	Q->tail->next = NULL;
	Q->size++;
}
int OutQueue(Queue* Q) {
	if (Q->head == Q->tail) {
		cout << "Очередь пуста" << endl;
		return 0;
	}
	else {
		Node* Temp = Q->head->next;
		cout << endl;
		while (Temp) {
			cout << Temp->Number << endl;
			Temp = Temp->next;
		}
	}
}
int Shift(Queue* Q) {
	if (Q->head == Q->tail) {
		cout << "Очередь пуста" << endl;
		return 0;
	}
	else {
		float max = 0;
		Node* Temp = Q->head->next;
		while (Temp) {
			if (Temp->Number > max)
				max = Temp->Number;
			Temp = Temp->next;
		}
		cout << "Наибольшее значение:" << max << endl;
		cout << "Очередь со сдвигом:" << endl;
		Temp = Q->head;
		Temp->Number = max;
		cout << Temp->Number << endl;
		while (Temp) {
			if (Temp->Number != max) cout << Temp->Number << endl;
			Temp = Temp->next;
		}
		cout << endl << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Queue t;
	int choice;
	CreateQueue(&t);
	for (;;)
	{
		cout << "Выберите команду:" << endl;
		cout << "1 - Добавление элемента в очередь" << endl;
		cout << "2 - Вывод очереди" << endl;
		cout << "3 - Циклический сдвиг" << endl;
		cout << "4 - Выход" << endl;
		cin >> choice;
		switch (choice)
		{

		case 1:
			AddElem(&t);
			break;
		case 2:
			OutQueue(&t);
			break;
		case 3:
			Shift(&t);
			break;
		case 4:
			return 0;
			break;

		}
	}
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
