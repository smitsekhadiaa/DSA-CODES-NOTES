// Add two numbers represented by linked lists

// Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

// The sum list is a linked list representation of the addition of two input numbers from the last.

// Example 1:

// Input:
// N = 2
// valueN[] = {4,5}
// M = 3
// valueM[] = {3,4,5}
// Output: 3 9 0  
// Explanation: For the given two linked
// list (4 5) and (3 4 5), after adding
// the two linked list resultant linked
// list will be (3 9 0).
// Example 2:

// Input:
// N = 2
// valueN[] = {6,3}
// M = 1
// valueM[] = {7}
// Output: 7 0
// Explanation: For the given two linked
// list (6 3) and (7), after adding the
// two linked list resultant linked list
// will be (7 0).

// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head)
    {
        Node *prev,*cur,*nex;
        prev=NULL;
        cur=head;
        nex=NULL;
        while(cur!=NULL)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
            
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node *res,*temp,*cur;
        
        res=NULL;
        cur=NULL;
        int s=0,c=0;
        first=reverse(first);
        second=reverse(second);
        while(first!=NULL || second!=NULL)
        {
            s=c+(first?first->data:0)+(second?second->data:0);
            c=(s>=10)?1:0;
            s=s%10;
            temp=new Node(s);
            if(res==NULL)
            {
                res=temp;
            }
            else{
                cur->next=temp;
                
            }
            cur=temp;
            if(first)
            {
                first=first->next;
            }
            if(second)
            {
                second=second->next;
            }
        }
        if(c>0)
        {
            temp = new Node(c);
            cur->next=temp;
            cur=temp;
        }
        res=reverse(res);
        return res;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends