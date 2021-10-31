// LAB4_DOP1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля: ФИО студента,
//число экзаменов, полученные оценки. Определить функции для обработки отдельного объекта (например, для проверки, 
//сданы ли все экзамены на 4 и 5). Написать функцию для обработки массива структур. В результате обработки требуется вычислить 
//характеристику успеваемости студентов, то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах. 

#include <iostream>
using namespace std;
void input(int size);
void output();
void find(char lastName[]);
typedef struct Exams
{
	char surname[16];
	char name[16];
	char secondname[16];
	char count[3];
	float mark;
} STUD;
int number, markplus = 0, markminus = 0; float per = 0; FILE *f; errno_t err;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice; char surname[16];
	do
	{
		cout << "\n1. Ввод данных с клавиатуры и запись в файл\n";
		cout << "2. Вывод данных из файла\n";
		cout << "3. Поиск по фамилии\n";
		cout << "4. Процент учащихся со средним баллом >=4.0\n";
		cout << "0. Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество студентов, данные о которых хотите ввести: ";
			cin >> number;
			input(number);
			cout << endl; break;
		case 2: output(); break;
		case 3: {  cout << "Введите фамилию: ";
			cin >> surname;
			find(surname); break;
		}
		case 4: { per = ((float)markplus / (float)markminus) * 100;
			cout << "На данный момент процент учащихся со средним баллов больше или равно 4 - " << per << "%." << endl;
			break;
		}
		case 0: exit(0);  break;
		}
	} while (choice != 0);
}

void input(int size)
{
	STUD buf = { ' ', ' ' };
	if (!fopen_s(&f, "exams.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Фамилия: "; 	cin >> buf.surname;
			cout << "Имя: "; 	cin >> buf.name;
			cout << "Отчество: "; 	cin >> buf.secondname;
			cout << "Количество экзаменов: "; 	cin >> buf.count;
			cout << "Средний балл: "; 	cin >> buf.mark;
			cout << endl;
			if (buf.mark >= 4) { markplus++; }
			else { markminus++; };
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
	if (!fopen_s(&f, "exams.txt", "rb"))
	{
		cout << "\nФамилия    Имя    Отчество    Количество экзаменов    Средний балл\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.surname << "\t    " << buf.name << "\t    " << buf.secondname << "\t    " << buf.count << "\t    " << buf.mark << endl;
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

void find(char lastName[16])
{
	bool flag = false;  STUD buf;
	if (!fopen_s(&f, "exams.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.surname) == 0)   //сравнение строк
			{
				cout << "\nФамилия    Имя    Отчество    Количество экзаменов    Средний балл\n";
				cout << buf.surname << "\t    " << buf.name << "\t    " << buf.secondname << "\t    " << buf.count << "\t    " << buf.mark << endl;
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
