// ZigZag Tree Traversal
// Easy Accuracy: 49.78% Submissions: 66793 Points: 2
// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

// Example 1:

// Input:
//         3
//       /   \
//      2     1
// Output:
// 3 1 2
// Example 2:

// Input:
//            7
//         /     \
//        9       7
//      /  \     /
//     8    8   6
//    /  \
//   10   9
// Output:
// 7 7 9 8 8 6 9 10

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).
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
// User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    void solve(Node *root, vector<int> &answer)
    {

        deque<Node *> dq;
        dq.push_back(root);
        dq.push_back(NULL);
        int signum = 0;
        while (dq.size() != 1)
        {
            if (signum == 0)
            {
                if (dq.front() == NULL)
                {
                    signum = 1;
                }
                else
                {
                    answer.push_back(dq.front()->data);
                    if (dq.front()->left != NULL)
                    {
                        dq.push_back(dq.front()->left);
                    }
                    if (dq.front()->right != NULL)
                    {
                        dq.push_back(dq.front()->right);
                    }
                    dq.pop_front();
                }
            }
            else
            {
                if (dq.back() == NULL)
                {
                    signum = 0;
                }
                else
                {
                    answer.push_back(dq.back()->data);
                    if (dq.back()->right != NULL)
                    {
                        dq.push_front(dq.back()->right);
                    }
                    if (dq.back()->left != NULL)
                    {
                        dq.push_front(dq.back()->left);
                    }
                    dq.pop_back();
                }
            }
        }
    }
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> answer;
        solve(root, answer);
        return answer;
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

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends