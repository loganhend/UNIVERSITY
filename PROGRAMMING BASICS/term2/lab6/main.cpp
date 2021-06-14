#include <iostream>
#include <vector>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include<map>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <sstream>
#include"lists.h"
#include"filework.h"

using namespace std;
ifstream input("listin.txt", ios::app);
ofstream output("listout.txt", ios::app);

int main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	DoubleList l;
	do
	{
		cout << "1. Add element" << endl;
		cout << "2. Delete element" << endl;
		cout << "3. Print the list" << endl;
		cout << "4. Find an element in the list" << endl;
		cout << "5. Sort elements in the list" << endl;
		cout << "6. Merge the lists" << endl;
		cout << "7. Cross the lists" << endl;
		cout << "8. Get a list from the database" << endl;
		cout << "9. Uploade the list to the database" << endl;
		cout << "10. Individual task" << endl;
		cout << "11. Delete all" << endl;
		cout << "0. Exit" << endl;
		cin >> x;
		switch (x)
		{
		case 1:
			cout << "Defenition > "; 
			cin >> value;
			cout << "Position > "; 
			cin >> position;
			l.AddList(value, position); 
			cout << "\nElement was added...\n\n";
			break;
		case 2:
			try {
				cout << "Position > ";
				cin >> position;
				l.DeleteList(position);
				cout << "\nElement was deleted...\n\n";
				break;
			}
			catch (exception&) {
				cout << "\nList is empty\n\n";
				break;
			}

		case 3:
			try {
				l.PrintList();
				break;
			}
			catch (exception&) {
				cout << "\nList is empty\n\n";
				break;
			}

		case 4:
			try {
				cout << "Defenition > ";
				cin >> value;
				vector<int> a;
				a = l.FindList(value);
				for (int q : a)
				{
					cout << "For " << value << " stays elment number " << q << endl;
				}
				break;
			}
			catch (exception&) {
				cout << "\nList is empty\n\n";
				break;
			}
		case 5:
			try {
				l.SortList();
				break;
			}
			catch (exception&) {
				cout << "\nList is empty\n\n";
				break;
			}
		case 6:
		{
			DoubleList f,s;
			f.GetList(1);

			s.GetList(2);

			l.DelAll();
			l.MergeList(f.ReturnHead(), s.ReturnHead());
			l.PrintList();
			break;
		}
		case 7:
		{
			DoubleList f, s;
			f.GetList(1);
			s.GetList(2);
			l.DelAll();
			l.CrossList(f.ReturnHead(), s.ReturnHead());
			l.PrintList();
			break;
		}
		case 8:
		{
			l.GetList(1);
			break;
		}
		case 9:
		{
			try {
				l.SendList();
				break;
			}
			catch (exception&) {
				cout << "\nList is empty\n\n";
				break;
			}
		}
		case 10:
		{
			
			try {
				system("cls");
				cout << "Old list:" << endl;
				l.PrintList();
				l.task();
				cout << endl << "New list:" << endl;
				l.PrintList();
				system("pause");
				break;
			}
			catch (exception&) {
				cout << "\nList is empty\n\n";
				break;
			}
		}
		case 11:
		{
			l.DelAll();
			break;
		}

		}
	} while (x != 0);
}
