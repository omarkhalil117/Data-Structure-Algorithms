#include <iostream>
using namespace std;

int sentinalSearch(int *arr, int size, int target)
{
    int last = arr[size - 1];
    arr[size - 1] = target;
    int i = 0;
    while (arr[i] != target)
    {
        i++;
    }
    arr[size - 1] = last;
    if ((i < size - 1) || (target == arr[size - 1]))
    {
        cout << "Found at index" << i;
    }
    else
    {
        cout << "Not Found";
    }
}

int main()
{
    int arr[5] = {2, 34, 20, 11, 15};

    sentinalSearch(arr, 5, 34);
}