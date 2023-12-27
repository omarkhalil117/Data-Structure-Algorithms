#include <iostream>
using namespace std;

template <class T>

class Node
{
public:
    Node<T> *next;
    T data;

    Node<T>()
    {
        next = nullptr;
        data = T();
    }
    Node<T>(T d)
    {
        next = nullptr;
        data = d;
    }
};

template <class T>

class Stack
{
public:
    Node<T> *pHead;
    int count;

    Stack()
    {
        pHead = nullptr;
        count = 0;
    }

    Stack(T d)
    {
        Node<T> *newNode = new Node<T>(d);
        pHead = newNode;
        count++;
    }

    ~Stack()
    {
        while (!pHead)
        {

            Node<T> *ptr = pHead;
            pHead = pHead->next;
            delete ptr;
        }
    }

    Stack(const Stack<T> &current)
    {
        pHead = nullptr;
        count = 0;
        Node<T> *curr = current.pHead;
        while (curr != nullptr)
        {
            push(curr->data);
            curr = curr->next;
        }
    }

    void push(T d)
    {
        Node<T> *newNode = new Node<T>(d);

        if (pHead == nullptr)
        {
            pHead = newNode;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = pHead;
            pHead = newNode;
        }

        count++;
    }

    T pop()
    {
        if (pHead == nullptr)
        {
            cout << "Empty Stack" << endl;
            return T();
        }
        else
        {
            Node<T> *pdel = pHead;
            pHead = pHead->next;
            T poppedData = pdel->data;
            delete pdel;
            count--;
            return poppedData;
        }
    }

    void display()
    {
        if (pHead == nullptr)
        {
            cout << "Nothing to display" << endl;
        }
        Node<T> *ptr = pHead;
        while (ptr != nullptr)
        {
            cout << ptr->data << "\t";
            ptr = ptr->next;
        }
        cout << endl;
    }

    void mergeStack(Stack<T> &S)
    {
        Node<T> *p = new Node<T>();
        Node<T> *pBefore = new Node<T>();
        p = pHead;
        while (p->next != nullptr)
        {
            p = p->next;
        }

        p->next = S.pHead;
        count += S.count;
    }

    void reverseStack()
    {
        Stack<T> temp;
        while (pHead != nullptr)
        {
            temp.push(pop());
        }

        pHead = temp.pHead;
    }
};

int main()
{

    Stack<int> s;
    s.push(5);
    s.push(13);
    s.push(18);

    Stack<int> s2;
    s2.push(25);
    s2.push(10);
    s2.push(29);

    cout << "Stack 1:" << endl;
    s.display();

    cout << "Stack 2:" << endl;
    s2.display();

    cout << "Copy" << endl;
    Stack<int> s3 = s2;
    s3.display();

    cout << "Merged" << endl;
    s.mergeStack(s2);
    s.display();

    cout << "Reversed" << endl;
    s.reverseStack();
    s.display();
}
