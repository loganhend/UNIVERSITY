#include<iostream>
#include<vector>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include<map>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include<fstream>
#include<sstream>

using namespace std;
ifstream input("students.txt", ios::app);//открываем файл для чтения
ofstream output("students.txt", ios::app);//открываем файл для записи

struct Book//создание структуры
{
	int number = 0;//номер книги
	string name; //название
	string author; //автор
	string publisher; //издание
	int publishYear = 0;//год издания
	int pages = 0;//кол-во страниц
};
Book list[100];//создаем список из таких структур на 100 элементов

void Remove()
{
	if (remove("students.txt") != 0)
		cout << "0" << endl;//if error occurs
	else
		cout << "1" << endl;//if the file is successfully deleted.
}



void Create()
{
	cout << "Create" << endl;
	cout << "Enter ammount of books" << endl;
	int n = 0;
	cin >> n;//количество книг

	if (input.is_open())//проверка на открытие файла
	{
		cout << "File is opened" << endl << "Enter book's name, author's name, publisher name, publishing year, number of pages" << endl;
		output << endl;//добавление пустой строки для удобсвта
		for (int m = 0; m < n; m++)
		{
			cout << "Book #" << m + 1 << endl;//m+1 из-за нумерации в массиве структур list от 0
			cin >> list[m].name >> list[m].author >> list[m].publisher >> list[m].publishYear >> list[m].pages;
			list[m].number = m + 1;//m+1 из-за нумерации в массиве структур list от 0
			output << list[m].number << "." << list[m].name << "." << list[m].author << "." << list[m].publisher << "." << list[m].publishYear << "." << list[m].pages << endl;//заносим все значения в файл. Через точку для удобства
		}
	}
	else {
		cout << "error!" << endl;//если файл не открылся
	}
}

void Read()
{
	ifstream input("students.txt", ios::app);
	cout << "Read" << endl;
	if (!input.is_open())//проверка на открытие файла(может не открываться)
	{
		cout << "File is not opened" << endl;//если файл не открылся
	}
	else
	{
		cout << "File is opened" << endl;//если файл открылся
		int m = 0;
		string line, studname;
		int number, year;
		string name, author, pages, publisher;
		while (getline(input, line))//поочередно считываем строки из документа(потока) и записывем их в перемнную line
		{
			if (m > 0) {
				istringstream text_stream(line);//перемнную line тоже преобразуем в поток 
				text_stream >> number;//из потока line считываем номер студента
				cout << "Book #" << number << endl;//выводим
				text_stream.ignore(1);//пропускаем в потоке один символ(точку)

				getline(text_stream, name, '.');
				cout << "Name: " << name << endl;//выводим

				getline(text_stream, author, '.');//из потока считываем значение имени и записываем в переменную author. Считываем до точки
				cout << "Author: " << author << endl;//выводим

				getline(text_stream, publisher, '.');//из потока считываем значение имени и записываем в переменную publisher. Считываем до точки
				cout << "Publisher: " << publisher << endl;//выводим

				text_stream >> year;//из потока line считываем год publishing'a
				cout << "Publishing year: " << year << endl;//выводим
				text_stream.ignore(1);//пропускаем в потоке один символ(точку)

				text_stream >> pages;//из потока line считываем количество страниц
				cout << "Pages: " << pages << endl;//выводим
				cout << "############################################" << endl;
			}
			m++;
		}
	}
	input.close();//закрываем поток
}

void Change()
{
	cout << "Change" << endl;

	ifstream input("students.txt", ios::app);
	int m = -1;
	string line;
	while (getline(input, line))//считаем количество книг на данный момент(количество строк)
	{
		m++;
	}

	cout << "Book #" << m + 1 << endl;
	cin >> list[m].name >> list[m].author >> list[m].publisher >> list[m].publishYear >> list[m].pages;
	list[m].number = m + 1;//m+1 из-за нумерации в массиве структур list от 0
	output << list[m].number << "." << list[m].name << "." << list[m].author << "." << list[m].publisher << "." << list[m].publishYear << "." << list[m].pages << endl;//заносим все значения в файл. Через точку для удобства
	input.close();//закрываем поток. Важно закрыть, чтобы все добавления сохранились (могут потеряться, если не закрыть)
}

void Quick_Sort(int begin, int end)
{
	int left, right;
	string x;
	Book _x;
	left = begin;
	right = end;
	x = list[(left + right) / 2].author;
	do {
		while (list[left].author < x)  left++;
		while (x < list[right].author) right--;
		if (left <= right) {
			_x = list[left];
			list[left] = list[right];
			list[right] = _x;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) Quick_Sort(begin, right);
	if (left < end) Quick_Sort(left, end);
}


void Sort()
{
	ifstream input("students.txt", ios::app);
	string name, publisher, author, author_search;
	string line;
	int year, group, prog, math, number;
	std::cout << "Enter the year of publishing" << endl;
	int n = 0;
	std::cin >> n;

	std::cout << "Enter the way of sorting 1)Direct selection 2)Quick_sort" << endl;
	int q = 0;
	std::cin >> q;

	int  m = -1;
	while (std::getline(input, line))
	{
		istringstream text_stream(line);
		text_stream >> list[m].number;
		number = list[m].number;
		text_stream.ignore(1);

		std::getline(text_stream, name, '.');
		list[m].name = name;

		std::getline(text_stream, author, '.');
		list[m].author = author;

		std::getline(text_stream, publisher, '.');
		list[m].publisher = publisher;

		text_stream >> list[m].publishYear;
		text_stream.ignore(1);

		text_stream >> list[m].pages;
		m++;
	}


	if (q == 1)
	{

		int min;
		Book temp; // для поиска минимального элемента и для обмена
		for (int i = 0; i < m - 1; i++)
		{
			min = i; // запоминаем индекс текущего элемента
			// ищем минимальный элемент чтобы поместить на место i-ого
			for (int j = i + 1; j < m - 1; j++)  // для остальных элементов после i-ого
			{
				if (list[j].author < list[min].author) // если элемент меньше минимального,
					min = j;       // запоминаем его индекс в min
			}
			temp = list[i];      // меняем местами i-ый и минимальный элементы
			list[i] = list[min];
			list[min] = temp;
		}
;
		for (int i = 0; i < m - 1; i++) 
		{
			min = i;

			for (int j = i + 1; j < m; j++)
				if (list[min].author > list[j].author)
						min = j;

			if (min != i) 
			{				// Переставляем элементы
				temp = list[min];    
					
				list[min] = list[i];     
					
				list[i] = temp;
			}
		}




		cout << "Books by author:" << endl;
		for (auto g : list)
			if (g.publishYear >= n)
			{
				cout << "Book " << g.name << " has number " << g.number << " it's author " << g.author << " it's publishing year " << g.publishYear << endl;
			}
	}

	if (q == 2)
	{
	Quick_Sort(0, number - 1);
	for (auto g : list)
		if (g.publishYear >= n)
		{
			cout << "Book " << g.name << " has number " << g.number << " it's author " << g.author << " it's publishing year " << g.publishYear << endl;
		}
	}

}


void Search_basic()
{
	ifstream input("students.txt", ios::app);
	string name, publisher, author, author_search;
	string line;
	int year, group, prog, math, m;
	double average;
	cout << "Enter author to find" << endl;
	cin >> author_search;

	m = 0;
	while (getline(input, line))
	{
		while (getline(input, line))
		{
			istringstream text_stream(line);
			text_stream >> list[m].number;
			text_stream.ignore(1);

			getline(text_stream, name, '.');
			list[m].name = name;

			getline(text_stream, author, '.');
			list[m].author = author;

			getline(text_stream, publisher, '.');
			list[m].publisher = publisher;

			text_stream >> list[m].publishYear;
			text_stream.ignore(1);

			text_stream >> list[m].pages;
			m++;
		}
	}

	m++;
	input.close();

	vector<int> base;

	for (int i = 0; i < m-1; i++) {
		if (list[i].author == author_search)
		{ 
			base.push_back(i);
		}
	}

	for (int w : base) {
		cout << "Book #" << list[w].number << endl;//выводим
		cout << "Name: " << list[w].name << endl;//выводим
		cout << "Author: " << list[w].author << endl;//выводим
		cout << "Publisher: " << list[w].publisher << endl;//выводим
		cout << "Publishing year: " << list[w].publishYear << endl;//выводим
		cout << "Pages: " << list[w].pages << endl;//выводим
		cout << "############################################" << endl;
	}
}

void Search_binar()
{
	ifstream input("students.txt", ios::app);
	string name, publisher, author, author_search;
	string line;
	int year, group, prog, math, number;
	cout << "Enter author to find" << endl;
	cin >> author_search;

	int  m = -1;
	while (std::getline(input, line))
	{
		istringstream text_stream(line);
		text_stream >> list[m].number;
		number = list[m].number;
		text_stream.ignore(1);

		std::getline(text_stream, name, '.');
		list[m].name = name;

		std::getline(text_stream, author, '.');
		list[m].author = author;

		std::getline(text_stream, publisher, '.');
		list[m].publisher = publisher;

		text_stream >> list[m].publishYear;
		text_stream.ignore(1);

		text_stream >> list[m].pages;
		m++;
	}

	Quick_Sort(0, number - 1);
		
	vector<int> base;

	int i= 0, j , ind,hub;
	j = m - 1;
	while (i < j) {
		ind = (i + j) / 2;
		if (list[ind].author < author_search) i = ind + 1;
		else  j = ind;
	}
	hub = i;

		cout << "Book #" << list[hub].number << endl;//выводим
		cout << "Name: " << list[hub].name << endl;//выводим
		cout << "Author: " << list[hub].author << endl;//выводим
		cout << "Publisher: " << list[hub].publisher << endl;//выводим
		cout << "Publishing year: " << list[hub].publishYear << endl;//выводим
		cout << "Pages: " << list[hub].pages << endl;//выводим
	
}


int main()
{
	cout << "Choose option: 1) Create; 2) Read; 3) Change;  5) Exit 6)Sort by characteristic 7)Basic search 8)Binar search ;" << endl;
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
		case 6:
			Sort();
			break;
		case 7:
			Search_basic();
			break;
		case 8:
			Search_binar();
			break;
		case 9:
			Remove();
			break;
		}
		cout << "Choose option: 1) Create; 2) Read; 3) Change; 5) Exit 6)Sort by characteristic 7)Basic search 8)Binar search;" << endl;
		cin >> v;
	}
	return 0;
}