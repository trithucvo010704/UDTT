#include <bits/stdc++.h>
using namespace std;
void thaphanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Chuyen 1 dia tu " << a << " " << c << endl;
        return;
    }
    thaphanoi(n - 1, a, c, b);
    thaphanoi(1, a, b, c);
    thaphanoi(n - 1, b, a, c);
}
struct Call
{
    int n;
    char a;
    char b;
    char c;
};

void thaphanoi2(int n, char a, char b, char c)
{
    // push trang thai dau tien
    stack<Call> s;
    // push dau tien
    s.push({n, a, b, c});
    while (!s.empty())
    {
        Call curently = s.top(); // Lay ra dinh ngan xep va xoa
        s.pop();                 // Xoa ptu o dinh vua lay ra
        if (curently.n == 1)
        {
            cout << "Chuyen 1 dia tu cot " << curently.a << " ==> " << curently.c << endl;
        }
        else
        {
            // thuc hien push
            s.push({curently.n - 1, curently.a, curently.c, curently.b});
            s.push({1, curently.a, curently.b, curently.c});
            s.push({curently.n - 1, curently.b, curently.a, curently.c});
        }
    }
}
int main()
{

    thaphanoi2(3, 'A', 'B', 'C');
}