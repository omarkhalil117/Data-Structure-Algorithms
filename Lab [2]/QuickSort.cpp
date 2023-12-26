#include <iostream>
using namespace std;

int partition(int *arr, int st, int en)
{
    int pivot = arr[st];
    int indx = st;

    for (int i = st + 1; i <= en; i++)
    {
        if (arr[i] < pivot)
        {
            indx++;
            swap(arr[indx], arr[i]);
        }
    }
    swap(arr[indx], arr[st]);

    return indx;
}

void quickSort(int *arr, int lower, int upper)
{
    if (lower < upper)
    {
        int pivot = partition(arr, lower, upper);
        quickSort(arr, lower, pivot - 1);
        quickSort(arr, pivot + 1, upper);
    }
}

int main()
{
    int arr[5] = {4, 3, 15, 26, 6};

    quickSort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
}