// LABA9_DOP1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дополнить проект, разработав функцию удаление списка и функцию подсчет числа элементов списка 

#include <iostream>

using namespace std;

struct Element                   // Элемент списка 
{
	Element* Prev;                // указатель на предыдущий элемент 
	Element* Next;                // указатель на следующий элемент 
	void* Data;                  //  данные  
	Element(Element* prev, void* data, Element* next)
	{
		Prev = prev;
		Data = data;
		Next = next;
	}
	Element* GetNext()            // получить следующий
	{
		return Next;
	};
	Element* GetPrev()            // получить предыдущий  
	{
		return Prev;
	};
};
//-----------------------------------------------------------
struct Object                     // Блок управления списком 
{
	Element* Head;                 // указатель на начало списка
	Object()
	{
		Head = NULL;
	};
	Element* GetFirst()            // получить первый элемент списка
	{
		return Head;
	};
	Element* GetLast();            // получить последний элемент списка
	Element* Search(void* data);   // найти  первый элемент по данным 
	bool Insert(void* data);       // добавить элемент в начало
	bool InsertEnd(void* data);    // добавить в конец 
	bool Delete(Element* e);       // удалить по адресу элемента 
	bool Delete(void* data);       // удалить первый по данным
	bool DeleteList();		    // очистить список 
	void PrintList(void(*f)(void*));
	void PrintList(void(*f)(void*), Element*);
	int CountList();
	bool DeleteDouble();
};
Object Create();                   // создать список

struct Person
{
	char name[20];
	int age;
	Person* next;
};

void print(void* b)       //Функция используется при выводе 
{
	Person* a = (Person*)b;
	cout << a->name << "  " << a->age << endl;
}

bool Object::Insert(void* data)           // Вставка в начало
{
	bool rc = 0;
	if (Head == NULL)
	{
		Head = new Element(NULL, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(NULL, data, Head));
		rc = true;
	}
	return rc;
}
//-----------------------------------------------------------
Element* Object::Search(void* data)    // Найти заданный элемент
{
	Element* rc = Head;
	while ((rc != NULL) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*))     // Вывод
{
	Element* e = Head;
	while (e != NULL)
	{
		f(e->Data);
		e = e->GetNext();
	};
}
//-----------------------------------------------------------
void Object::PrintList(void(*f)(void*), Element* e)
{
	f(e->Data);
}
//-----------------------------------------------------------
bool  Object::Delete(Element* e)    // Удалить по ссылке
{
	bool rc = 0;
	if (rc = (e != NULL))
	{
		if (e->Next != NULL)
			e->Next->Prev = e->Prev;
		if (e->Prev != NULL)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}
//-----------------------------------------------------------
bool Object::Delete(void* data)      // Удалить по значению
{
	return Delete(Search(data));
};
//-----------------------------------------------------------
Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != NULL)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}
//-----------------------------------------------------------
Object Create()
{
	return *(new Object());
}
//-----------------------------------------------------------
bool Object::DeleteList() {

	Element* tmpl = Head;
	while (tmpl != NULL) {
		Element* nx = tmpl->GetNext();
		delete tmpl;
		tmpl = nx;
	}
	Head = NULL;
	return true;
}
//-----------------------------------------------------------
int Object::CountList() {
	int count = 0;

	Element* tmpl = Head;
	while (tmpl != NULL) {
		++count;
		tmpl = tmpl->GetNext();
	}

	return count;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	Person a1 = { "Петров", 20 };
	Person a2 = { "Сидоров", 25 };
	Person a3 = { "Иванов", 47 };
	bool rc;
	Object L1 = Create();   // создание списка с именем L1
	L1.Insert(&a1);
	L1.Insert(&a2);
	L1.Insert(&a3);
	L1.PrintList(print);
	Element* e = L1.Search(&a3);
	Person* aa = (Person*)e->Data;
	cout << "Найден элемент= " << aa->name << endl;
	rc = L1.Delete(&a2);
	if (rc == true) cout << "Удален элемент" << endl;
	cout << "Размер списка - " << L1.CountList() << endl;
	cout << "Список:" << endl;
	L1.PrintList(print);

	L1.DeleteList();
	cout << "Очищен список\n";
	L1.PrintList(print);
	cout << "Размер списка - " << L1.CountList() << endl;
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
