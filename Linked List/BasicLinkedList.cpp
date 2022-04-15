// Inserting at start,before any given value, after any given value, end; deleteing at start,value in between,end;searching if a element is present in linked list or not,printing linked list.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1)
    {
        data = data1;
        next == NULL;
    }
} *head = NULL, *temp;

class LinkedList
{
public:
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertStart(int data)
    {
        Node *newnode = new Node(data);
        newnode->data = data;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAfterValue(int data1, int value)
    {
        Node *newnode = new Node(data1);

        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            Node *p = NULL;
            p = head;
            while (p != NULL && p->data != value)
            {
                p = p->next;
            }
            newnode->next = p->next;
            p->next = newnode;
        }
    }

    void insertBeforeValue(int data1, int value)
    {
        Node *newnode = new Node(data1);
        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            Node *p, *q;
            q = NULL;
            p = head;
            while (p->next->data != value)
            {
                p = p->next;
            }
            newnode->next = p->next;
            p->next = newnode;
        }
    }

    void insertEnd(int data)
    {
        Node *newnode = new Node(data);
        Node *p;
        p = head;
        if (head == NULL)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else

        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = newnode;
            newnode->next = NULL;
        }
    }

    int deleteStart()
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            Node *p = head;
            head = head->next;
            int x = p->data;
            delete p;
            return x;
        }
    }

    int deleteMiddle(int value)
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            Node *p = head, *q = NULL;
            while (p->data != value)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            int x = p->data;
            delete p;
            return x;
        }
    }

    int deleteEnd()
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            Node *p = head;
            while (p->next->next != NULL)
            {
                p = p->next;
            }
            int x = p->next->data;
            p->next = NULL;
            return x;
        }
    }

    int searching(int value)
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            Node *p = head;

            while (p->data != value)
            {
                p = p->next;
            }
            int x = p->data;
            cout << x << " is Present in the LinkedList" << endl;
            return x;
        }
    }

    void reverseLL()
    {
        if (head == NULL)
        {
            cout << head;
        }
        else
        {
            Node *p, *q, *r; // SLIDING POINTERS used to reverse a linked list.p is the head,q and r are null.move r to q ;q to p and p to the next node.continue this process till p becomes null.all the three pointers appears to slide on the linklist.when p is null;assign the node on which q (last node) is there as head. and pointthe next of q on r after every increment in node.
            p = head;
            q = r = NULL;
            while (p != NULL)
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            }
            head = q;
        }
    }

    void printLL(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " " << endl;
            head = head->next;
        }
    }
};

int main()
{
    LinkedList LL;
    LL.insertStart(20);
    LL.insertStart(40);
    LL.insertStart(60);
    LL.insertStart(80);
    LL.printLL(head);

    LL.insertEnd(50);
    LL.printLL(head);

    LL.insertAfterValue(30, 60);
    LL.printLL(head);

    LL.insertBeforeValue(100, 20);
    LL.printLL(head);

    LL.deleteStart();
    LL.printLL(head);

    LL.deleteEnd();
    LL.printLL(head);

    LL.deleteMiddle(60);
    LL.printLL(head);

    LL.searching(40);

    LL.reverseLL();
    LL.printLL(head);

    return 0;
}
