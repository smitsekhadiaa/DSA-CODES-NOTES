// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {

        //USING MAPS 


        map<int,int> mp;
    Node* prev = head;
    Node* cur = head->next;
    
    mp[prev->data] = 1;
    while(cur){
        if(mp[cur->data]>0){
            prev->next = cur->next;
            cur = prev->next;
        }
        else{
            mp[cur->data] = 1;
            prev = cur;
            cur = cur->next;
        }
    }
    return head;

    // ANALYSIS:
    // TIME: O(n)
    // SPACE: O(n) as we create new map and store exch node data in it.



    //USING UNORDERED SETS: 
    //   your code goes here
    //   if(head->next==NULL){
    //         return head;
    //     }
    //     unordered_set<int> s;
    //     s.insert(head->data);
    //     Node* prev=head;
    //     Node* temp=head->next;
    //     while(temp!=NULL){
    //         if(s.count(temp->data)==0){
    //              s.insert(temp->data);
    //              prev=prev->next;
    //              temp=temp->next;
    //         }
    //         else{
    //             prev->next=temp->next;
    //             temp=temp->next;
    //         }
                
    //         }
        // return head;
    }

    // ANALYSIS:
    // TIME: O(n)
    // SPACE: O(n) as we create new map and store exch node data in it.
   
};


// { Driver Code Starts.

int main() {
	// your code goes here
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
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  // } Driver Code Ends