#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

fstream st; //Хедер fstream предоставляет функционал для считывания данных из файла и для записи в файл. В целом он очень похож на хедер iostream, который работает с консолью, поскольку консоль это тоже файл.создаем объект класса ifstream - st

struct Student //создаем структуру и указываем, какие поля в ней будут
{
	int number = 0;
	char name[32] = "";//имя - переменная типа чар на 32 элемента
	int birthYear = 0;//думаю, перевести названия переменных дальше не сложно)(по стандарту записываем 0)
	long int groupNumber = 0;//(по стандарту записываем 0)
	double mathMark = 0;//(по стандарту записываем 0)
	double progMark = 0;//(по стандарту записываем 0)
	double averageMark = 0;//(по стандарту записываем 0)
};
Student list[100];//изначально создаем структуру на 100 студентов

void Remove()//функция, ничего не возвращает
{
	if (remove("students.txt") != 0)
		cout << "0" << endl;
	else
		cout << "1" << endl;
}

void Create()//функция, ничего не возвращает, только изменяет структуру
{
	cout << "Create" << endl;
	cout << "Enter ammount of students" << endl;
	int n = 0;
	cin >> n;
	st.open("students.txt", fstream::out | fstream::app);//
	if (!st.is_open())//проверяем, открылся ли файл
	{
		cout << "File is not opened" << endl;//если нет, выдаем ошибку
	}
	else//если файл открылся, работаем
	{
		cout << "File is opened" << endl << "Enter students name, birth year, group number, prog mark, math mark" << endl;
		for (int m = 0; m < n; m++)//создаем столько студентов, сколько записали выше
		{
			cout << "Student #" << m + 1 << endl;//m+1, чтобы правильный номер выводился, нумерация с 0
			cin >> list[m].name >> list[m].birthYear >> list[m].groupNumber >> list[m].progMark >> list[m].mathMark;
			list[m].averageMark = (list[m].progMark + list[m].mathMark) / 2;
			list[m].number = m + 1;//m+1, чтобы правильный номер выводился, нумерация с 0
			st.write((char*)&list[m], sizeof(Student));//
		}
	}
	st.close();//закрываем поток
}

void Read()//функция, ничего не возвращает, только читает элементы структуры
{
	cout << "Read" << endl;
	st.open("students.txt", fstream::in);//
	if (!st.is_open())//выше то же самое было
	{
		cout << "File is not opened" << endl;
	}
	else
	{
		cout << "File is opened" << endl;
		int m = 0;
		while (st.read((char*)&list[m], sizeof(Student)))
		{
			if (list[m].number != 0)//проверка, чтобы в структуре были студенты
			{
				cout << list[m].name << " " << list[m].birthYear << " " << list[m].groupNumber << " " << list[m].progMark << " " << list[m].mathMark << " " << list[m].averageMark << endl;
				m++;
			}
			else//если студентов нет, прерываем
			{
				break;
			}
		}
	}
	st.close();//закрываем поток
}

void Change()//функция, ничего не возвращает, только чизменяет элементы элементов структуры
{
	int p = 0;
	cout << "Change" << endl;
	cout << "1) Clear file; 2) Change file;" << endl;
	cin >> p;
	switch (p)//проверяем, какой вариант выбрал пользователь
	{
	case 1:
		cout << "Clear file" << endl;
		st.open("students.txt", fstream::out);
		st.close();
		break;
	case 2:
		int n = 0;
		int v = 0;
		int m = 0;
		cout << "Enter # of student to edit" << endl;
		cin >> n;
		cout << "Enter parametr to edit 1) name; 2) birth year; 3)group number; 4)prog mark; 5)math mark" << endl;
		cin >> v;
		st.open("students.txt", fstream::in);
		while (st.read((char*)&list[m], sizeof(Student)))
		{
			if (list[m].number != 0)
			{
				m++;
				continue;
			}
			else
			{
				break;
			}
		}
		st.close();
		st.open("students.txt", fstream::out);
		switch (v)
		{
		case 1:
			cin >> list[n - 1].name;
			break;
		case 2:
			cin >> list[n - 1].birthYear;
			break;
		case 3:
			cin >> list[n - 1].groupNumber;
			break;
		case 4:
			cin >> list[n - 1].progMark;
			list[n - 1].averageMark = (list[n - 1].progMark + list[n - 1].mathMark) / 2;
			break;
		case 5:
			cin >> list[n - 1].mathMark;
			list[n - 1].averageMark = (list[n - 1].progMark + list[n - 1].mathMark) / 2;
			break;
		}
		for (int i = 0; i < m; i++)
		{
			st.write((char*)&list[i], sizeof(Student));
		}
		st.close();
		break;
	}
}

void Ex()
{
	st.open("students.txt", fstream::in);
	int m = 0;
	while (st.read((char*)&list[m], sizeof(Student)))
	{
		if (list[m].number != 0)
		{
			m++;
			continue;
		}
		else
		{
			break;
		}
	}
	st.close();
	long int group = 0;
	cout << "Enter group number" << endl;
	cin >> group;
	for (int i = 0; i < m; i++)
	{
		if (group == list[i].groupNumber)
		{
			if (list[i].averageMark > 8)
			{
				cout << list[i].name << " " << list[i].birthYear << " " << list[i].groupNumber << " " << list[i].progMark << " " << list[i].mathMark << " " << list[i].averageMark << endl;
			}
		}
	}
}

int main()
{
	cout << "Choose option: 1) Create; 2) Read; 3) Change; 4) Individual variant; 5) Exit;" << endl;
	int v = 0;
	cin >> v;
	while (v != 5)
	{
		switch (v)
		{
		case 1:
		Create();
			break;
		case 2:
		Read();
			break;
		case 3:
		Change();
			break;
		case 4:
		Ex();
			break;
		case 6:
		Remove();
			break;
		}
		cout << "Choose option: 1) Create; 2) Read; 3) Change; 4) Individual variant; 5) Exit;" << endl;
		cin >> v;
	}

    system("PAUSE");
    return 0;
}