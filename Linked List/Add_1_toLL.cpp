// Add 1 to a number represented as linked list 
// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Example 1:

// Input:
// LinkedList: 4->5->6
// Output: 457 
// Example 2:

// Input:
// LinkedList: 1->2->3
// Output: 124



// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
#include <vector>
class Solution
{
    public:
    Node* reverse(Node *head)
    {
        Node *prev,*nex,*cur;
        prev=NULL;
        nex=NULL;
        cur=head;
        while(cur!=NULL)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head=reverse(head);
        Node *p=head;
        bool flag=true;
        while(p!=NULL && flag==true)
        {
            if(p->data==9 && p->next==NULL)
            {
                p->data=1;
                Node *temp = new Node(0);
                temp->next=head;
                head=temp;
                p=p->next;
            }
            else if(p->data==9)
            {
                p->data=0;
                p=p->next;
            }
            else{
                p->data+=1;
                p=p->next;
                flag=false;
            }
        }
        head=reverse(head);
        return head;
        
    }
};

// ANALYSIS:
// TIME:O(N)
// SPACE:O(1)
// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends