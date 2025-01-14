#include <bits/stdc++.h>
using namespace std;
long long f1(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return f1(n - 1) + f1(n - 2);
}
long long f2(int n)
{
    long long fbtruoc = 1;
    long long fbtruoc2 = 1;
    long long temp = 0;
    for (int i = 3; i <= n; i++)
    {
        temp = fbtruoc + fbtruoc2;
        fbtruoc = temp;
        fbtruoc2 = fbtruoc;
    }
    return temp;
}
main()
{
    int n = 5;
    cout << f2(n) << endl;
}