#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    int i, j;
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[start + i];
    }

    for (int j = 0; j < size2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    int k = start;

    i = j = 0;

    while ((i < size1) && (j < size2))
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }

        k++;
    }

    while (i < size1)
    {
        arr[k] = arr1[i];
        k++;
        i++;
    }
    while (j < size2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[5] = {4, 3, 15, 26, 6};

    mergeSort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
}