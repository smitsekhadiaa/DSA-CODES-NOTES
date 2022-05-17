// Morris traversal for Postorder
// Perform Postorder Tree traversal using Morris Traversal.

// Examples:

// Input:             1
//              /          \
//            2             3
//         /       \       / \
//        6       7      8    9

// Output: 6 7 2 8 9 3 1

// Input:            5
//              /          \
//            2             3
//         /      \       /  \
//        4       N      8     9

// Output: 4 2 8 9 3 5

// Approach: The approach to performing Morris Traversal for Postorder is similar to Morris traversal for Preorder except swapping between left and right node links.

// Create a vector and Initialize current as root
// While current is not NULL
// If the current does not have a right child
// push the current key in vector
//     Go to the left, i.e., current = current->left
// else
// Find leftmost node in current right subtree OR node whose left child == current.
// if current  does not have a left child
// push the current key in the vector
// Make current as of the left child of that leftmost node
// Go to this right child, i.e., current = current->right
// else
// Found left child == current
// Update the left child as NULL of that node whose left child is current
// Go to the left, i.e. current = current->left

// In the last, we reverse the vector and print it.

// C++ program to perform
// Morris Traversal for Postorder
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

// Function to print vector
void print(vector<int> &ans)
{
    // Print the vector elements
    for (auto x : ans)
    {
        cout << x << " ";
    }
}

// Postorder traversal
// Without recursion and without stack
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    TreeNode *current = root;

    while (current != NULL)
    {
        // If right child is null,
        // put the current node data
        // in res. Move to left child.
        if (current->right == NULL)
        {
            res.push_back(current->key);
            current = current->left;
        }
        else
        {
            TreeNode *predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current)
            {
                predecessor = predecessor->left;
            }
            // If left child doesn't point
            // to this node, then put in res
            // this node and make left
            // child point to this node
            if (predecessor->left == NULL)
            {
                res.push_back(current->key);
                predecessor->left = current;
                current = current->right;
            }
            // If the left child of inorder predecessor
            // already points to this node
            else
            {
                predecessor->left = NULL;
                current = current->left;
            }
        }
    }
    // reverse the res
    reverse(res.begin(), res.end());
    return res;
}
// Driver program
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);

    cout << "Morris(postorder) Traversal: ";
    vector<int> ans = postorderTraversal(root);

    print(ans);
    return 0;
}
