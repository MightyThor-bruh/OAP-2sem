// LAB5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Ф.И.О., дата поступления, специальность, группа, факультет, средний балл. Выбор по среднему баллу. 
//Дату поступления реализовать с помощью битового поля, факультет с помощью перечисления.

#include <iostream>
#include <string>
using namespace std;
const int n = 100;

enum Faculty {
	Poit = 1, Daivi, Mobilki, Isit
};

struct Date
{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 5;
};

struct Student {
	string Last_name;
	string First_name;
	string Father_name;
	Date date_now;
	string spec;
	string group;
	int fac; // сделали поле для запоминания факультета
	double sr_ball;
};

void table_in(Student* A, int& t);
void find(Student* A, int t, double user_mark);
int main()
{
	int t = 0;
	Student A[n];
	bool exit = false;
	table_in(A, t);
	int k;//for menu
	while (exit != true)
	{
		cout << "What work would you like?" << endl;
		cout << "Menu: " << endl;
		cout << "1-Show table" << endl;
		cout << "2-Delete the element" << endl;
		cout << "3-Find the average mark" << endl;
		cout << "4-Exit" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
		{
			cout << "Last Name\tName\tFather name\tDay\t\tSpec\tGroup\tBall" << endl;
			for (int i = 0; i < t; i++)
			{
				cout << A[i].Last_name << "\t";
				cout << A[i].First_name << "\t";
				cout << A[i].Father_name << "\t";
				cout << A[i].date_now.day << "." << A[i].date_now.month << "." << "20" << A[i].date_now.year << "\t";
				cout << A[i].spec << "\t";
				cout << A[i].group << "\t";
				switch (A[i].fac)
				{
				case Poit: cout << "Poit" << "\t"; break;
				case Daivi: cout << "Daivi" << "\t"; break;
				case Mobilki: cout << "Mobilki" << "\t"; break;
				case Isit: cout << "Isit" << "\t"; break;
				}
				cout << A[i].sr_ball << endl;
			}
			break;
		}
		case 2:
		{
			string Last_name;
			cout << "Enter the Last name" << endl;
			cin >> Last_name;
			int ind;
			for (int i = 0; i < t; i++)
			{
				if (Last_name == A[i].Last_name)
				{
					ind = i;
					break;
				}
			}
			A[ind].Last_name = A[t - 1].Last_name;
			A[ind].First_name = A[t - 1].First_name;
			A[ind].Father_name = A[t - 1].Father_name;
			A[ind].date_now.day = A[t - 1].date_now.day;
			A[ind].date_now.month = A[t - 1].date_now.month;
			A[ind].date_now.year = A[t - 1].date_now.year;
			A[ind].spec = A[t - 1].spec;
			A[ind].group = A[t - 1].group;
			A[ind].sr_ball = A[t - 1].sr_ball;
			t--;

			break;
		}
		case 3: {
			cout << "Enter the average mark" << endl;
			double user_mark;
			cin >> user_mark;
			find(A, t, user_mark);
			break;
		}
		case 4: {
			exit = true;
			break;
		}
		}
	}
	system("pause");
	return 0;
}
void table_in(Student* A, int& t)
{
	int i = 0, act;
	do
	{
		cout << "Enter Last name" << endl;
		cin >> A[i].Last_name;
		cout << "Enter First name" << endl;
		cin >> A[i].First_name;
		cout << "Enter Father name" << endl;
		cin >> A[i].Father_name;

		int number;
		cout << "Enter day" << endl;
		cin >> number;
		A[i].date_now.day = number;
		cout << "Enter month" << endl;
		cin >> number;
		A[i].date_now.month = number;
		cout << "Enter year" << endl;
		cin >> number;
		A[i].date_now.year = number;
		cout << "Enter specialisation" << endl;
		cin >> A[i].spec;
		cout << "Enter the number of group" << endl;
		cin >> A[i].group;
		cout << "Enter the faculty" << endl;

		string fac;
		cin >> fac;
		if (fac == "Poit") {
			A[i].fac = Poit;
		}
		else if (fac == "Daivi")
		{
			A[i].fac = Daivi;
		}
		else if (fac == "Mobilki")
		{
			A[i].fac = Mobilki;
		}
		else if (fac == "Isit")
		{
			A[i].fac = Isit;
		}
		cout << "Enter sr ball" << endl;
		cin >> A[i].sr_ball;
		i++;
		t = i;

		cout << "if you want to continue enter 1 else 0" << endl;
		cin >> act;
	}

	while (act == 1);

}
void find(Student* A, int t, double user_mark) {
	cout << "Last Name\tName\tFather name\tDay\t\tSpec\tGroup\tBall" << endl;
	for (int i = 0; i < t; i++)
	{
		if (A[i].sr_ball == user_mark)
		{
			cout << A[i].Last_name << "\t";
			cout << A[i].First_name << "\t";
			cout << A[i].Father_name << "\t";
			cout << A[i].date_now.day << "." << A[i].date_now.month << "." << "20" << A[i].date_now.year << "\t";
			cout << A[i].spec << "\t";
			cout << A[i].group << "\t";
			cout << A[i].fac << "\t";
			cout << A[i].sr_ball;
			cout << endl;
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
