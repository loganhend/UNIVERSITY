#include <iostream>
#include <fstream>
#include <string>
#include "biblio.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream reading("zapici.txt");
    if (reading)
    {
        int n;
        int l0, r0;
        int k = 0;
        string stroka, probel, p, p1, nek;
        int a[20];
        reading >> n; // размер массива
        for (int i = 0; i < n; i++)
        {
            reading >> a[i];  //записываю элементы в массив
            k++;
        }
        l0 = 0;
        r0 = n - 1;

        while (!reading.eof())
        {
            build(a, 1, 0, n - 1);
            getline(reading, stroka);

            if (stroka == "up") //изменение на отрезке
            {
                cout << "Сумма с изменением" << endl;
                int l, r, y, k1;
                reading >> l;
                reading >> r;
                l--;
                r--;
                reading >> y;

                if (l < l0 || r > r0)
                {
                    p1 = "Nope";
                    reading >> k1;
                    getline(reading, probel);
                    getline(reading, p);
                    if (p1 == p)
                    {
                        cout << "   Ok" << endl;
                    }
                    else
                    {
                        cout << "   Error" << endl;
                    }
                }

                else
                {
                    int k, k1;
                    Up(1, 0, n - 1, l, r, y);
                    k = Sum(1, 0, n - 1);

                    reading >> k1;
                    if (k1 == k)
                    {
                        p1 = "Ok";
                    }
                    else
                    {
                        p1 = "Error";
                    }

                    getline(reading, probel);
                    getline(reading, p);

                    if (p1 == p)
                    {
                        cout << "   Ok" << endl;
                    }
                    else
                    {
                        cout << "   Error" << endl;
                    }
                }
            }

            if (stroka == "Sum") //вся сумма
            {
                cout << "Сумма всех элементов" << endl;
                int s1, S1;
                s1 = Sum(1, 0, n - 1);
                reading >> S1;
                if (s1 == S1)
                {
                    p1 = "Ok";
                }
                else
                {
                    p1 = "Error";
                }
                getline(reading, probel);
                getline(reading, p);
                if (p1 == p)
                {
                    cout << "   Ok" << endl;
                }
                else
                {
                    cout << "   Error" << endl;
                }
            }

            if (stroka == "sum") //сумма на отрезке
            {
                cout << "Сумма на отрезке" << endl;
                int l, r;
                reading >> l;
                reading >> r;
                l--;
                r--;
                if (l < l0 || r > r0)
                {
                    int k1;
                    p1 = "Nope";
                    reading >> k1;
                    getline(reading, probel);
                    getline(reading, p);
                    if (p1 == p)
                    {
                        cout << "   Ok" << endl;
                    }
                    else
                    {
                        cout << "   Error" << endl;
                    }
                }
                else
                {
                    int s2, S2;
                    s2 = sum(1, 0, n - 1, l, r);
                    reading >> S2;
                    if (s2 == S2)
                    {
                        p1 = "Ok";
                    }
                    else
                    {
                        p1 = "Error";
                    }
                    getline(reading, probel);
                    getline(reading, p);
                    if (p1 == p)
                    {
                        cout << "   Ok" << endl;
                    }
                    else
                    {
                        cout << "   Error" << endl;
                    }
                }
            }
        }
    }
    reading.close();
}