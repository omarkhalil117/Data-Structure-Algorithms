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

    LinkedList(const LinkedList<T> &list)
    {
        pHead = pTail = nullptr;
        count = 0;
        Node<T> *cpyNode = list.pHead;
        while (cpyNode != nullptr)
        {
            add(cpyNode->data);
            cpyNode = cpyNode->next;
        }
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
            return nullptr;
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
    int search2(T d)
    {
        if (pHead == nullptr)
        {
            cout << "Nothing to Search for" << endl;
            return -1;
        }

        int indx = 0;

        Node<T> *ptr = pHead;

        while (ptr != nullptr)
        {
            if (ptr->data == d)
            {
                return indx;
            }
            else
            {
                ptr = ptr->next;
                indx++;
            }
        }
        cout << "Not found" << endl;
        return -1;
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
        }
    }

    void deleteNode2(int indx)
    {
        // int deleteIndx = search2(val);

        Node<T> *p = new Node<T>();
        p = pHead;
        for (int i = 0; i < indx; i++)
        {
            p = p->next;
        }

        if ((indx < 0) || (indx > count - 1))
        {
            cout << "Value not found" << endl;
            return;
        }
        else if (indx == 0)
        {
            if (pHead == pTail)
            {
                pHead = pTail = nullptr;
                delete p;
            }
            else
            {
                pHead = pHead->next;
                pHead->prev = nullptr;
                delete p;
            }
        }
        else if (indx == count - 1)
        {
            pTail = pTail->prev;
            pTail->next = nullptr;
            delete p;
        }
        else
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
    }

    void insertAfter(T val, T d)
    {
        Node<T> *p = new Node<T>();
        p = search(val);

        if (p == nullptr)
        {
            cout << "Value not found" << endl;
            return;
        }

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

    void insertAfter2(int indx, T d)
    {
        Node<T> *p = new Node<T>();
        p = pHead;
        for (int i = 0; i < indx; i++)
        {
            p = p->next;
        }

        if (p == nullptr)
        {
            cout << "Value not found" << endl;
            return;
        }

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

    void reverseList()
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
    LinkedList<int> l1;

    l1.add(5);
    l1.add(14);
    l1.add(20);

    cout << "Before insertion" << endl;
    l1.display();

    l1.insertAfter2(1, 15);
    // l1.insertAfter(20, 15);

    cout << "After Insertion" << endl;
    l1.display();

    l1.reverseList();

    l1.deleteNode2(1);

    cout << "After Delete : " << endl;
    l1.display();
    // l1.deleteNode(5);
    // l1.deleteNode(15);

    // LinkedList<int> l2 = l1;

    // cout << "Reversed List" << endl;
    // l2.display();

    // l2.deleteNode(15);

    // cout << "list 1" << endl;
    // l1.display();
    // cout << "list 2" << endl;
    // l2.display();
    return 0;
}