#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Stack//c������ ���������(������� �������)
{
	Stack* next;//(��������� �� ��������� ������� � �����)
	int info;//�������������� ����
};

Stack* push(Stack*, int);//�������� ������� ����������
Stack* pop(Stack*, int*);//�������� ������� ��������
void view(Stack*);//�������� ������� ������ ���������
void clear(Stack**);//�������� ������� �������
void task(Stack*, Stack**);//�������� ������� �������������� �������

void Sort_p(Stack** p) {//������� ���������� ��������� � �����
	Stack* t = NULL, * t1, * r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}


int main()
{
	Stack* my_stack = NULL;
	int opt;
	while (true)
	{
		view(my_stack);
		if (my_stack != NULL)
		{
			cout << endl;
		}
		cout << "Enter 1 to push an element to the stack" << endl;
		cout << "Enter 2 to delete an element from the stack" << endl;
		cout << "Enter 3 to clear the stack" << endl;
		cout << "Enter 4 for individual task" << endl;
		cout << "Enter 5 to exit" << endl; 
		cout << "Enter 6 to sort the stack" << endl;
		cout << endl;
		cin >> opt;
		cout << endl;
		switch (opt)
		{
		case 1:
		{
			int number;
			cout << "Enter info for the element:" << endl;
			cin >> number;
				my_stack = push(my_stack, number);
			break;
		}
		case 2:
		{
			int a;
			my_stack = pop(my_stack, &a);
			cout << a << " was ejected" << endl;
			break;
		}
		case 3:
		{
			clear(&my_stack);
			break;
		}
		case 4:
		{
			system("cls");
			cout << "Old stack:" << endl;
			view(my_stack);
			task(my_stack, &my_stack);
			cout << endl << "New stack:" << endl;
			view(my_stack);
			system("pause");
			break;
		}
		case 5:
		{
			clear(&my_stack);
			return 0;
		}
		case 6:
		{
			my_stack = push(my_stack, 1);
			Sort_p(&my_stack);
			int a;
			my_stack = pop(my_stack, &a);
		}
		}
		system("cls");
	}
}

Stack* push(Stack* p, int in)//���������� ������� ��������� ��������
{
	Stack* temp = new Stack;//�������� ��������� �� ������� �����
	temp->info = in;//��� ���� ���������� � ����� �������� in
	temp->next = p;//��������� �� ��������� ������� - ��������� ������� �� �����
	return temp;//���������� ����������� ����
}

Stack* pop(Stack* p, int* out)//���������� ������� �������� ��������
{
	Stack* temp = p;//�������� ������� ���������� � ����
	*out = p->info;//� ��������� �� int ���������� �������� ��������, ������� ��������� ���������
	p = p->next;//p ����������� �� ��������� ����� �������� �������
	delete temp;//������� ������� �������
	return p;//���������� ����������� ����(��������� �� ����� ������� ������� �����)
}

void view(Stack* p)//���������� ������� ����������� �����
{
	Stack* temp = p;//��������� ������� ���������� � ���� 
	while (temp != NULL)//���� ��������� �� ��������� �� �������
	{
		cout << temp->info << endl;//������� �������� ��������
		temp = temp->next;//��������� � ���� ��������
	}
}

void clear(Stack** p) {//���������� ������� �������� �����, ** ��������� �������� ���������� ������ �������� �����
	Stack* temp;
	while (*p != NULL) {//���� ��������� �� ��������(���� �� ����� �� �����)
		temp = *p;//������ �������� 
		*p = (*p)->next;//� p �������� ���������
		delete temp;//������� �������
	}
}

void task(Stack* p, Stack** t)//�������������
{
	Stack* temp = p;
	if (temp == NULL)
	{
		cout << "Error! Stack is empty!" << endl;
	}
	else 
	{
		Stack* point = p;
		double min;
		min= temp->info;

		while (temp != NULL)
		{
			if (min >= temp->info)
			{
				min = temp->info;
				point = temp;
			}
			temp = temp->next;
		}

		while (*t != point) 
		{
			temp = *t;
			*t = (*t)->next;
			delete temp;
		}
		temp = *t;
		*t = (*t)->next;
		delete temp;
	}
}