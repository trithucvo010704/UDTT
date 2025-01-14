/*
    quay lui hoan vi
*/
#include <bits/stdc++.h>
using namespace std;
int a[100], dd[100];
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
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == 0)
        {
            a[k] = i;
            if (k == n)
            {
                show(a);
            }
            else
            {
                dd[i] = 1;
                Try(k + 1);
                dd[i] = 0;
            }
        }
    }
}

main()
{
    for (int i = 0; i < 100; i++)
    {
        dd[i] = 0;
    }
    n = 3;
    Try(1);
}