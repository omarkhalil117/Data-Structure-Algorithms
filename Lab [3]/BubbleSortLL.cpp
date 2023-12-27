#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    // attributes
    T data;
    Node *next;
    Node *prev;

    // constructor
    Node()
    {
        data = T();
        next = prev = nullptr;
    }

    Node(T d)
    {
        data = d;
        next = prev = nullptr;
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *pHead;
    Node<T> *pTail;
    int count;

    LinkedList()
    {
        pHead = pTail = nullptr;
        count = 0;
    }

    LinkedList(const LinkedList<T> &other)
    {
        pHead = pTail = nullptr;
        count = 0;

        Node<T> *current = other.pHead;
        while (current != nullptr)
        {
            add(current->data);
            current = current->next;
        }
    }

    ~LinkedList()
    {
        clearList();
    }

    void add(T d)
    {
        Node<T> *newNode = new Node<T>(d);

        if ((pHead == nullptr) && (pTail == nullptr))
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

    Node<T> *search(T d)
    {
        if (pHead == nullptr)
        {
            cout << "Nothing to display" << endl;
        }

        Node<T> *ptr = pHead;

        while (ptr != nullptr)
        {
            if (ptr->data == d)
            {
                return ptr;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        cout << "Not found" << endl;
        return nullptr;
    }

    void clearList()
    {
        Node<T> *p = new Node<T>();

        while (pHead != nullptr)
        {
            p = pHead;
            pHead = pHead->next;
            delete p;
        }
        pTail = nullptr;
        count = 0;
    }

    void deleteNode(T val)
    {
        Node<T> *pDelete = search(val);

        if (pDelete == nullptr)
        {
            cout << "Node not found " << endl;
        }
        else
        {
            if (pDelete == pHead)
            {
                if (pDelete == pTail)
                {
                    pHead = pTail = nullptr;
                    delete pDelete;
                }
                else
                {
                    pHead = pHead->next;
                    pHead->prev = nullptr;
                    delete pDelete;
                }
            }
            else if (pDelete == pTail)
            {
                pTail = pTail->prev;
                pTail->next = nullptr;
                delete pDelete;
            }
            else
            {
                pDelete->prev->next = pDelete->next;
                pDelete->next->prev = pDelete->prev;
                delete pDelete;
            }
            count--;
        }
    }

    void insertAfter(T val, T d)
    {
        Node<T> *p = new Node<T>();
        p = search(val);

        if (p == pTail)
        {
            add(d);
        }
        else
        {
            Node<T> *newNode = new Node<T>(d);
            newNode->next = p->next;
            newNode->prev = p;
            p->next->prev = newNode;
            p->next = newNode;
            count++;
        }
    }

    void bubbleSort()
    {
        if (pHead == nullptr || pHead->next == nullptr)
            return;

        bool swapped;
        Node<T> *current;
        Node<T> *last = nullptr;

        do
        {
            swapped = false;
            current = pHead;

            while (current->next != last)
            {
                if (current->data > current->next->data)
                {
                    swapNodes(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

    void swapNodes(Node<T> *node1, Node<T> *node2)
    {
        T temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
};

int main()
{
    LinkedList<int> l1;
    l1.add(5);
    l1.add(14);
    l1.add(20);
    l1.add(3);
    l1.add(9);

    cout << "Original List: ";
    l1.display();

    l1.bubbleSort();

    cout << "Sorted List: ";
    l1.display();

    return 0;
}