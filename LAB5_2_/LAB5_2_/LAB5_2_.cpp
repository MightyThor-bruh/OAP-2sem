// LAB5_2_.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Справочник абитуриента. Наименование вуза, адрес, перечень специальностей, конкурс прошлого года по каждой 
//специальности, размер оплаты при договорном обучении. Поиск минимального конкурса по дан-ной специальности.

#include<iostream>	
#include<Windows.h>
using namespace std;
#define size 4

enum Espec {
	Isit = 1, Poit, Poibms, Deivi
}spec;
struct univ {
	char name[4];
	char adres[12];
	int scepial = spec;
	unsigned int free_ball : 12;
	unsigned int cost_learn : 12;
};
univ arr[size];
int i = 0;
int oper;

void input();
void remove();
void output();
void search();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Что вы хотите сделать?\n";
	cout << "1 - Ввод данных в структуру\n";
	cout << "2 - Удаление данных из структуры\n";
	cout << "3 - Вывод данных на экран\n";
	cout << "4 - Поиск баллам\n";
	cout << "5 - Для завершения работы\n";
	cin >> oper;
	do {
		switch (oper)
		{
		case 1:  input(); break;
		case 2:  remove(); break;
		case 3:  output(); break;
		case 4:  search(); break;
		}
	} while (oper != 5);
	system("pause");
}

void input()
{
	if (i < size)
	{
		int free_ball, cost_learn;
		cout << "Введите название уничерситета(Абривеатура): ";
		cin >> arr[i].name;
		cout << "Введите улицу, на которой находится университет: ";
		cin >> arr[i].adres;
		cout << "Введите специальность(1 - Исит, 2 - ПОИТ, 3 - ПОИБМС, 4 - ДЭиВИ): ";
		cin >> arr[i].scepial;
		cout << "Введите проходной балл для бюджетной формы обучения: ";
		cin >> free_ball;
		arr[i].free_ball = free_ball;
		cout << "Введите стоимость оплаты на контрактной форме обучения: ";
		cin >> cost_learn;
		arr[i].cost_learn = cost_learn;
		i++;
		cout << "-------------------------------------------" << endl;
	}
	else
		cout << "Введено максимальное кол-во строк!\n";
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void output()
{
	if (i > 0)
	{
		int n;
		cout << "Введите номер элемента, который хотите вывести: "; cin >> n;
		n--;
		cout << "Название университета: ";
		for (i = 0; i < 4; i++)
		{
			cout << arr[n].name[i];
		}
		cout << endl;
		cout << "Адрес: " << arr[n].adres << endl;
		cout << "Специальность: ";
		switch (arr[n].scepial) {
		case Isit: cout << "ИСиТ" << endl;
			break;
		case Poit: cout << "ПОИТ" << endl;
			break;
		case Poibms: cout << "ПОиБМС" << endl;
			break;
		case Deivi: cout << "ДЭиВИ" << endl;
			break;
		}
		cout << "Проходной балл: " << arr[n].free_ball << endl;
		cout << "Стоимость обучения по контракту: " << arr[n].cost_learn << endl;
	}
	else
		cout << "Недостаточно информации для вывода!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void remove()
{
	if (i > 0)
	{
		int d;
		cout << "Номер записи, которую нужно удалить: "; cin >> d;
		for (int de1 = (d - 1); de1 < i; de1++)
			arr[de1] = arr[de1 + 1];
		i--;
		cout << "Запись удалена" << endl;
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
}
void search()
{
	int test, free_ball;
	if (i > 0)
	{
		cout << "Введите ваш балл за ЦТ: "; cin >> test;
		for (int k = 0; k < i; k++)
		{
			free_ball = arr[i].free_ball;
			if (free_ball <= test)
			{
				cout << "Название университета: ";
				for (int z = 0; z < 4; z++)
				{
					cout << arr[i].name[z];
				}
				cout << endl;
				cout << "Адрес: " << arr[i].adres << endl;
				cout << "Специальность: ";
				switch (arr[i].scepial) {
				case Isit: cout << "ИСиТ" << endl;
					break;
				case Poit: cout << "ПОИТ" << endl;
					break;
				case Poibms: cout << "ПОиБМС" << endl;
					break;
				case Deivi: cout << "ДЭиВИ" << endl;
					break;
				}
				cout << "Проходной балл: " << arr[i].free_ball << endl;
				cout << "Стоимость обучения по контракту: " << arr[i].cost_learn << endl;
			}
		}
	}
	else
		cout << "Недостаточно информации!" << endl;
	cout << "Cледующее действие?" << endl;
	cin >> oper;
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
