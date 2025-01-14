#include <bits/stdc++.h>
using namespace std;
float powmod(float a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return a;
    }
    float x = powmod(a, n / 2);
    if (n % 2 == 0)
    {
        return x * x;
    }
    else
        return x * x * a;
}
main()
{
    cout << powmod(2.5, 3);
}