// LABA9_DOP2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Каждый элемент списка студентов содержит фамилию, имя, отчество, год рождения, курс, номер группы, оценки по 
//пяти предметам. Упорядочить студентов по курсу, причем студенты одного курса должны располагаться в алфавитном порядке. 
//Найти средний балл каждой группы по каждому предмету. Определить самого старшего студента и самого младшего студентов. 
//Для каждой группы найти лучшего с точки зрения успеваемости студента.

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

struct Address
{
	string name;
	int groupId;
	int math;
	int chemistry;
	int it;
	int biology;
	int pi;
	int berthyear;
	Address* next;
	Address* prev;
};
void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}
Address* setElement()
{
	Address* temp = new  Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	getline(cin, temp->name);
	getline(cin, temp->name);
	cout << "Введите оценки: \n";
	cout << "биология ";
	cin >> temp->biology;
	cout << "математика ";
	cin >> temp->math;
	cout << "химия ";
	cin >> temp->chemistry;
	cout << "информатика ";
	cin >> temp->it;
	cout << "физкультура ";
	cin >> temp->pi;
	cout << "Введите год рождения";
	cin >> temp->berthyear;
	cout << "Введите группу";
	cin >> temp->groupId;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << endl << " Оценки: биология " << t->biology << " математика " << t->math << " физкульт " << t->pi << " информатика " << t->it << " химия " << t->chemistry << endl << "Год рождения " << t->berthyear << "\nГруппа" << t->groupId << endl;
		t = t->next;
	}
	cout << "" << endl;
}
void delet(string name, Address** phead, Address** plast)
{
	struct Address* t = *phead;
	while (t)
	{
		if (name == t->name)  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
	}
}
void sortList(Address** phead, Address** plast) {
	Address* pheadP = NULL;
	Address* plastP = NULL;

	struct Address* tp = *phead;
	while (tp)
	{
		Address* tpNext = tp->next;
		insert(tp, &pheadP, &plastP);
		tp = tpNext;
	}

	struct Address* t = *phead;
	while (t)
	{
		struct Address* sec = t;
		while (sec) {
			if (sec->name < t->name) {
				Address tmpl = *t;
				t->name = sec->name;
				t->berthyear = sec->berthyear;
				t->groupId = sec->groupId;
				t->biology = sec->biology;
				t->math = sec->math;
				t->pi = sec->pi;
				t->it = sec->it;
				t->chemistry = sec->chemistry;

				sec->name = tmpl.name;
				sec->berthyear = tmpl.berthyear;
				sec->groupId = tmpl.groupId;
				sec->biology = tmpl.biology;
				sec->math = tmpl.math;
				sec->pi = tmpl.pi;
				sec->it = tmpl.it;
				sec->chemistry = tmpl.chemistry;
			}
			sec = sec->next;
		}
		t = t->next;
	}
	cout << "Отсортированный список: \n";
	outputList(&pheadP, &plastP);
}
void averMarks(Address** phead, Address** plast) {

	struct Address* t = *phead;
	vector<int> groups;
	while (t)
	{
		int counter = 0;
		for (size_t i = 0; i < groups.size(); i++)
		{
			if (groups[i] != t->groupId) counter++;
		}
		if (counter == groups.size()) groups.push_back(t->groupId);
		t = t->next;
	}

	for (size_t i = 0; i < groups.size(); i++)
	{
		int colOfStudents = 0;
		t = *phead;
		int mathVal = 0;
		int chemistryVal = 0;
		int biologyVal = 0;
		int piVal = 0;
		int itVal = 0;
		while (t)
		{
			if (groups[i] == t->groupId) {
				colOfStudents++;
				mathVal += t->math;
				chemistryVal += t->chemistry;
				biologyVal += t->biology;
				piVal += t->pi;
				itVal += t->it;
			}
			t = t->next;
		}
		cout << "Средние баллы группы N" << groups[i] << ": \n";
		cout << "биология " << biologyVal / (float)colOfStudents << " математика " << mathVal / (float)colOfStudents << " физкульт " << piVal / (float)colOfStudents << " информатика " << itVal / (float)colOfStudents << " химия " << chemistryVal / (float)colOfStudents << endl;
	}
}

void stat(Address** phead, Address** plast) {

	struct Address* t = *phead;
	vector<int> groups;
	while (t)
	{
		int counter = 0;
		for (size_t i = 0; i < groups.size(); i++)
		{
			if (groups[i] != t->groupId) counter++;
		}
		if (counter == groups.size()) groups.push_back(t->groupId);
		t = t->next;
	}

	for (size_t i = 0; i < groups.size(); i++)
	{
		int bestScore = 0;
		Address bestStudent;
		t = *phead;

		while (t)
		{
			if (groups[i] != t->groupId) {
				t = t->next;
				continue;
			}

			int rscore = 0;
			rscore += t->math;
			rscore += t->chemistry;
			rscore += t->biology;
			rscore += t->pi;
			rscore += t->it;

			if (rscore > bestScore) {
				bestScore = rscore;
				bestStudent = *t;
			}
			t = t->next;
		}

		cout << "Лучший студент группы N" << groups[i] << " это " << bestStudent.name << endl;
	}

	t = *phead;
	int maxYear = t->next->berthyear;
	int minYear = 0;
	Address oldest;
	Address yangest;
	while (t)
	{
		if (t->berthyear < maxYear) {
			maxYear = t->berthyear;
			oldest = *t;
		}
		if (t->berthyear > minYear) {
			minYear = t->berthyear;
			yangest = *t;
		}
		t = t->next;
	}
	cout << "Самый младший студент - " << yangest.name << " " << yangest.berthyear << " год\n";
	cout << "Самый старший студент - " << oldest.name << " " << oldest.berthyear << " год\n";
}

int main(void)
{
	int m, a;
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		cout << endl;
		cout << "1. Ввод" << endl;
		cout << "2. Удаление" << endl;
		cout << "3. Вывод на экран" << endl;
		cout << "4. Упорядочить" << endl;
		cout << "5. Ср. баллы" << endl;
		cout << "6. Статистика студентов" << endl;
		cout << "7. Выход" << endl;
		cout << endl;
		cin >> a;
		switch (a)
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  string dname;
			cout << "Введите имя: ";
			getline(cin, dname);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4:
			sortList(&head, &last);
			break;
		case 5:
			averMarks(&head, &last);
			break;
		case 6:
			stat(&head, &last);
			break;
		case 7:  exit(0);
		default: exit(1);
		}
	}
	system("pause");
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
