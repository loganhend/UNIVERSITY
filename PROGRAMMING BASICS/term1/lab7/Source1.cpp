#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n, k, m, sum1, sum2,len,j,buf1,buf2;
    char st[81];
    n = 0;
    buf1 = 0;
    buf2 = 0;
    cout << "Enter srting." << endl;
    //cin >> st;//
    cin.getline(st, 81);


    cout << "_______________________________________________________________" << endl;
    for (int i = 0; i <= strlen(st); i++) {
        cout << st[i];
    }
    cout << endl;
    
    len = strlen(st);
    cout << len;
    cout << endl;

    for (int i = 0; i <= len; i++)
    {    
        buf1 = 0;
        buf2 = 0;
        if ((st[i] == '0' || st[i] == '1' || st[i] == '2' || st[i] == '3' || st[i] == '4' || st[i] == '5' || st[i] == '6' || st[i] == '7' || st[i] == '8' || st[i] == '9' ) && (st[i + 1] == ',' || st[i+1] == '.'))
        {
            buf1 = i;
            j = i + 2;
            n = 1;
           while ((j <= (len - 3)) && n == 1)
            {
                if (st[j] == '0' || st[j] == '1' || st[j] == '2' || st[j] == '3' || st[j] == '4' || st[j] == '5' || st[j] == '6' || st[j] == '7' || st[j] == '8' || st[j] == '9')
                {
                    j++;
                    n = 1;
                }
                if (st[j] != '0' && st[j] != '1' && st[j] != '2' && st[j] != '3' && st[j] != '4' && st[j] != '5' && st[j] != '6' && st[j] != '7' && st[j] != '8' && st[j] != '9')
                {
                    n = 0;
                }
            }
            if (st[j] == 'e' || st[j] == 'E')
            {
                if (st[j + 1] == '+' || st[j + 1] == '-')
                {
                    k = j + 2;
                    n = 1;
                    while ((k <= len) && n == 1)
                    {
                        if (st[k] == '0' || st[k] == '1' || st[k] == '2' || st[k] == '3' || st[k] == '4' || st[k] == '5' || st[k] == '6' || st[k] == '7' || st[k] == '8' || st[k] == '9')
                        {
                            k++;
                            n = 1;
                        }
                        if (st[k] != '0' && st[k] != '1' && st[k] != '2' && st[k] != '3' && st[k] != '4' && st[k] != '5' && st[k] != '6' && st[k] != '7' && st[k] != '8' && st[k] != '9')
                        {
                            n = 0;
                        }
                    }
                    buf2 = k - 1;

                    //
                    cout << "_______________________________________________________________" << endl;
                    cout << "Your number is" << endl;
                    for (int i = buf1; i <= buf2; i++) {
                        cout << st[i];
                    }
                    cout << endl;
                    cout << "_______________________________________________________________" << endl;


                    //
                }
            }
        }
    }

    system("PAUSE");
    return 0;
}