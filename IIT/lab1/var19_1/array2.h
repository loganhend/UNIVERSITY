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
	vector<int> two_to_one(vector<vector<int> > arr)//функция перевода двумерного массива в вектор
	{
		vector<int> a(h * w);//создается вектор следующуго размера
		for (int i = 0; i < h; i++)//перебор строк
		{
			for (int j = 0; j < w; j++)//перебор столбцов
			{
				a[i * w + j] = arr[i][j];
			}
		}
		return a;
	}
public://freind означает дружественная функция
	friend ofstream& operator<<(ofstream& out, const array2& a)//перегрузка оператора (просто загугли, так будет быстрее)
	{
		for (int i = 0; i < a.h; i++)
		{
			for (int j = 0; j < a.w; j++)
				out << a.arr2[i][j] << ' ';
			out << '\n';
		}
		return out;
	}
	friend ifstream& operator>>(ifstream& in, array2& a)//перегрузка оператора (просто загугли, так будет быстрее)
	{
		in >> a.h >> a.w;//считываем размеры массива из потока ввода
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

	friend ostream& operator<<(ostream& out, const array2& a)//перегрузка оператора (просто загугли, так будет быстрее)
	{
		for (int i = 0; i < a.h; i++)//обычный вывод массива с перебором строк и столбцов
		{
			for (int j = 0; j < a.w; j++)
				out << a.arr2[i][j] << ' ';
			out << '\n';
		}
		return out;
	}
	friend istream& operator>>(istream& in, array2& a)//перегрузка оператора(просто загугли, так будет быстрее)
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

	friend vector<int> Union(const array2& a, const array2& b)//функция операции объединения
	{
		vector<int> un(0);//вектор результата
		int i = 0, j = 0;//счетчики в векторах
		while (i < a.arr1.size() && j < b.arr1.size())
			//в принципе, происходит дальше просто перебор и сравнение элементов
			//для выполнения операции объединения
			//Если я начну это все расписывать, получится алгоритм для одм
			//Тут не используется ничего сложного, обычные if'ы
			//Если уже делал алгоритм по одм, логика понятна и элементарна
			//Если не делал алгоритм по одм, то разберись тут, только поможет
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
	friend vector<int> Intersection(const array2& a, const array2& b)//функция операции объединения
	{
		vector<int> intr(0);//вектор результата
		int i = 0, j = 0;//счетчики в векторах
		while (i < a.arr1.size() && j < b.arr1.size())
			//тут все еще проще, чем с объединением
			//обычный алгоритм, когда над двумя множествами производят операцию пересечение
			//мне кажется, это элементарная логика и смысла писать "сравниваем такой-то элемент одного множества с таким-то элементом второго множества" нет
			//если в упор не понимаешь, сделай одм алгоритм
			//серьезно, тебе будет только лучше
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

	void sort2()//операция сортировки
	{
		arr1 = two_to_one(arr2);//переводим наш двумерный массив в одномерный и выгружаем все элементы в arr1
		sort(arr1.begin(), arr1.end());//встроенный алгоритм сортировки в векторе
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				arr2[i][j] = arr1[i * w + j];//делаем обратную операцию операции two_to_one
				                             //из одномерного массива элементы добавляем в двумерный
			}
		}
	}
	void insert(vector<int> a)//функция добавления элементов в массив из вектора, принятого функцией
	{
		arr2.push_back(a);//добавлеям элементы вектора в массив
		h += 1;//увеличиваем количество строк на 1
		(*this).sort2();//применяем к массиву операцию sort2
		//В программировании на C ++ this - ключевое слово, которое относится к текущему экземпляру класса.В C ++ может быть 3 основных использования этого ключевого слова.
		//Его можно использовать для передачи текущего объекта в качестве параметра другому методу.
		//Его можно использовать для ссылки на переменную экземпляра текущего класса.
		//Его можно использовать для объявления индексаторов.
		//В идеале - почитай сам
	}

	bool search(int num)//функция поиска (думаю, понятно, как работает поиск в массиве с перебором столбцов и строк)
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

	int size_w()//функция возвращает количество столбцов
	{
		return w;
	}
	int size_h()//функция возвращает количество строк
	{
		return h;
	}
};