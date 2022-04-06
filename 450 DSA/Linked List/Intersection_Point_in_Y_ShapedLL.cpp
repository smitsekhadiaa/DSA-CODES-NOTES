// { Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// count nodes of first LL and Second LL and store the diff in a var d; now bring the longer LL till d nodes ahead. now both the LL are on the same height.now increase p and q til both the nodes become equal.

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *p,*q;
    p=head1;
    q=head2;
   
int count1=0,count2=0;
while(p!=NULL)
{
    count1++;
    p=p->next;
}
while(q!=NULL)
{
    count2++;
    q=q->next;
    
}
p=head1;  //bringing p and q back again to head after couting number of nodes present in both
q=head2;
int diff=0;
diff=abs(count1-count2);  //gives absolute value of count1-count2
if(count1>count2)
{
    for(int i=0;i<diff;i++)
    {
        p=p->next;
        
    }
    
}
else if(count2>count1){
    for(int i=0;i<diff;i++)
    {
        q=q->next;
    }
}
while(p!=q)
{
    p=p->next;
    q=q->next;
}
return p->data;
}

// TIME: O(m+n) where m is node of LL1 and n is node of LL2
// SPACE: O(1) c







