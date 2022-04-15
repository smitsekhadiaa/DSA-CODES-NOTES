// LRU Cache 
// Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

// SET x y : sets the value of the key x with value y
// GET x : gets the key of x if present else returns -1.

// The LRUCache class has two methods get() and set() which are defined as follows.

// get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
// set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
// In the constructor of the class the capacity of the cache should be intitialized.
 

// Example 1:

// Input:
// cap = 2
// Q = 2
// Queries = SET 1 2 GET 1
// Output: 2
// Explanation: 
// Cache Size = 2

// SET 1 2 GET 1
// SET 1 2 : 1 -> 2

// GET 1 : Print the value corresponding
// to Key 1, ie 2.

// Example 2:

// Input:
// cap = 2
// Q = 8
// Queries = SET 1 2 SET 2 3 SET 1 5
// SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
// Output: 5 -1
// Explanation: 
// Cache Size = 2
// SET 1 2 : 1 -> 2

// SET 2 3 : 1 -> 2, 2 -> 3 (the most recently 
// used one is kept at the rightmost position) 

// SET 1 5 : 2 -> 3, 1 -> 5

// SET 4 5 : 1 -> 5, 4 -> 5 (Cache size is 2, hence 
// we delete the least recently used key-value pair)

// SET 6 7 : 4 -> 5, 6 -> 7 

// GET 4 : Prints 5 (The cache now looks like
// 6 -> 7, 4->5)

// SET 1 2 : 4 -> 5, 1 -> 2 
// (Cache size is 2, hence we delete the least 
// recently used key-value pair)

// GET 3 : No key value pair having 
// key = 3. Hence, -1 is printed.

// Your Task:
// You don't need to read input or print anything . Complete the constructor and get(), set() methods of the class LRUcache. 


// Expected Time Complexity: O(1) for both get() and set().
// Expected Auxiliary Space: O(1) for both get() and set(). 
// (Although, you may use extra space for cache storage and implementation purposes).

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    class Node
    {
        public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key,int value)
        {
            this->key=key;
            this->value=value;
        }
    };
    
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap=0;
    unordered_map<int,Node*> m;
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        this->cap=cap;
        head->next=tail;
        tail->prev=head;
        head->prev=NULL;
        tail->next=NULL;
    }
    void addnode(Node* newnode)
    {
        Node* temp;
        temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
        
    }
    
    void deletenode(Node* delnode)
    {
        Node* delprev;
        Node* delnext;
        delprev=delnode->prev;
        delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)!=m.end())
        {
            Node * resnode=m[key];
            int res=resnode->value;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key]=head->next;
            return res;
        }
        else
        {
            return -1;
        }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if(m.find(key)!=m.end())
        {
            Node* existingnode=m[key];
            m.erase(key);
            deletenode(existingnode);
            
        
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        m[key]=head->next;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends