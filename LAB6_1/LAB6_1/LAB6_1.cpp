// LAB6_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Создать список, содержащий элементы целого типа. Найти сумму положительных элементов, у которых последняя
//цифра 7 или выдать сообщение, что таких элементов нет.

#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;

struct list {
	int number;
	list* next;
};

void enter(list*& pfirst, int num);
int del(list*& pf, int num);
int search(list*& pfirst, int num);
void out(list*& pfirst);
void file_out(list*& pfirst);
void file_in(list*& pfirst);
int summa(list*& pfirst);
void list_unique(list* pfirst) {
    list* t, * p, * i, * prev;
    for (p = pfirst; p != NULL; p = p->next) {
        prev = p;
        for (i = p->next; i != NULL; ) {
            if (i->number == p->number) {
                t = prev->next = i->next;
                free(i);
                i = t;
                continue;
            }
            prev = i;
            i = i->next;
        }
    }
}

int op, k = 0;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list* first = 0;
	int num, sym;
    cout << "Введите:" << endl;
    cout << "1-для добавления элемента" << endl;
    cout << "2-для вывода в консольное окно" << endl;
    cout << "3-для удаления элемента" << endl;
    cout << "4-для поиска элемента" << endl;
    cout << "5-для записи информации в файл" << endl;
    cout << "6-для чтения данных из файла" << endl;
    cout << "7-для вывод суммы" << endl;
    cout << "8-для выхода" << endl;
    cin >> op;
    do
    {
        switch (op)
        {
        case 1: cout << "Введите число: "; cin >> num;
            enter(first, num); 
            break;
        case 2: out(first); break;
        case 3: cout << "Введите число, которое хотите удалить: "; cin >> num; 
            if (del(first, num)) {
                cout << "Число удалено" << endl;
                cout << "Следующее действие?" << endl;
                cin >> op;
            }
            else {
                cout << "Число не найдено" << endl;
                cout << "Следующее действие?" << endl;
                cin >> op;
            } break;
        case 4: cout << "Введите число, которое хотите проверить: "; cin >> num; 
            if (search(first, num)) {
                cout << "Число найдено" << endl;
                cout << "Следующее действие?" << endl;
                cin >> op;
            }
            else {
                cout << "Число не найдено" << endl;
                cout << "Следующее действие?" << endl;
                cin >> op;
            }
            break;
        case 5: file_out(first); break;
        case 6: file_in(first); break;
        case 7: sym =0;
            if (sym = summa(first)) {

                cout << "Cумма нужных элементов: " << sym << endl;
                cout << "Следующее действие?" << endl;
                cin >> op;
            }

            else { cout << "Таких элементов нет" << endl;
            cout << "Следующее действие?" << endl;
            cin >> op;
            }break;
        }
    } while (op != 8);
    system("pause");
}
void enter(list *&pf, int num) {
    list* pNew = new list;
    if (pNew != NULL)
    {
        pNew->number = num;
        pNew->next = *&pf;
        pf = pNew;
    }
    k++;
    cout << "Число добавлено в список" << endl;
    cout << "Следующее действие?" << endl;
    cin >> op;
}
void out(list*& pf) {
    if (pf == NULL)
        cout << "Список пуст";
    else
    {
        cout << "Список: " << endl;
        while (pf != NULL) {
            cout << pf->number << "-->";
            pf = pf->next;
        }
        cout << "NULL" << endl;
    }
    cout << "Число добавлено в список" << endl;
    cout << "Следующее действие?" << endl;
    cin >> op;
}
int search(list*& pf, int num){
    list* previous, * current;
    if (num == pf->number)
        return num;
    else {
        previous = pf;
        current = pf->next;
        while (current != NULL && current->number != num)
        {
            previous = current;
            current = current->next;
        }
        if (current != NULL)
            return num;
    }
    return 0;
}
int del(list*& pf, int num) {
    list* previous, * current, * temp;
    if (num == pf->number) {
        temp = pf;
        pf = pf->next;
        delete temp;
        return num;
    }
    else{
        previous = pf;
        current = pf->next;
        while (current != NULL && current->number != num)
        {
            previous = current;
            current = current->next;
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return num;
        }
    }
    return 0;
}
void file_out(list*& pf) {
    list* temp = pf;
    ofstream out("Out.txt");
    if (out.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp != NULL) {
        out << temp->number;
        out << "-->";
        temp = temp->next;
    }
    out << "NULL";
    out.close();
    cout << "Следующее действие?" << endl;
    cin >> op;
}
void file_in(list*& pf) //Считывание из файла
{
    char k[20];
    ifstream fin("Out.txt");
    if (fin.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    fin.read(k, sizeof(k));
    for (int i = 0; i < (int)strlen(k); i++)
    {
        if (k[i] == 'М')
            break;
        cout << k[i];
    }
    cout << endl;
    fin.close();
    cout << "Следующее действие?" << endl;
    cin >> op;
}
int summa(list*& pfirst) {
    int f = 0, sym = 0;
    list * nextN = pfirst;
    while (nextN != NULL) {
        if ((nextN->number % 10) == 7 && nextN->number > 0)
        {
            sym = sym + nextN->number;
            nextN = nextN->next;
            f++;
        }
        else
            nextN = nextN->next;
        
    }
    if (f == 0)
        return 0;
    else
        return sym;
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
