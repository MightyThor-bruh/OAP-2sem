// LABA11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дан указатель p1 на корень непустого дерева. Написать функцию, в которой для каждого из уровней данного 
//дерева, начиная с нулевого, вывести сумму значений вершин, находящихся на этом уровне. Считать, что глубина дерева не превосходит 10.

#include<iostream>
using namespace std;
struct Tree
{
	int key;
	char text[10];
	Tree* Left, * Right;
};
Tree* makeTree(Tree* Root);//создание нового дерева
Tree* list(int i, char* s);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, char* s);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 
void delAll(Tree* t);
int p1(Tree* Root, int level); //мое задание
Tree* Root = NULL; 	//указатель корня
int sum[10]; //для суммы значений вершин
void main()
{
	int key, choice;
	Tree* rc; char s[10];
	bool exit = false;
	while (exit != true)
	{
		cout << "1-make a tree\n2-add the element\n3-find with help of the key\n4-delete the element\n5-show the tree\n6-clear the tree\n7-my task\n8-exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1: {Root = makeTree(Root); break; }
		case 2: {
			cout << "enter the key" << endl;
			cin >> key;
			cout << endl;
			cout << "Enter the text" << endl;
			cin >> s;
			insertElem(Root, key, s); break;
		}
		case 3: {
			cout << "Enter the key" << endl;
			cin >> key;
			rc = search(Root, key);
			cout << "A word, which what found is ";
			puts(rc->text); break;
		}
		case 4: {
			cout << "Enter the key to delete" << endl;
			cin >> key;
			Root = delet(Root, key); break;
		}
		case 5: {
			if (Root->key >= 0)
			{
				cout << "The tree is under 90 C left" << endl;
				view(Root, 0);
			}
			else cout << "The tree is empty" << endl; break;
		}
		case 6: {
			delAll(Root); break;
		}
		case 7: {
			for (int i = 0; i < 10; i++) {
				sum[i] = 0;
			}
			int max_level = p1(Root, 0);
			for (int level = 0; level <= max_level; level++)
			{
				cout << level << " " << sum[level] << endl;
			}
			break;
		}
		case 8: {exit = true; break; }
		}

	}
}
Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key; char s[10];
	cout << "The end of entrance-num<0\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Enter the key: "; cin >> key; //ввод ключа
		cout << "Enter the word: "; cin >> s; //ввод слова
		Root = list(key, s);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nEnter the key: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Enter the word: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}

Tree* list(int i, char* s)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 10; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s)  //Добавление нового элемента
{
	Tree* Prev = t;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key, s);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}


Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nThis key isn't find");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nDelete the element with the key  " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "there isn't such element\n";
	return rc;
}

void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//вывод левого поддерева
	}

}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

int p1(Tree* t, int level) //Сумма ключей узлов по уровням
{
	if (t)
	{
		int max_level_right = 0, max_level_left = 0;
		max_level_right = p1(t->Right, level + 1);	//идём в правое поддерево
		max_level_left = p1(t->Left, level + 1);	//идём в левое поддерево
		sum[level] += t->key;
		if (max_level_left >= max_level_right) {
			return max_level_left;
		}
		else {
			return max_level_right;
		}
	}
	else {
		return (level - 1);
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
