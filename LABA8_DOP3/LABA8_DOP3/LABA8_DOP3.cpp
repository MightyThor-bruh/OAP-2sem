// LABA8_DOP3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Содержимое текстового файла f, разделенное на строки, переписать в текстовый файл g, перенося при этом в конец 
//каждой строки все входящие в нее цифры (с сохранением исходного взаимного порядка, как среди цифр, так и среди 
//остальных литер строки). Использовать очереди.

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
struct Node1 {
	char Letter;
	Node1* next;
};

struct Queue1 {
	Node1* head;
	Node1* tail;
};

struct Node2 {
	char Number;
	Node2* next;
};

struct Queue2 {
	Node2* head;
	Node2* tail;
};
void CreateQueue1(Queue1* Liter) {
	Liter->head = new Node1();
	Liter->head->next = NULL;
	Liter->tail = Liter->head;
}

void CreateQueue2(Queue2* Number) {
	Number->head = new Node2();
	Number->head->next = NULL;
	Number->tail = Number->head;
}
void symbol(Queue1* Liter, Queue2* Number) {
	ifstream file("f.txt");
	string Temp;
	char Symbol;
	int TempInt;
	getline(file, Temp);
	cout << "Исходная строка:" << Temp << endl;
	for (int i = 0; i < Temp.length(); i++) {
		Symbol = Temp[i];
		if ((Symbol >= 97 && Symbol <= 122) || (Symbol >= 65 && Symbol <= 90)) {
			Liter->tail->next = new Node1;
			Liter->tail = Liter->tail->next;
			Liter->tail->Letter = Symbol;
			Liter->tail->next = NULL;
		}
		if (Symbol >= 48 && Symbol <= 57) {
			Number->tail->next = new Node2();
			Number->tail = Number->tail->next;
			Number->tail->Number = Symbol;
			Number->tail->next = NULL;
		}
	}
	Node1* Temp1 = Liter->head->next;
	Node2* Temp2 = Number->head->next;
	cout << "Буквы:" << endl;
	while (Temp1) {
		cout << Temp1->Letter;
		Temp1 = Temp1->next;
	}
	cout << endl;
	cout << "Цифры:" << endl;
	while (Temp2) {
		cout << Temp2->Number;
		Temp2 = Temp2->next;
	}
	cout << endl;
	file.close();

	ofstream File("g.txt");
	Temp1 = Liter->head->next;
	Temp2 = Number->head->next;
	while (Temp1) {
		File << Temp1->Letter;
		Temp1 = Temp1->next;
	}
	while (Temp2) {
		File << Temp2->Number;
		Temp2 = Temp2->next;
	}
	File.close();
	cout << "Строка записана в файл" << endl;
}
int main() {
	setlocale(LC_ALL, "rus");
	Queue1 Q1;
	Queue2 Q2;
	CreateQueue1(&Q1);
	CreateQueue2(&Q2);
	symbol(&Q1, &Q2);
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
