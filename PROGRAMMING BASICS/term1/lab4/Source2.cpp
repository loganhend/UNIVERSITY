#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include <cstdlib>

using namespace std;
int fac(int k)
{
    int fact;
    fact = 1;
    for (int i = 1; i <= k; i++) {
        fact = fact * i;
    }
    return fact;
}

int main()
{
    double a, b, n, h;
    double x, s, y, k, fact, chisl, rasn, e;
    cout << "Enter n" << endl;
    cin >> n;
    cout << "Enter a" << endl;
    cin >> a;
    cout << "Enter b" << endl;
    cin >> b;
    cout << "Enter h" << endl;
    cin >> h;

    for (x = a; x <= b; x += h) {
        s = 0;
        y = 2 * (pow(cos(x), 2) - 1); //y(x)
        for (k = 1; k <= n; k++) {
            fact = fac(2 * k);
            chisl = pow(2 * x, 2 * k);//числитель
            s += (pow(-1, k) * (chisl / fact)); //s(x)
        }
        rasn = fabs(y - s);
        cout << "If x = " << x << "| S(x)= " << s << "| Y(x)= " << y << "| MoRa= " << rasn << endl;
    }
    system("PAUSE");
    return 0;
}