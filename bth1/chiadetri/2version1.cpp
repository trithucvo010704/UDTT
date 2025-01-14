#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Hàm merge hai nửa
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    // Copy dữ liệu vào hai mảng tạm
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0;

    // Gộp hai mảng tạm lại
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[left] = L[i];
            ++left;
            ++i;
        }
        else
        {
            arr[left] = R[j];
            ++left;
            ++j;
        }
    }

    // Copy các phần tử còn lại
    while (i < n1)
    {
        arr[left] = L[i];
        ++left;
        ++i;
    }
    while (j < n2)
    {
        arr[left] = R[j];
        ++left;
        ++j;
    }
}

// Hàm đệ quy để thực hiện merge sort
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Hàm chính
int main()
{
    std::ifstream inputFile("input1.txt");
    std::ofstream outputFile("output1.txt");

    if (!inputFile)
    {
        std::cerr << "Không thể mở file input.txt để đọc.\n";
        return 1;
    }

    if (!outputFile)
    {
        std::cerr << "Không thể mở file output.txt để ghi.\n";
        return 1;
    }

    // Đọc dữ liệu từ file input
    std::vector<int> numbers;
    std::string line;
    if (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        int num;
        while (ss >> num)
        {
            numbers.push_back(num);
        }
    }

    // Sắp xếp mảng bằng Merge Sort
    mergeSort(numbers, 0, numbers.size() - 1);

    // Ghi kết quả vào file output
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        outputFile << numbers[i];
        if (i < numbers.size() - 1)
        {
            outputFile << " ";
        }
    }

    std::cout << "Ket Qua trong file output1.txt.\n";

    // Đóng file
    inputFile.close();
    outputFile.close();

    return 0;
}
