#include <iostream>
#include <vector>
using namespace std;

// Kiểm tra xem nước đi có hợp lệ hay không
bool kiemTraHopLe(int x, int y, int n, vector<vector<int>> &banCo)
{
    return (x >= 0 && x < n && y >= 0 && y < n && banCo[x][y] == 0);
}

// Hàm đệ quy để giải bài toán
bool giaiMaQuanMa(int x, int y, int buocThu, vector<vector<int>> &banCo, int n,
                  vector<int> &buocX, vector<int> &buocY)
{
    if (buocThu == n * n + 1)
    {
        return true; // Đã đi hết tất cả các ô
    }

    for (int i = 0; i < 8; i++)
    {
        int xTiepTheo = x + buocX[i];
        int yTiepTheo = y + buocY[i];

        if (kiemTraHopLe(xTiepTheo, yTiepTheo, n, banCo))
        {
            banCo[xTiepTheo][yTiepTheo] = buocThu; // Đánh dấu bước đi

            if (giaiMaQuanMa(xTiepTheo, yTiepTheo, buocThu + 1, banCo, n, buocX, buocY))
            {
                return true;
            }

            banCo[xTiepTheo][yTiepTheo] = 0; // Quay lui
        }
    }

    return false;
}

// Hàm chính để giải bài toán
void timDuongDiQuanMa(int n)
{
    vector<vector<int>> banCo(n, vector<int>(n, 0));

    // Các bước di chuyển của quân mã
    vector<int> buocX = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> buocY = {1, 2, 2, 1, -1, -2, -2, -1};

    // Bắt đầu từ ô (0, 0)
    banCo[0][0] = 1;

    if (!giaiMaQuanMa(0, 0, 2, banCo, n, buocX, buocY))
    {
        cout << "Không tìm thấy lời giải." << endl;
    }
    else
    {
        cout << "Tìm thấy lời giải:" << endl;
        for (const auto &hang : banCo)
        {
            for (int o : hang)
            {
                cout << o << "\t";
            }
            cout << endl;
        }
    }
}

// Hàm main để chạy chương trình
int main()
{
    int n;
    cout << "Nhập kích thước bàn cờ (n): ";
    cin >> n;

    timDuongDiQuanMa(n);

    return 0;
}
