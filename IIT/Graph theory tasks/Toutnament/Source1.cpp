#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
#include <string>
#include<map>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include<fstream>
#include<sstream>
using namespace std;


bool Tour_Check(int** ary, int n, int m)
{
    bool tour_checker=1;
    for (int i = 0; i < n; i++) //перебираем строки
    {
        for (int j = 0; j < m; j++) //перебираем элементы в строках
        {
            if (ary[i][j] == 1)//находим элемент, из которого исходит ребро (номер вершины хранится в i)
            {
                for (int a = 0; a < n; a++)//перебираем столбец, тоесть значения в матрице для этого ребра
                {
                    if (ary[a][j] == -1)//находим, куда это ребро приходит (номер вершины хранится в а)
                    {
                        for (int b = 0; b < m; b++)//перебираем для этой вершины все элементы в поисках исходящих ребер
                        {
                            if ((ary[a][b] == 1) && (ary[i][b] == -1))//если выходит какое-то ребро (тоесть 1 в матрице) и при этом в вершине i для этого же ребра стоит -1 (тоесть это ребро приходит в вершину i)
                                tour_checker = false;//нарушается условие для графа-турнира
                        }
                    }
                }
            }
        }

    }
    return tour_checker;
}

bool Trans_Check(int** ary, int n, int m)
{
    bool trans_checker = 1, three_checker=0;
    vector<int> starter;
    for (int i = 0; i < n; i++)//перебираем строки
    {
        for (int j = 0; j < m; j++)//перебираем элементы в строках
        {
            if (ary[i][j] == 1)//находим элемент, из которого исходит ребро (номер вершины хранится в i)
            {
                for (int a = 0; a < n; a++)//перебираем столбец, тоесть значения в матрице для этого ребра
                {
                    if (ary[a][j] == -1)//находим, куда это ребро приходит (номер вершины хранится в а)
                    {
                        for (int b = 0; b < m; b++)//перебираем для этой вершины все элементы в поисках исходящих ребер
                        {
                            if (ary[a][b] == 1)//находим исходящее ребро из вершины а
                            {
                                for (int c = 0; c < n; c++)//перебираем столбец, тоесть значения в матрице для этого ребра
                                {
                                    if (ary[c][b] == -1)//находим, куда это ребро приходит (номер вершины хранится в c)
                                    {
                                        for (int x = 0; x < m; x++)//перебираем для этой вершины все элементы
                                        {
                                            if ((ary[c][x] == -1) && (ary[i][x] == 1))//если входящее (-1) в вершину с ребро выходит (1) из вершины i
                                                three_checker = 1;//переменной задаем значение 1
                                            if ((x == (m - 1)) && (three_checker == 0))//если перебрали всю строку для вершины с и не нашли такой элемент
                                                trans_checker = false;//нарушается условие для транзитивности
                                        }
                                        three_checker = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return trans_checker;
}

void TestRunner(int test)
{
    int n, link, m, M=0, zero_count = 0, zero_counted = 0, checker=0;
    string testname;
    testname = "test" + to_string(test) + ".txt";
    ifstream input(testname, ios::app);

    cout << "Test " << test << endl;

    if (!input.is_open())
    {
        cout << "File is not opened" << endl;
    }
    input >> n >> m;

    for (int i = 1; i < n; i++)//считаем, сколько должно быть ребер, тк все вершины должны быть соединены со всеми другими
        M += i;

    zero_counted == m - n + 1;//считаем, сколько нулей должно быть для каждой вершины в каждой строке в матрице (только связи в одну сторону)


    if (m != M) {
        cout << "Not tournament" << endl;
        cout << endl;
        cout << endl;
    }
    else
    {
        int** ary;
        ary = new int* [n];
        for (int i = 0; i < n; i++) {
            ary[i] = new int[m];
        }

        for (int i = 0; i < n; i++) 
        {

            for (int j = 0; j < m; j++) {
                input >> link;
                ary[i][j] = link;
                if (ary[i][j] == 0)
                    zero_count++;
            }

            if (zero_count == zero_counted)
            {
                cout << "Not tournament" << endl;
                cout << endl;
                cout << endl;
                return;
            }
            
            zero_count = 0;
        }


        cout << "Table: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ary[i][j] << " ";
            }
            cout << endl;
        }


       if(Tour_Check(ary, n,m))
           cout << "Graph is tournament";
       if (Tour_Check(ary, n, m) && Trans_Check(ary, n, m))
           cout << " and is transitive" << endl;



        for (int i = 0; i < n; i++)
            delete[]ary[i];
        delete[]ary;
        cout << endl;
        cout << endl;
    }
}

// Test
int main()
{
    TestRunner(1);
    TestRunner(2);
    TestRunner(3);
    TestRunner(4);
    TestRunner(5);

    return 0;
}
