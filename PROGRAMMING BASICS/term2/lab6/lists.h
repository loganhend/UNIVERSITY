#pragma once
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
struct Node //�������� ���� ������
{
	int data; //�������������� ����
	Node* next; //��������� �� ��������� �������
	Node* prev; //��������� �� ���������� �������
};

class DoubleList
{
private:
	// ������, �����
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


//**********************���������� ��������**********************
void DoubleList::AddList(int value, int position)
{
	Node* node = new Node; //�������� ������ ��������
	node->data = value; //���������� �������� ��������
	if (head == NULL) //���� ������ ����
	{
		node->next = node; //��������� ��������� next
		node->prev = node; //��������� ��������� prev
		head = node; //������������ ������ ������
		tail = node;//������������ ����� ������
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


//***********************�������� ��������***********************
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


//*************************����� ������*************************
void DoubleList::PrintList()
{
	ValidCheck();
	Node* a = head;
	cout << "\n�������� ������: ";
	do
	{
		cout << a->data << " ";
		a = a->next;
	} while (a != head); cout << "\n\n";
}

//*************************����� � ������*************************
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

//*************************���������� ������*************************
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


//*************************����������� �������*************************
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

//*************************����������� �������*************************
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

//*************************�������������� �������***********************
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