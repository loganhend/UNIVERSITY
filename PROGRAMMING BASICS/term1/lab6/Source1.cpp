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



    int** ary;// Для доступа к двумерному массиву объявляется переменная ary типа указатель на указатель на тип (в данном случае это указатель на указатель на int)
    ary = new int* [n];    // массив указателей Переменная инициализируется оператором new, который выделяет память для массива указателей на int
    for (int i = 0; i < n; i++) {   // В цикле каждый элемент массива указателей инициализируется оператором new, который выделяет память для массива типа int.
        ary[i] = new int[m];     // инициализация указателей
    }
    int** ary1;// Для доступа к двумерному массиву объявляется переменная ary типа указатель на указатель на тип (в данном случае это указатель на указатель на int)
    ary1 = new int* [n];    // массив указателей Переменная инициализируется оператором new, который выделяет память для массива указателей на int
    for (int i = 0; i < n; i++) {   // В цикле каждый элемент массива указателей инициализируется оператором new, который выделяет память для массива типа int.
        ary1[i] = new int[m];     // инициализация указателей
    }


    // работа с массивом
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
                // Обмен местами
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

    // уничтожение
    for (int i = 0; i < n; i++) {
        delete[] ary[i];
    }
    delete[] ary;
    delete[] buf;

    system("PAUSE");
    return 0;
}