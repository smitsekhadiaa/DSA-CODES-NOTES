// Bottom View of Binary Tree
// Medium Accuracy: 45.32% Submissions: 100k+ Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

//                       20
//                     /    \
//                   8       22
//                 /   \     /   \
//               5      3 4     25
//                      /    \      
//                  10       14

// For the above tree the output should be 5 10 4 14 25.

// Example 1:

// Input:
//        1
//      /   \
//     3     2
// Output: 3 1 2
// Explanation:
// First case represents a tree with 3 nodes
// and 2 edges where root is 1, left child of
// 1 is 3 and right child of 1 is 2.

// Thus nodes of the binary tree will be
// printed as such 3 1 2.
// Example 2:

// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 40 20 60 30
// Your Task:
// This is a functional problem, you don't need to care about input, just complete the function bottomView() which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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

vector<int> bottomView(Node *root);

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

// } Driver Code Ends
// Function to return a list containing the bottom view of the given tree.

class Solution
{
public:
    void solve(Node *root, vector<int> &v)
    {
        queue<pair<Node *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, pair<Node *, int>> mp;
        if (root == NULL)
        {
            return;
        }
        while (!q.empty())
        {
            Node *t = q.front().first;
            int line = q.front().second.first;
            int h = q.front().second.second;
            q.pop();
            pair<Node *, int> p = {t, h};
            if (mp.find(line) == mp.end())
            {
                mp[line] = p;
            }
            else
            {
                if (mp[line].second <= h)
                {
                    mp[line].second = h;
                    mp[line].first = t;
                }
            }
            if (t->left)
            {
                q.push({t->left, {line - 1, h + 1}});
            }
            if (t->right)
            {
                q.push({t->right, {line + 1, h + 1}});
            }
        }
        for (auto it : mp)
        {
            v.push_back(it.second.first->data);
        }
    }
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        vector<int> v;
        solve(root, v);
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        vector<int> res = ob.bottomView(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends