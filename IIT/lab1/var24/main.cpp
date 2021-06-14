#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>
#include"llists.h"

using namespace std;
ifstream input("list.txt", ios::app);
ofstream output("list.txt", ios::app);

/*
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
	cout << "Enter ammount of students" << endl;
	int n = 0;
	cin >> n;

	if (input.is_open())
	{
		cout << "File is opened" << endl << "Enter students name, birth year, group number, prog mark, math mark" << endl;
		output << endl;
		for (int m = 0; m < n; m++)
		{
			cout << "Student #" << m + 1 << endl;
			cin >> list[m].name >> list[m].birthYear >> list[m].groupNumber >> list[m].progMark >> list[m].mathMark;
			list[m].averageMark = (list[m].progMark + list[m].mathMark) / 2;
			list[m].number = m + 1;
			output << list[m].number << "." << list[m].name << "." << list[m].birthYear << "." << list[m].groupNumber << "." << list[m].progMark << "." << list[m].mathMark << "." << list[m].averageMark << endl;
		}
	}
	else {
		cout << "error!" << endl;
	}
}

void Read()
{
	ifstream input("students.txt", ios::app);
	cout << "Read" << endl;
	if (!input.is_open())
	{
		cout << "File is not opened" << endl;
	}
	else
	{
		cout << "File is opened" << endl;
		int m = 0;
		string line, studname;
		int number, year, group, prog, math;
		double average;
		while (getline(input, line))
		{
			if (m > 0) {
				istringstream text_stream(line);
				text_stream >> number;
				cout << "Student #" << number << endl;
				text_stream.ignore(1);
				getline(text_stream, studname, '.');
				cout << "Name: " << studname << endl;
				text_stream >> year;
				cout << "Birth year: " << year << endl;
				text_stream.ignore(1);
				text_stream >> group;
				cout << "Group: " << group << endl;
				text_stream.ignore(1);
				text_stream >> prog;
				cout << "Programming mark: " << prog << endl;
				text_stream.ignore(1);
				text_stream >> math;
				cout << "Math mark: " << math << endl;
				text_stream.ignore(1);
				text_stream >> average;
				cout << "Average " << studname << "'s mark: " << average << endl;
				cout << "############################################" << endl;
			}
			m++;
		}
	}
	input.close();
}
*/

int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	do
	{
		cout << "1. Add element" << endl;
		cout << "2. Delete element" << endl;
		cout << "3. Print the list" << endl;
		cout << "4. Find an element in the list" << endl;
		cout << "5. Sort elements in the list" << endl;
		cout << "6. Merge the lists" << endl;
		cout << "7. Cross the lists" << endl;
		cout << "0. Exit" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Defenition > ";
			cin >> value;
			cout << "Position > ";
			cin >> position;
			AddList(value, position);
			break;
		case 2:
			cout << "Position > ";
			cin >> position;
			DeleteList(position);
			break;
		case 3:
			PrintList();
			break;
		case 4:
			cout << "Defenition > ";
			cin >> value;
			FindList(value);
			break;
		case 5:
			SortList();
			break;
		case 6:
			MergeList();
			break;
		case 7:
			CrossList();
			break;
		}
	} while (x != 0);
}