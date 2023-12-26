#include <iostream>
using namespace std;

class Employee
{

public:
    int id;
    string name;
    float salary;

    Employee(int _id, string _name, float _salary)
    {
        id = _id;
        name = _name;
        salary = _salary;
    }
};

int searchById(Employee arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].id == target)
        {
            return i;
        }
    }
    return -1;
}

int searchByName(Employee arr[], int size, string target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].name == target)
        {
            return i;
        }
    }
    return -1;
}

int searchBySalary(Employee arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].salary == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Employee emp1(1, "Ali", 2000);
    Employee emp2(2, "Ahmed", 4000);
    Employee emp3(3, "Salah", 5000);

    Employee arr[3] = {emp1, emp2, emp3};

    // search by id
    int res = searchById(arr, 3, 2);
    if (res != -1)
    {
        cout << "Employee found By ID at index number :  " << res << endl;
    }
    else
    {
        cout << "Employee not found" << endl;
    }

    // search by name
    res = searchBySalary(arr, 3, 3000);
    if (res != -1)
    {
        cout << "Employee found By Salary at index number  :  " << res << endl;
    }
    else
    {
        cout << "Employee not found" << endl;
    }

    // search by salary
    res = searchByName(arr, 3, "Salah");
    if (res != -1)
    {
        cout << "Employee found By Name at index number : " << res << endl;
    }
    else
    {
        cout << "Employee not found" << endl;
    }

    return 0;
}