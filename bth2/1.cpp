/*
    Quay Lui Nhi Nhan
*/
#include <bits/stdc++.h>
using namespace std;
int a[100];
int n;
void show(int a[])
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Try(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        a[k] = i;
        if (k == n)
        {
            show(a);
        }
        else
        {
            Try(k + 1);
        }
    }
}
main()
{
    n = 4;
    Try(1);
}