#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include <string>
using namespace std;

class array2
{
private:
	int h, w;
	vector<vector<int> > arr2;
	vector<int> arr1;
	vector<int> two_to_one(vector<vector<int> > arr)//������� �������� ���������� ������� � ������
	{
		vector<int> a(h * w);//��������� ������ ���������� �������
		for (int i = 0; i < h; i++)//������� �����
		{
			for (int j = 0; j < w; j++)//������� ��������
			{
				a[i * w + j] = arr[i][j];
			}
		}
		return a;
	}
public://freind �������� ������������� �������
	friend ofstream& operator<<(ofstream& out, const array2& a)//���������� ��������� (������ �������, ��� ����� �������)
	{
		for (int i = 0; i < a.h; i++)
		{
			for (int j = 0; j < a.w; j++)
				out << a.arr2[i][j] << ' ';
			out << '\n';
		}
		return out;
	}
	friend ifstream& operator>>(ifstream& in, array2& a)//���������� ��������� (������ �������, ��� ����� �������)
	{
		in >> a.h >> a.w;//��������� ������� ������� �� ������ �����
		a.arr2.resize(a.h);
		for (int i = 0; i < a.h; i++)
		{
			a.arr2[i].resize(a.w);
		}
		for (int i = 0; i < a.h; i++)
		{
			for (int j = 0; j < a.w; j++)
			{
				in >> a.arr2[i][j];
			}
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const array2& a)//���������� ��������� (������ �������, ��� ����� �������)
	{
		for (int i = 0; i < a.h; i++)//������� ����� ������� � ��������� ����� � ��������
		{
			for (int j = 0; j < a.w; j++)
				out << a.arr2[i][j] << ' ';
			out << '\n';
		}
		return out;
	}
	friend istream& operator>>(istream& in, array2& a)//���������� ���������(������ �������, ��� ����� �������)
	{
		in >> a.h >> a.w;
		a.arr2.resize(a.h);
		for (int i = 0; i < a.h; i++)
		{
			a.arr2[i].resize(a.w);
		}
		for (int i = 0; i < a.h; i++)
		{
			for (int j = 0; j < a.w; j++)
			{
				in >> a.arr2[i][j];
			}
		}
		return in;
	}

	friend vector<int> Union(const array2& a, const array2& b)//������� �������� �����������
	{
		vector<int> un(0);//������ ����������
		int i = 0, j = 0;//�������� � ��������
		while (i < a.arr1.size() && j < b.arr1.size())
			//� ��������, ���������� ������ ������ ������� � ��������� ���������
			//��� ���������� �������� �����������
			//���� � ����� ��� ��� �����������, ��������� �������� ��� ���
			//��� �� ������������ ������ ��������, ������� if'�
			//���� ��� ����� �������� �� ���, ������ ������� � �����������
			//���� �� ����� �������� �� ���, �� ��������� ���, ������ �������
		{
			if (a.arr1[i] == b.arr1[j])
			{
				if (un.size() == 0 || a.arr1[i] != un[un.size() - 1])
					un.push_back(a.arr1[i]);
				i++;
				j++;
				continue;
			}
			if (a.arr1[i] < b.arr1[j])
			{
				if (un.size() == 0 || a.arr1[i] != un[un.size() - 1])
					un.push_back(a.arr1[i]);
				i++;
				continue;
			}
			if (b.arr1[j] < a.arr1[i])
			{
				if (un.size() == 0 || b.arr1[j] != un[un.size() - 1])
					un.push_back(b.arr1[j]);
				j++;
				continue;
			}
		}
		if (i < a.arr1.size())
			for (; i < a.arr1.size(); i++)
			{
				if (a.arr1[i] != un[un.size() - 1])
					un.push_back(a.arr1[i]);
			}
		if (j < b.arr1.size())
			for (; j < b.arr1.size(); j++)
			{
				if (b.arr1[j] != un[un.size() - 1])
					un.push_back(b.arr1[j]);
			}
		return un;
	}
	friend vector<int> Intersection(const array2& a, const array2& b)//������� �������� �����������
	{
		vector<int> intr(0);//������ ����������
		int i = 0, j = 0;//�������� � ��������
		while (i < a.arr1.size() && j < b.arr1.size())
			//��� ��� ��� �����, ��� � ������������
			//������� ��������, ����� ��� ����� ����������� ���������� �������� �����������
			//��� �������, ��� ������������ ������ � ������ ������ "���������� �����-�� ������� ������ ��������� � �����-�� ��������� ������� ���������" ���
			//���� � ���� �� ���������, ������ ��� ��������
			//��������, ���� ����� ������ �����
		{
			if (a.arr1[i] == b.arr1[j])
			{
				if (intr.size() == 0 || a.arr1[i] != intr[intr.size() - 1])
					intr.push_back(a.arr1[i]);
				i++;
				j++;
				continue;
			}
			if (a.arr1[i] < b.arr1[j])
			{
				i++;
				continue;
			}
			if (b.arr1[j] < a.arr1[i])
			{
				j++;
				continue;
			}
		}
		return intr;
	}

	void sort2()//�������� ����������
	{
		arr1 = two_to_one(arr2);//��������� ��� ��������� ������ � ���������� � ��������� ��� �������� � arr1
		sort(arr1.begin(), arr1.end());//���������� �������� ���������� � �������
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				arr2[i][j] = arr1[i * w + j];//������ �������� �������� �������� two_to_one
				                             //�� ����������� ������� �������� ��������� � ���������
			}
		}
	}
	void insert(vector<int> a)//������� ���������� ��������� � ������ �� �������, ��������� ��������
	{
		arr2.push_back(a);//��������� �������� ������� � ������
		h += 1;//����������� ���������� ����� �� 1
		(*this).sort2();//��������� � ������� �������� sort2
		//� ���������������� �� C ++ this - �������� �����, ������� ��������� � �������� ���������� ������.� C ++ ����� ���� 3 �������� ������������� ����� ��������� �����.
		//��� ����� ������������ ��� �������� �������� ������� � �������� ��������� ������� ������.
		//��� ����� ������������ ��� ������ �� ���������� ���������� �������� ������.
		//��� ����� ������������ ��� ���������� ������������.
		//� ������ - ������� ���
	}

	bool search(int num)//������� ������ (�����, �������, ��� �������� ����� � ������� � ��������� �������� � �����)
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr2[i][j] == num)return true;
			}
		}
		return false;
	}

	int size_w()//������� ���������� ���������� ��������
	{
		return w;
	}
	int size_h()//������� ���������� ���������� �����
	{
		return h;
	}
};