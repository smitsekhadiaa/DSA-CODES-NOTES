// Min distance between two given nodes of a Binary Tree
// Medium Accuracy: 45.05% Submissions: 61695 Points: 4
// Given a binary tree and two node values your task is to find the minimum distance between them.

// Example 1:

// Input:
//         1
//       /  \
//      2    3
// a = 2, b = 3
// Output: 2
// Explanation: The tree formed is:
//        1
//      /   \ 
//     2     3
// We need the distance between 2 and 3.
// Being at node 2, we need to take two
// steps ahead in order to reach node 3.
// The path followed will be:
// 2 -> 1 -> 3. Hence, the result is 2.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.
// Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).
// { Driver Code Starts
// Initial Template for C++

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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    // find lca first then calc dist btwn lca and our node
    Node *lca(Node *root, int a, int b)
    {
        if (root == NULL || root->data == a || root->data == b)
        {
            return root;
        }
        Node *l = lca(root->left, a, b);
        Node *r = lca(root->right, a, b);

        if (l == NULL)
        {
            return r;
        }
        if (r == NULL)
        {
            return l;
        }
        else
        {
            return root;
        }
    }
    // to calc dist betwn lca and that node
    int dist(Node *root, int val)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->data == val)
        {
            return 1;
        }
        int a = dist(root->left, val);
        int b = dist(root->right, val);
        if (!a && !b)
        {
            return 0;
        }
        else
        {
            return a + b + 1;
        }
    }
    int findDist(Node *root, int a, int b)
    {
        // Your code here

        Node *t = lca(root, a, b);
        int x = dist(t, a);
        int y = dist(t, b);
        return x + y - 2;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
    }
    return 0;
}
// } Driver Code Ends