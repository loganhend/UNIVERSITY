#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Stack//cоздаем структуру(будущий элемент)
{
	Stack* next;//(указатель на следующий элемент в стеке)
	int info;//информационное поле
};

Stack* push(Stack*, int);//прототип функции добавления
Stack* pop(Stack*, int*);//прототип функции удаления
void view(Stack*);//прототип функции вывода элементов
void clear(Stack**);//прототип функции очистки
void task(Stack*, Stack**);//прототип функции индивидульного задания

void Sort_p(Stack** p) {//функция сортировки элементов в стеке
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

Stack* push(Stack* p, int in)//реализация функции доавления элемента
{
	Stack* temp = new Stack;//создание указателя на элемент стека
	temp->info = in;//для поля информации в стеке задается in
	temp->next = p;//указатель на следующий элемент - последний элемент до этого
	return temp;//возвращаем обновленный стек
}

Stack* pop(Stack* p, int* out)//реализация функции удаления элемента
{
	Stack* temp = p;//последни элемент записываем в темп
	*out = p->info;//в указатель на int записываем значение элемента, который собираеся делитнуть
	p = p->next;//p переключаем на следующий после крайнего элемент
	delete temp;//удаляем крайний элемент
	return p;//возвращаем обновленный стек(указатель на новый крайний элемент стека)
}

void view(Stack* p)//реализация функции отображения стека
{
	Stack* temp = p;//последний элемент записываем в темп 
	while (temp != NULL)//пока указатель не указывает на пустоту
	{
		cout << temp->info << endl;//выводим инфополе элемента
		temp = temp->next;//переходим к след элементу
	}
}

void clear(Stack** p) {//реализация функции удаления стека, ** позволяет изменять информацию внутри элемента стека
	Stack* temp;
	while (*p != NULL) {//пока указатель не пустотой(пока не дошли до конца)
		temp = *p;//задали значение 
		*p = (*p)->next;//в p записали следующий
		delete temp;//крайний удалили
	}
}

void task(Stack* p, Stack** t)//индивидульное
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