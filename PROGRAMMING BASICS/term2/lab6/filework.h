#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include"lists.h"

using namespace std;
void  DoubleList::GetList(int k)
{
	ifstream input("listin.txt", ios::app);
	cout << "Read" << endl;
	if (!input.is_open())
	{
		cout << "File is not opened" << endl;
	}
	else
	{
		cout << "File is opened" << endl;
		vector<int> b;
		vector<int> a;
		string line;

		int i;
		getline(input, line);
		istringstream text_stream(line);
		while (text_stream >> i)
		{
			a.push_back(i);
			text_stream.ignore(1);
		}
		if ((k == 2) && (getline(input, line)))
		{
			istringstream text_stream(line);
			while (text_stream >> i)
			{
				b.push_back(i);
				text_stream.ignore(1);
			}
			for (int w : b)
				AddList(w, 1);
		}
		else
			for (int w : a)
				AddList(w, 1);
	}
	input.close();
}

void  DoubleList::SendList()
{
	ValidCheck();
	ofstream output("listout.txt", ios::ate);
	Node* b = head;
	do
	{
		output << b->data << ".";
	} while (b != head);
}