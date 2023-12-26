#include <iostream>
using namespace std;

class Employee
{
public:
    int id;
    string name;

    Employee(int i, string n)
    {
        id = i;
        name = n;
    }
};

void BubbleSort(Employee arr[], int size, int (*func)(int, int))
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (func(arr[j].id, arr[j + 1].id))
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int biggerThan(int a, int b)
{
    return a < b;
}

int smallerThan(int a, int b)
{
    return a > b;
}
int main()
{

    Employee emp1(5, "Ali");
    Employee emp2(12, "Mohamed");
    Employee emp3(2, "Omar");

    Employee arr[3] = {emp1, emp2, emp3};

    BubbleSort(arr, 3, &smallerThan);
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i].id << endl;
    }
    BubbleSort(arr, 3, &biggerThan);

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i].id << endl;
    }
}