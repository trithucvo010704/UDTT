#include <iostream>
#include <stack>
using namespace std;

struct Call
{
    int n;  // Số lượng đĩa
    char a; // Cột nguồn
    char b; // Cột trung gian
    char c; // Cột đích
};

void thaphanoi2(int n, char a, char b, char c)
{
    // Push trạng thái đầu tiên
    stack<Call> s;
    s.push({n, a, b, c});

    while (!s.empty())
    {
        Call curently = s.top(); // Lấy ra đỉnh ngăn xếp và xóa
        s.pop();                 // Xóa phần tử ở đỉnh vừa lấy ra

        if (curently.n == 1)
        {
            cout << "Chuyen dia 1 tu " << curently.a << " sang " << curently.c << endl;
        }
        else
        {
            // Thực hiện push trạng thái theo thứ tự
            s.push({curently.n - 1, curently.b, curently.a, curently.c}); // Chuyển n-1 đĩa từ b sang c qua a

            s.push({1, curently.a, curently.b, curently.c});              // Chuyển đĩa lớn nhất từ a sang c
            s.push({curently.n - 1, curently.a, curently.c, curently.b}); // Chuyển n-1 đĩa từ a sang c qua b
        }
    }
}

int main()
{
    thaphanoi2(3, 'A', 'B', 'C');
    return 0;
}
