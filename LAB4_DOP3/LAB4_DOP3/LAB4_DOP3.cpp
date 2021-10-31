// LAB4_DOP3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Определить структуру для представления информации о наличии санаторных путевок, содержащую следующие поля: 
//Название санатория, Место расположения, Лечебный профиль, Количество путевок. Представить введенные данные 
//в виде таблицы, сгруппировав их по лечебным профилям санаториев. В пределах каждой группы данные отсортировать 
//по названиям санаториев. Организовать поиск информации и вывод результатов. 

#include <iostream>
using namespace std;

void input(int size);
void output();
void finds(char lastName[]);
void findh(char lastHeal[]);

typedef struct Exams
{
	char name[16];
	char place[16];
	char prof[16];
	int num;
} STUD;
int number; FILE *f; errno_t err;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice; char name[16], prof[16];
	do
	{
		cout << "\n1. Ввод данных с клавиатуры и запись в файл\n";
		cout << "2. Вывод данных из файла\n";
		cout << "3. Поиск по названию санатория\n";
		cout << "4. Поиск по лечебному профилю\n";
		cout << "0. Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество санаториев, данные о которых хотите ввести: ";
			cin >> number;
			input(number);
			cout << endl; break;
		case 2: output(); break;
		case 3: {  cout << "Введите название: ";
			cin >> name;
			finds(name); break;
		}
		case 4: { cout << "Введите лечебный профиль: ";
			cin >> prof;
			findh(prof); break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "travel.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Название санатория: "; 	cin >> buf.name;
			cout << "Местонахождение: "; 	cin >> buf.place;
			cout << "Лечебный профиль: "; 	cin >> buf.prof;
			cout << "Количество оставшихся путевок: "; 	cin >> buf.num;
			cout << endl;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}
}

void output()
{
	STUD buf;
	if (!fopen_s(&f, "travel.txt", "rb"))
	{
		cout << "\nНазвание санатория      Местонахождение      Лечебный профиль     Количество оставшихся путевок\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.name << "\t    " << buf.place << "\t    " << buf.prof << "\t    " << buf.num << endl;
			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void finds(char lastName[16])
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "travel.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.name) == 0)   //сравнение строк
			{
				cout << "\nНазвание санатория     Местонахождение    Лечебный профиль   Количество оставшихся путевок\n";
				cout << buf.name << "\t    " << buf.place << "\t    " << buf.prof << "\t    " << buf.num << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
}

void findh(char lastHeal[16])
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "travel.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastHeal, buf.prof) == 0)   //сравнение строк
			{
				cout << "\nНазвание санатория     Местонахождение    Лечебный профиль   Количество оставшихся путевок\n";
				cout << buf.name << "\t    " << buf.place << "\t    " << buf.prof << "\t    " << buf.num << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "Ничего не найдено\n";
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
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
