// Move last element to front of a given Linked List
// Write a function that moves the last element to the front in a given Singly Linked List. For example, if the given Linked List is 1->2->3->4->5, then the function should change the list to 5->1->2->3->4.

#include <iostream>
using namespace std;

class Node
{
    public:
    int data;    
     Node * next;
    Node(int data1)
    {
        data=data1;
        next==NULL;
    }
}*head=NULL,*temp;


class LinkedList
{
    public:
    void insertEnd(int data)
    {
        Node *newnode= new Node(data);
        Node *p;
        p=head;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
        }
        else

        {
            while (p->next!=NULL)
            {
                p=p->next;
            }
            p->next=newnode;
            newnode->next=NULL;
        }
        
    }


    void lastToFirst()  
    {
        Node * p=head;
        Node *q=NULL;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        p->next=head;
        head=p;
        q->next=NULL;
    }

    //ANALYSIS:
    //TIME Complexity: O(n) as we are traversing through the LL once where n is the number of nodes in the LL
    //2 pointers are required



    void printLL(Node * head)
    {
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    }
};



int main()
{
    LinkedList LL;
    cout<<"Linked list"<<endl;
    LL.insertEnd(10);
    LL.insertEnd(20);
    LL.insertEnd(30);
    LL.insertEnd(40);
    LL.insertEnd(50);
    LL.printLL(head);
    cout<<endl<<"after moving last element to first:"<<endl;
    LL.lastToFirst();
    LL.printLL(head);
    return 0;
}
