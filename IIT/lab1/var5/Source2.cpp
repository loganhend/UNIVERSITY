#include <iostream>
using namespace std;

int t[1000];

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else {
        int m = (tl + tr) / 2;
        build(a, 2 * v, tl, m);
        build(a, 2 * v + 1, m + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

//????? ?? ???? ??????? 
int Sum(int v, int tl, int tr)
{
    if (tl == tr)
    {
        return t[v];
    }
    int m = (tl + tr) / 2;
    return Sum(2 * v, tl, m) + Sum(2 * v + 1, m + 1, tr);
}

//????? ?? ??????? ??????? 
int sum(int v, int tl, int tr, int l, int r)
{
    if (l <= tl && tr <= r)
    {
        return t[v];
    }

    if (tr < l || r < tl)
    {
        return 0;
    }

    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, r) + sum(v * 2 + 1, tm + 1, tr, l, r);
}

//?????????
void  Up(int v, int tl, int tr, int l, int r, int y)
{
    if (l > r) return;
    if (tl == tr)
    {
        t[v] = y;
    }
    else
    {
        int tm = (tl + tr) / 2;
        Up(2 * v, tl, tm, l, min(r, tm), y);
        Up(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, y);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}