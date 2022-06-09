// Right View of Binary Tree

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8

// Example 1:

// Input:
//        1
//     /    \
//    3      2
// Output: 1 2
// Example 2:

// Input:
//      10
//     /   \
//   20     30
//  /   \
// 40  60
// Output: 10 30 60
// Your Task:
// Just complete the function rightView() that takes node as parameter and returns the right view as a list.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.

    // RECURSIVE:
    void solve(Node *root, int &maxh, int curh, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            if (curh > maxh)
            {
                v.push_back(root->data);
                maxh = curh;
            }
            solve(root->right, maxh, curh + 1, v);
            solve(root->left, maxh, curh + 1, v);
        }
    }
    // ITERATIVE:
    void solve2(vector<int> &v, Node *root)
    {
        queue<Node *> q;
        if (root == NULL)
        {
            return;
        }
        q.push(NULL);
        q.push(root);
        while (q.size() != 1)
        {
            if (q.front() == NULL)
            {
                q.pop();
                v.push_back(q.front()->data);
                q.push(NULL);
            }
            else
            {

                Node *temp = q.front();
                q.pop();
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
    }
    vector<int> rightView(Node *root)
    {
        // Your Code here
        vector<int> v;
        int maxh = 0;
        int curh = 1;
        //   solve(root,maxh,curh,v);
        solve2(v, root);
        return v;
    }
};

// { Driver Code Starts.

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        Solution ob;
        vector<int> vec = ob.rightView(root);
        for (int x : vec)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends