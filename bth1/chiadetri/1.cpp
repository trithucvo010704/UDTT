#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct HS
{
    string hodem, ten;
    int namsinh;
    string diachi;
};
void inHS(HS a)
{
    cout << "Ho dem : " << a.hodem << " --> Ten : " << a.ten << "---> Namsinh : " << a.namsinh << "--> DiaChi : " << a.diachi << endl;
}
void SwapHS(HS &a, HS &b)
{
    HS Temp = a;
    a = b;
    b = Temp;
}
void quicksort(vector<HS> &DS, int l, int r)
{
    if (l >= r)
        return; // Điều kiện dừng

    int i = l, j = r;
    string pivot = DS[(l + r) / 2].ten; // Lưu giá trị pivot

    while (i <= j)
    {
        while (DS[i].ten < pivot)
            i++; // Tìm phần tử lớn hơn hoặc bằng pivot
        while (DS[j].ten > pivot)
            j--; // Tìm phần tử nhỏ hơn hoặc bằng pivot

        if (i <= j)
        {
            SwapHS(DS[i], DS[j]); // Hoán đổi hai phần tử
            i++;
            j--;
        }
    }

    // Đệ quy sắp xếp hai phần
    if (l < j)
        quicksort(DS, l, j);
    if (i < r)
        quicksort(DS, i, r);
}

void S(vector<HS> &DS)
{
    quicksort(DS, 0, DS.size() - 1);
}
int T(vector<HS> &DS, string ten)
{
    int l = 0, r = DS.size() - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ten == DS[m].ten)
        {
            return m;
        }
        else if (ten > DS[m].ten)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1; // K thay
}
int main()
{
    // Khởi tạo danh sách học sinh
    vector<HS> danhSach = {
        {"Nguyen Van", "A", 2005, "Ha Noi"},
        {"Le Thi", "B", 2004, "Hai Phong"},
        {"Tran Van ", "F", 2003, "Da Nang"},
        {"Pham Thi ", "D", 2005, "Hue"},
        {"Hoang Van ", "D", 2006, "Ho Chi Minh"},
        {"Nguyen Thi ", "C", 2004, "Can Tho"}};

    // Hiển thị danh sách trước khi sắp xếp
    cout << "Danh sach truoc khi sap xep:\n";
    for (const auto &hs : danhSach)
    {
        inHS(hs);
    }

    // Sắp xếp danh sách theo tên
    S(danhSach);

    // Hiển thị danh sách sau khi sắp xếp
    cout << "\nDanh sach sau khi sap xep:\n";
    for (const auto &hs : danhSach)
    {
        inHS(hs);
    }

    // Tìm kiếm học sinh theo tên
    string tenCanTim;
    cout << "\nNhap ten hoc sinh can tim: ";
    getline(cin, tenCanTim);

    int viTri = T(danhSach, tenCanTim);
    if (viTri != -1)
    {
        cout << "\nHoc sinh tim thay o vi tri " << viTri + 1 << ":\n";
        inHS(danhSach[viTri]);
    }
    else
    {
        cout << "\nKhong tim thay hoc sinh co ten \"" << tenCanTim << "\".\n";
    }

    return 0;
}