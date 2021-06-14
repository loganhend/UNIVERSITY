#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

double recursive(int m, int k)
{
    double res = 0;
    if (k == m) {
        res = sqrt(m);
    }
    if (k < m) {
        res = sqrt(k + recursive(m, k + 1));
    }
    return res;
}
void non_recursive(int m)
{
    double res = 0;
    for (int i = m; i > 0; i--)
    {
        res = sqrt(i + res);
    }
    cout << res << endl;
}

int main()
{
    srand(time(NULL));
    int n, k;
    double res;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Recursive way:" << endl;
    res = recursive(n, 1);
    cout << res << endl;
    cout << "Non-recursive way:" << endl;
    non_recursive(n);
    system("PAUSE");
    return 0;
}