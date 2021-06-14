#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
void Input(int* M, int n);  // ���� �������
void Print(int* M, int n);   // ����� �������
void RandomFill(int* M, int n);   // ���������� ������� ���������� �������
int Work(int* M, int n);   // ��������f �������

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

// ���� �������
void Input(int* M, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "M[" << i << "]=?";
        cin >> M[i];
    }
}
// ���������� ���������� �������
void RandomFill(int* M, int n)
{
    for (int i = 0; i < n; i++)
    {
        M[i] = -50 + rand() % 100;
    }
}
// ����� �������
void Print(int* M, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << M[i] << " ";
    }
    cout << endl;
}
// ��������� - ������� ����� ������� ���������
int Work(int* M, int n)
{
    int sum = 0, buf=0,i;
    i = n-1;//������ ���������� c 0
    buf = M[i];//bufer ������ ��������� ��������� �� �������
    while ((buf >= 0) && (i >= 0)) {//�������� ������ ���� �������� � ������ �� ������������� ��� i �� ����� �� 0(������ �������)
        i--;
        buf = M[i];
    }
    if(i<=(n-1))//����� �� ������ i ��������, �������� ��� � �������
     i = i + 1;
    for (i; i < n; i++)
    {
        sum = sum + abs(M[i]);
    }
    return sum;
}