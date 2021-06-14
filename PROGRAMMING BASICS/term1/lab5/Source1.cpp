#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
void Input(int* M, int n);  // ввод массива
void Print(int* M, int n);   // вывод массива
void RandomFill(int* M, int n);   // заполнение массива случайными числами
int Work(int* M, int n);   // обработкf массива

int main()
{
    srand(time(NULL));
    int n,k;
    cout << "Enter massiv size"<<endl;
    cin >> n;
    cout << "Do you want to enter massiv elements yourself?(0) Or random machine filling?(1)"<<endl;
    cin >> k;
    int* A = new int[n];
    if(k == 0)
      Input(A,n);
    if (k == 1)
      RandomFill(A, n);
    Print(A, n);
    int s = Work(A, n);
    cout << "Summa = " << s << endl;
    delete[] A;
    system("PAUSE");
    return 0;
}

// ввод массива
void Input(int* M, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "M[" << i << "]=?";
        cin >> M[i];
    }
}
// заполнение случайными числами
void RandomFill(int* M, int n)
{
    for (int i = 0; i < n; i++)
    {
        M[i] = -50 + rand() % 100;
    }
}
// вывод массива
void Print(int* M, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;
}
// обработки - подсчет суммы модулей элементов
int Work(int* M, int n)
{
    int sum = 0, buf=0,i;
    i = n-1;//массив начинается c 0
    buf = M[i];//bufer задаем последним значением из массива
    while ((buf >= 0) && (i >= 0)) {//проходим массив пока значение в буфере не отрицательное или i не дошло до 0(начало массива)
        i--;
        buf = M[i];
    }
    if(i<=(n-1))//чтобы не задать i значение, которого нет в массиве
     i = i + 1;
    for (i; i < n; i++)
    {
        sum = sum + abs(M[i]);
    }
    return sum;
}