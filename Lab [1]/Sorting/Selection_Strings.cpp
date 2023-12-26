#include <iostream>
using namespace std;

void SelectionSortStr(string arr[], int size)
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
        if (minIndx != i)
        {
            // swap item[min_idx] and item[i]
            swap(arr[i], arr[minIndx]);
        }
    }
}

int main()
{

    string names[2] = {"Omar", "Ahmed"};

    SelectionSortStr(names, 2);

    for (int i = 0; i < 2; i++)
    {
        cout << names[i] << endl;
    }
}
