// Segregate even and odd nodes in a Link List
// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.


// Example 1:

// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers 
// so they appear first and 17,15,9 are odd 
// numbers that appear later.

// Example 2:

// Input:
// N = 4
// Link List:
// 1 -> 3 -> 5 -> 7

// Output: 1 3 5 7

// Explaination: There is no even number. 
// So ne need for modification.


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
        cout << node->data <<" "; 
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

// METHOD 1 

#include <vector>
class Solution{
public:
Node* reverse1(Node *head)
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
    Node* divide(int N, Node *head){
    //     // code here
    
    Node *even,*odd,*e,*o,*p;
        even=NULL;
        odd=NULL;
        e=NULL;
        o=NULL;
        p=head;
        
        while(p!=NULL)
        {
            if(p->data%2==0)
            {
                if(even==NULL)
                {
                    even=p;
                    e=p;
                }
                else
                {
                    e->next=p;
                    e=p;
                }
            }
            else
            {
                if(odd==NULL)
                {
                    odd=p;
                    o=p;
                }
                else
                {
                    o->next=p;
                    o=p;
                }
            }
            p=p->next;
        }
        if(e)
        {
            e->next=odd;
        }
        if(o)
        {
            o->next=NULL;
        }
        if(even)
        {
            return even;
        }
        else
        {
            return odd;
        }
        return head;

        // ANALYSIS OF METHOD 1:
        // TIME:O(n)
        // SPACE: O(1)
        
    
    // METHOD 2: USING VECTORS
    
      Node *p,*q;
      p=head;
      q=head;
      vector <int> v1,v2;
      while(p!=NULL)
      {
          if(p->data%2==0)
          {
              v1.push_back(p->data);
          }
          else{
              v2.push_back(p->data);
          }
          p=p->next;
      }
      p=head;
      reverse(v1.begin(),v1.end());
      reverse(v2.begin(),v2.end());
      while(!v1.empty())
      {
           
          p->data=v1.back();
          v1.pop_back();
          p=p->next;
           
      }
      while(!v2.empty())
      {
          p->data=v2.back();
          v2.pop_back();
          p=p->next;
          
      }

      return head;
       
    }
};

// ANALYSIS:
// TIME:O(n)
// SPACE:O(1)

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends