#pragma once
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
struct Node //описание узла списка
{
	int data; //информационное поле
	Node* next; //указатель на следующий элемент
	Node* prev; //указатель на предыдущий элемент
};

class DoubleList
{
private:
	// Голова, хвост
	Node* head;
	Node* tail;
	int count;
public:
	~DoubleList();
	DoubleList();
	Node* ReturnHead();
	void AddList(int value, int position);
	void DeleteList(int position);
	void PrintList();
	vector<int> FindList(int val);
	void SortList();
	vector<int> GetVector();
	void task();
	void DelAll();
	void ValidCheck();
	void MergeList(Node* a, Node* b);
	void CrossList(Node* a, Node* b);
	void GetList(int k);
	void SendList();
};

DoubleList::DoubleList()
{
	head = tail = NULL;
	count = 0;
}

Node* DoubleList::ReturnHead()
{
	return head;
}

void DoubleList::DelAll()
{
	while (count != 0)
		DeleteList(1);
}

DoubleList::~DoubleList()
{
	DelAll();
}

void DoubleList::ValidCheck()
{
	if (head == NULL)
		throw exception();
}


//**********************ДОБАВЛЕНИЕ ЭЛЕМЕНТА**********************
void DoubleList::AddList(int value, int position)
{
	Node* node = new Node; //создание нового элемента
	node->data = value; //присвоение элементу значения
	if (head == NULL) //если список пуст
	{
		node->next = node; //установка указателя next
		node->prev = node; //установка указателя prev
		head = node; //определяется голова списка
		tail = node;//определяется хвост списка
		count++;
	}
	else
	{
		Node* p = head;
		for (int i = position; i > 1; i--) p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
		count++;
	}
}


//***********************УДАЛЕНИЕ ЭЛЕМЕНТА***********************
void DoubleList::DeleteList(int position)
{
	ValidCheck();
	if (head == head->next)
	{
		delete head;
		head = NULL;
		count--;
	}
	else
	{
		Node* a = head;
		for (int i = position; i > 1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
		count--;
	}
}


//*************************ВЫВОД СПИСКА*************************
void DoubleList::PrintList()
{
	ValidCheck();
	Node* a = head;
	cout << "\nЭлементы списка: ";
	do
	{
		cout << a->data << " ";
		a = a->next;
	} while (a != head); cout << "\n\n";
}

//*************************ПОИСК В СПИСКЕ*************************
vector<int> DoubleList::FindList(int val)
{
	int i = 1;
	vector<int> found;
	ValidCheck();
	Node* a = head;
	do
	{
		if (val == a->data)
		{ 
			found.push_back(i);
		}
		i++;
		a = a->next;
	} while (a != head);
	return found;
}

//*************************СОРТИРОВКА СПИСКА*************************
void DoubleList::SortList() {
	vector<int> buf;
	ValidCheck();
	Node* a = head;
	do
	{
		buf.push_back(a->data);
		a = a->next;
	} while (a != head);
	sort(buf.begin(), buf.end());
	for (int w : buf)
		DeleteList(1);
	for (int w : buf)
		AddList(w, 1);
}


//*************************ОБЪЕДИНЕНИЕ СПИСКОВ*************************
void DoubleList::MergeList(Node* a , Node* b)
{
	set<int> c;
	Node* h = a;
	do
	{
		c.insert(h->data);
		h = h->next;
	} while (h != a);

	h = b;
	do
	{
		c.insert(h->data);
		h = h->next;
	} while (h != b);
	
	for (int q : c)
	{
		AddList(q, 1);
	}
}

//*************************ПЕРЕСЕЧЕНИЕ СПИСКОВ*************************
void DoubleList::CrossList(Node* a, Node* b)
{
	map<int, int> c;
	Node* h = a;
	do
	{
		c[h->data]++;
		h = h->next;
	} while (h != a);


	h = b;
	do
	{
		c[h->data]++;
		h = h->next;
	} while (h != b);


	set<int> d;
	for (const auto& q : c)
	{
		if(q.second>1)
		{
			d.insert(q.first);
		}
	}

	for (int q : d)
	{
		AddList(q, 1);
	}
}

//*************************ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ***********************
void DoubleList::task()
{
	Node* temp = head;
	ValidCheck();
	int min,num;
	min = temp->data;
	int i = 1;
	do
	{
		if (min >= temp->data)
		{
			min = temp->data;
			num = i;
		}
		i++;
		temp = temp->next;
	} while (temp != head);

	for (i = 1; i <= num; i++) {
		DeleteList(1);
	}	
}