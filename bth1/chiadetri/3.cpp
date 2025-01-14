#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm giá trị lớn nhất trong mảng bằng chia để trị
float findMax(const vector<float> &arr, int left, int right)
{
    // Trường hợp cơ sở: chỉ có một phần tử
    if (left == right)
    {
        return arr[left];
    }

    // Chia mảng thành hai nửa
    int mid = (left + right) / 2;

    // Tìm giá trị lớn nhất ở nửa trái và nửa phải
    float maxLeft = findMax(arr, left, mid);
    float maxRight = findMax(arr, mid + 1, right);

    // Kết hợp kết quả
    return max(maxLeft, maxRight);
}

int main()
{
    // Khởi tạo mảng với kiểu float
    vector<float> arr = {1.5, 5.2, 3.1, 9.8, 2.6, 8.4, 7.9, 4.3};

    // Tìm giá trị lớn nhất
    float maxVal = findMax(arr, 0, arr.size() - 1);

    // In ra giá trị lớn nhất
    cout << "Gia tri lon nhat trong mang: " << maxVal << endl;

    return 0;
}
