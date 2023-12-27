#include <iostream>
using namespace std;

template <class T>

class Node
{
public:
    Node<T> *next;
    Node<T> *prev;
    T data;

    Node<T>()
    {
        prev = next = nullptr;
        data = T();
    }
    Node<T>(T d)
    {
        prev = next = nullptr;
        data = d;
    }
};

template <class T>

class Queue
{
public:
    Node<T> *pHead;
    Node<T> *pTail;
    int count;

    Queue()
    {
        pHead = pTail = nullptr;
        count = 0;
    }

    ~Queue()
    {
        while (pHead != nullptr)
        {
            Node<T> *ptr = pHead;
            pHead = pHead->next;
            delete ptr;
        }
    }

    Queue(const Queue<T> &current)
    {
        pHead = pTail = nullptr;
        count = 0;
        Node<T> *curr = current.pHead;
        while (curr != nullptr)
        {
            enqueue(curr->data);
            curr = curr->next;
        }
    }
    void enqueue(T d)
    {
        Node<T> *newNode = new Node<T>(d);
        newNode->next = nullptr;

        if (pHead == nullptr)
        {
            pHead = pTail = newNode;
        }
        else
        {
            pTail->next = newNode;
            newNode->prev = pTail;
            pTail = newNode;
        }
        count++;
    }

    T dequeue()
    {
        T out;
        if (pHead == nullptr)
        {
            cout << "Nothing to display" << endl;
            return T();
        }

        Node<T> *p = pHead;

        out = p->data;
        pHead = pHead->next;

        if (!pHead)
        {
            pHead = nullptr;
            delete p;
            count--;
            return out;
        }

        pHead->prev = nullptr;
        delete p;
        count--;
        return out;
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

    void reverseQueue()
    {
        Node<T> *ptr = pHead;

        while (ptr != nullptr)
        {
            Node<T> *temp = ptr->next;
            ptr->next = ptr->prev;
            ptr->prev = temp;
            ptr = ptr->prev;
        }

        ptr = pHead;
        pHead = pTail;
        pTail = ptr;
    }
};

int main()
{

    Queue<int> q1;

    q1.enqueue(5);
    q1.enqueue(12);
    q1.enqueue(7);
    q1.enqueue(20);

    int x = q1.dequeue();
    int y = q1.dequeue();

    cout << "X : " << x << "  Y : " << y << endl;

    Queue<int> q2 = q1;

    q2.enqueue(10);

    cout << "Queue 1 :  " << endl;
    q1.display();

    cout << "Queue 2 :  " << endl;
    q2.display();

    cout << "Queue 1 Reversed" << endl;
    q1.reverseQueue();
    q1.display();
}
