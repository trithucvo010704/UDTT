// Ma di tuan
#include <bits/stdc++.h>
using namespace std;

// 1 ham kiem tra buoc di hop le tren ban co

bool check(int x, int y, int n, vector<vector<int>> &banco)
{
    // kiem tra nam trong ban co vo o xy chua di qua
    return (x >= 0 && x < n && y >= 0 && y < n && banco[x][y] == 0);
}
bool checkmadituan(int x, int y, int buocthu, vector<vector<int>> &banco, int n, vector<int> &DX, vector<int> &DY)
{
    if (buocthu == (n * n) + 1)
    {
        return true; // di het ban co thi dung
    }
    for (int i = 0; i < 8; i++)
    {
        // chung ta se tra ra biet tiep theo trong 8 kha nang cua quan ma hop le
        int nextx = x + DX[i];
        int nexty = y + DY[i];
        if (check(nextx, nexty, n, banco))
        {
            banco[nextx][nexty] = buocthu;
            if (checkmadituan(nextx, nexty, buocthu + 1, banco, n, DX, DY))
            {
                return true;
            }
            banco[nextx][nexty] = 0; // Quay lui
        }
    }
    return false; // duyet het kha nang
}

void madituan(int n)
{
    // ktao ban co
    vector<vector<int>> banco(n, vector<int>(n, 0));
    // Ktao 8 kha nang
    vector<int> DX = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> DY = {1, 2, 2, 1, -1, -2, -2, -1};
    // cho ban co chay tu o 1 1 tuc la o 0 0
    banco[0][0] = 1;
    // neu duyet het kha nang o buoc thu 2 ma no van k dc thi cut
    if (!checkmadituan(0, 0, 2, banco, n, DX, DY))
    {
        cout << "Khong tim thay loi giai !" << endl;
    }
    else
    {
        cout << "Tim thay loi giai" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << banco[i][j] << "\t";
            }
            cout << endl;
        }
    }
}
main()
{
    madituan(7);
}