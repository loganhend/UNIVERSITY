#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n, k, m, sum1, sum2;
    cout << "Enter massiv size n" << endl;
    cin >> n;
    cout << "Enter massiv size m" << endl;
    cin >> m;



    int** ary;// ��� ������� � ���������� ������� ����������� ���������� ary ���� ��������� �� ��������� �� ��� (� ������ ������ ��� ��������� �� ��������� �� int)
    ary = new int* [n];    // ������ ���������� ���������� ���������������� ���������� new, ������� �������� ������ ��� ������� ���������� �� int
    for (int i = 0; i < n; i++) {   // � ����� ������ ������� ������� ���������� ���������������� ���������� new, ������� �������� ������ ��� ������� ���� int.
        ary[i] = new int[m];     // ������������� ����������
    }
    int** ary1;// ��� ������� � ���������� ������� ����������� ���������� ary ���� ��������� �� ��������� �� ��� (� ������ ������ ��� ��������� �� ��������� �� int)
    ary1 = new int* [n];    // ������ ���������� ���������� ���������������� ���������� new, ������� �������� ������ ��� ������� ���������� �� int
    for (int i = 0; i < n; i++) {   // � ����� ������ ������� ������� ���������� ���������������� ���������� new, ������� �������� ������ ��� ������� ���� int.
        ary1[i] = new int[m];     // ������������� ����������
    }


    // ������ � ��������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Enter massiv element ary[" << i << "] [" << j << "]" << endl;
            cin >> k;
            ary[i][j] = k;
        }
    }
    cout << "Now matrix looks like:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ary1[i][j] = ary[i][j];
            cout << "[" << i << "][" << j << "]" << ary[i][j] << " || ";
        }
        cout << endl;
    }

    int* buf = new int[m];

    for (int i = 1; i < n; ++i)
    {
        for (int r = 0; r < n - i; r++)
        {
            sum1 = 0;
            sum2 = 0;
            for (int j = 0; j < m; j++) {
                sum1 = sum1 + ary1[r][j];
            }
            for (int j = 0; j < m; j++) {
                sum2 = sum2 + ary1[r + 1][j];
            }
            if (sum1 > sum2)
            {
                // ����� �������
                swap(ary1[r], ary1[r + 1]);
            }
        }
    }


    cout << "_______________________________________________________________" << endl;

    cout << "Now matrix looks like:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "[" << i << "][" << j << "]" << ary1[i][j] << " || ";
        }
        cout << endl;
    }

    // �����������
    for (int i = 0; i < n; i++) {
        delete[] ary[i];
    }
    delete[] ary;
    delete[] buf;

    system("PAUSE");
    return 0;
}