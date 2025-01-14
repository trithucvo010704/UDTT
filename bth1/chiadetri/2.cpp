#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void merge(vector<int> &a, int l, int m, int r)
{ // Cat va sao chep thanh 2 mang
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = a[m + 1 + i];

    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            a[l] = left[i];
            ++i;
            ++l;
        }
        else
        {
            a[l] = right[j];
            ++j;
            ++l;
        }
    }
    while (i < left.size())
    {
        a[l] = left[i];
        ++i;
        ++l;
    }
    while (j < right.size())
    {
        a[l] = right[j];
        ++j;
        ++l;
    }
}

void merge_sort(vector<int> &a, int l, int r)
{
    int m = (l + r) / 2;
    if (l >= r)
        return;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
}
int main()
{
    ifstream in1("input1.txt");
    ofstream out1("output1.txt");
    if (!in1)
    {
        cout << " Khong the mo file doc va ghi dap an " << endl;
    }
    vector<int> ktao;
    string line;
    if (getline(in1, line))
    {
        stringstream ss(line);
        int num;
        while (ss >> num)
        {
            ktao.push_back(num);
        }
    }
    merge_sort(ktao, 0, ktao.size() - 1);
    // Ghi ket qua ra file
    for (int i = 0; i < ktao.size(); i++)
    {
        out1 << ktao[i];
        if (i < ktao.size() - 1)
        {
            out1 << " ";
        }
    }
    cout << "SX XONG KET Qua nam trong file output1.txt" << endl;
}