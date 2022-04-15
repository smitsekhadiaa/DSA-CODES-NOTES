// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node *findIntersection(Node *head1, Node *head2)
{
    // OPTIMIZED CODE:

    Node *p, *q, *r;
    p = head1;
    q = head2;
    Node *head3 = NULL;
    r = NULL;
    while (p != NULL and q != NULL)
    {
        if (p->data == q->data)
        {
            if (head3 == NULL) // Checking if its the first node or not
            {
                Node *temp = new Node(p->data); // making new node
                head3 = temp;
                r = temp;
            }
            else // if ot the first node
            {
                Node *temp = new Node(p->data); // making new node
                r->next = temp;
                r = r->next;
            }
            p = p->next;
            q = q->next;
        }
        else
        {
            if (p->data < q->data) // agar p choota hai to  p ko aage badhao
            {
                p = p->next;
            }
            else // varna q ko aage badhao as this list is already sorted we can do this
            {
                q = q->next;
            }
        }
    }
    return head3;

    // TIME: O(m+n) where m is node of LL1 and n is nodes of LL2 this does the code in o of n time
    // SPACE: O(m+n) as new LL is being created and if all the elements are same in both LL you have to make that many nodes

    // Your Code Here
    // Node * head3=new Node(0);
    // Node *p,*q,*r,*s;
    // p=head1;
    // q=head2;
    // r=head3;

    // while(p!=NULL)
    // {
    //     q=head2;

    //     while(q!=NULL)
    // {

    //     if(p->data==q->data && head3->data!=p->data )
    //     {
    //         Node *temp=new Node(p->data);
    //         head3->next=temp;
    //         head3=head3->next;

    //     }
    //     q=q->next;
    // }
    // p=p->next;

    // }

    // return r->next;
    // TIME: O(m+n square) where m are no of elements of first and n are number of elements of second as we are iterating the second list n times
}