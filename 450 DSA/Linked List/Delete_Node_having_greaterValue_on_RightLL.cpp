// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* Reverse(Node *head)
    {
        Node *p,*q,*r;
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
    Node *compute(Node *head)
    {
        // your code goes here
        Node *p,*q;
        head = Reverse(head);
        
        p=q=head;
        int max=p->data;
        while(q!=NULL)
        {
            
            if(q->data<max)
            {
                p->next=q->next;
                q=p->next;
                
            }
            else
            {
                
                max=q->data;
                p=q;
                q=q->next;
            }
        }
        q=Reverse(head);
        return q;
        
        
    }
    // ANALYSIS:
    //TIME: O(n)
    // SPACE: O(1)
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends