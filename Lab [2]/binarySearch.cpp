#include <iostream>
using namespace std;

void binarySearch(int *arr, int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid;
    int flag = 0;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            cout << "Target found at index " << mid << endl;
            flag = 1;
        }
        if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (flag != 1)
    {
        cout << "Target not found" << endl;
    }
}

int main()
{
    int arr[5] = {10, 15, 20, 25, 30};

    binarySearch(arr, 5, 20);
}