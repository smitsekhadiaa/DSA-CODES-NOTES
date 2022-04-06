

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
     
    
    void insertStart(int data)
    {
        Node * newnode=new Node(data);
        newnode->data=data;
        if(head==NULL)
        {
            head=newnode;
            newnode->next=NULL;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }

// ITERATIVE METHOD
    void reverseLL()
    {
        if(head==NULL)
        {
            cout<<head;
        }
        else
        {
            Node *p,*q,*r;  //SLIDING POINTERS used to reverse a linked list.p is the head,q and r are null.move r to q ;q to p and p to the next node.continue this process till p becomes null.all the three pointers appears to slide on the linklist.when p is null;assign the node on which q (last node) is there as head. and pointthe next of q on r after every increment in node.
            p=head;
            q=r=NULL;
            while(p!=NULL)
            {
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            head=q;
        }
    }

    //ANALYSIS:
    //TIME COMPLEXITY: O(n) as we are traversing through entire linked list once
    //3 pointers are required (sliding pointers)

    void RecursiveReverseLL(Node *q,Node *p)
    {
        
        if(p!=NULL)
        {
            RecursiveReverseLL(p,p->next);
            p->next=q;
        }
        else
        {
            head=q;
        }
    }



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
    LL.insertStart(20);
    LL.insertStart(40);
    LL.insertStart(60);
    LL.insertStart(70);
    LL.insertStart(50);
    LL.insertStart(90);
    LL.printLL(head);
    cout<<endl<<"in reverse order:"<<endl;
    LL.reverseLL();
    // LL.RecursiveReverseLL(head);
    LL.printLL(head);

    return 0;
}
