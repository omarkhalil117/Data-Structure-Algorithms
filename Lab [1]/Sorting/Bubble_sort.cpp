#include <iostream>
using namespace std;
template <typename T>

void BubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int arr[5] = {5, 2, 4, 1, 3};
    // float arr[5] = {5.7, 2.1, 4.5, 1.5, 3.2};
    BubbleSort<int>(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

// void BubbleSort( T arr[], int size)
// {
//     for (int i = 0; i < size - 1; i++)
//     {
//         for (int j = 0; j < size - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 T temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// void swap(int &x, int &y)
// {
//     int temp = x;
//     x = y;
//     x = temp;
// }