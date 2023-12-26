#include <iostream>
using namespace std;
template <typename T>
void SelectionSort(T arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int minIndx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndx])
            {
                minIndx = j;
            }
        }
        swap(arr[i], arr[minIndx]);
    }
}

int main()
{

    int arr[5] = {5, 2, 4, 1, 3};
    SelectionSort<int>(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    string names[2] = {"Omar", "Ahmed"};

    SelectionSort<string>(names, 2);

    for (int i = 0; i < 2; i++)
    {
        cout << names[i] << endl;
    }
}
