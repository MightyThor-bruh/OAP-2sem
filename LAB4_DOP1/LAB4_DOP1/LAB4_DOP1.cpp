﻿// LAB4_DOP1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения, номер поезда, время отправления. 
//Написать программу, выполняющую ввод с клавиатуры данных в массив, состоящий из восьми элементов типа TRAIN 
//(записи должны быть размещены в алфавитном порядке по названиям пунктов назначения); вывод на экран информации 
//о поездах, отправляющихся после введенного с клавиатуры времени (если таких поездов нет, то вывести сообщение об этом).

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct
{
    string station;
    int number;
    int time;
}   TRAIN, * PTRAIN;

int main()
{
    vector<TRAIN> v;
    TRAIN t;

    // Ввод
    ifstream ifs("in.txt", ios::in);
    for (int i = 0; i < 6; ++i)
    {
        ifs >> t.station;
        ifs >> t.number;
        ifs >> t.time;

        v.push_back(t);
    }
    ifs.close();

    string name;
    cout << "enter station: ";
    cin >> name;

    // Вывод
    bool c = false;
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (name == v[i].station)
        {
            cout << "---------------------------------------" << endl;
            cout << "STATION: " << v[i].station << endl;
            cout << "NUMBER: " << v[i].number << endl;
            cout << "TIME: " << v[i].time << endl;
            cout << "---------------------------------------" << endl;
            c = true;
        }
    }
    if (!c)
        cout << "not found!" << endl;
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
