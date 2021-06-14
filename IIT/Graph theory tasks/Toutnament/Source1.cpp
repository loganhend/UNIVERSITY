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
    for (int i = 0; i < n; i++) //���������� ������
    {
        for (int j = 0; j < m; j++) //���������� �������� � �������
        {
            if (ary[i][j] == 1)//������� �������, �� �������� ������� ����� (����� ������� �������� � i)
            {
                for (int a = 0; a < n; a++)//���������� �������, ������ �������� � ������� ��� ����� �����
                {
                    if (ary[a][j] == -1)//�������, ���� ��� ����� �������� (����� ������� �������� � �)
                    {
                        for (int b = 0; b < m; b++)//���������� ��� ���� ������� ��� �������� � ������� ��������� �����
                        {
                            if ((ary[a][b] == 1) && (ary[i][b] == -1))//���� ������� �����-�� ����� (������ 1 � �������) � ��� ���� � ������� i ��� ����� �� ����� ����� -1 (������ ��� ����� �������� � ������� i)
                                tour_checker = false;//���������� ������� ��� �����-�������
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
    for (int i = 0; i < n; i++)//���������� ������
    {
        for (int j = 0; j < m; j++)//���������� �������� � �������
        {
            if (ary[i][j] == 1)//������� �������, �� �������� ������� ����� (����� ������� �������� � i)
            {
                for (int a = 0; a < n; a++)//���������� �������, ������ �������� � ������� ��� ����� �����
                {
                    if (ary[a][j] == -1)//�������, ���� ��� ����� �������� (����� ������� �������� � �)
                    {
                        for (int b = 0; b < m; b++)//���������� ��� ���� ������� ��� �������� � ������� ��������� �����
                        {
                            if (ary[a][b] == 1)//������� ��������� ����� �� ������� �
                            {
                                for (int c = 0; c < n; c++)//���������� �������, ������ �������� � ������� ��� ����� �����
                                {
                                    if (ary[c][b] == -1)//�������, ���� ��� ����� �������� (����� ������� �������� � c)
                                    {
                                        for (int x = 0; x < m; x++)//���������� ��� ���� ������� ��� ��������
                                        {
                                            if ((ary[c][x] == -1) && (ary[i][x] == 1))//���� �������� (-1) � ������� � ����� ������� (1) �� ������� i
                                                three_checker = 1;//���������� ������ �������� 1
                                            if ((x == (m - 1)) && (three_checker == 0))//���� ��������� ��� ������ ��� ������� � � �� ����� ����� �������
                                                trans_checker = false;//���������� ������� ��� ��������������
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

    for (int i = 1; i < n; i++)//�������, ������� ������ ���� �����, �� ��� ������� ������ ���� ��������� �� ����� �������
        M += i;

    zero_counted == m - n + 1;//�������, ������� ����� ������ ���� ��� ������ ������� � ������ ������ � ������� (������ ����� � ���� �������)


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
