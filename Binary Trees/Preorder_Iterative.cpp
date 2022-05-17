// Iterative Preorder Traversal
// Difficulty Level : Easy
// Last Updated : 17 Jan, 2022
// Given a Binary Tree, write an iterative function to print the Preorder traversal of the given binary tree.
// Refer to this for recursive preorder traversal of Binary Tree. To convert an inherently recursive procedure to iterative, we need an explicit stack. Following is a simple stack based iterative process to print Preorder traversal.
// 1) Create an empty stack nodeStack and push root node to stack.
// 2) Do the following while nodeStack is not empty.
// ….a) Pop an item from the stack and print it.
// ….b) Push right child of a popped item to stack
// ….c) Push left child of a popped item to stack
// The right child is pushed before the left child to make sure that the left subtree is processed first.

// Time Complexity: O(N)
// Auxiliary Space: O(N), where N is the total number of nodes in the tree.

// Space Optimized Solution: The idea is to start traversing the tree from the root node, and keep printing the left child while exists and simultaneously, push the right child of every node in an auxiliary stack. Once we reach a null node, pop a right child from the auxiliary stack and repeat the process while the auxiliary stack is not-empty.

// Time Complexity: O(N)
// Auxiliary Space: O(H), where H is the height of the tree.

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Iterative function to do Preorder traversal of the tree
void preorderIterative(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;

    // start from root node (set current node to root node)
    Node *curr = root;

    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL)
    {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL)
        {
            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false)
        {
            curr = st.top();
            st.pop();
        }
    }
}

// Driver Code
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->left->left = new Node(70);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->right = new Node(80);

    preorderIterative(root);

    return 0;
}
