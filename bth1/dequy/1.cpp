#include <bits/stdc++.h>
using namespace std;
int ucln1(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return ucln1(b, a % b);
}
int ucln2(int a, int b)
{
    while (b != 0)
    {
        int tem = a % b;
        a = b;
        b = tem;
    }
    return a;
}
int main()
{
    int a = 75, b = 25;
    cout << ucln1(a, b) << " " << ucln2(a, b);
}
