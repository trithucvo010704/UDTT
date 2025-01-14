#include <bits/stdc++.h>
using namespace std;
double sumODD(vector<double> a, int left, int right)
{
    if (left == right)
    {
        return a[left] > 0 ? a[left] : 0;
    }
    int m = (left + right) / 2;
    double sum_trai = sumODD(a, left, m);
    double sum_phai = sumODD(a, m + 1, right);
    return sum_trai + sum_phai;
}
main()
{
    vector<double> a = {-1, -2, -3, 3, 41, 3.3, 4.2, -1, -5.4};
    cout << sumODD(a, 0, a.size() - 1) << endl;
}
