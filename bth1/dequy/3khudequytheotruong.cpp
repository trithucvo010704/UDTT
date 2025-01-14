#include <bits/stdc++.h>
using namespace std;
struct call
{
    int n;
    char a, b, c;
};
struct Stack
{
    int top;
    call *e;
};
void init(Stack &a)
{
    a.top = -1;
    a.e = NULL;
}
void empty(Stack a)
{
    return a.top == -1;
}

void push(Stack &a, call vao)
{
    if (empty(a))
        a.e = new call[1];
    else
    {
        a.e = (call *)realloc(a.e, (a.top + 2) * sizeof(call)); // cap phat them bo nho
    }
    a.top++;
    a.e[top] = vao;
}
void pop(Stack &a, call &ra)
{
    if (empty(a))
        return;
    ra = a.e[top];
    if (a.top == 0)
    {
        delete[] a.e;
        init(a);
    }
    else
    {
        a.e = (call *)realloc(a.e, a.top * sizeof(call)); // top n-1 ;
        a.top--;
    }
}
voi thaphanoi(call dau)
{
    call ra;
    Stack s;
    init(s);
    push(s, dau);
    while (!empty(s))
    {
        pop(s, ra);
    }
    if (ra.n == 1)
    {
        cout << "Chuyen 1 dia tu " << ra.a << " ==> " << ra.c << endl;
    }
    else
    {
    }
}