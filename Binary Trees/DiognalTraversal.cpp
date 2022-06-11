// Diagonal Traversal of Binary Tree

// Difficulty Level : Medium
// Last Updated : 21 Jan, 2022
// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to the same line.

// Input : Root of below tree
// unnamed

// Output :
// Diagonal Traversal of binary tree :
//  8 10 14
//  3 6 7 13
//  1 4
// Observation : root and root->right values will be prioritized over all root->left values.
Using Queue.

    Every node will help to generate the next diagonal.We will push the element in the queue only when its left is available.We will process the node and move to its right.

    Code :

#include <bits/stdc++.h>
    using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

vector<vector<int>> result;
void diagonalPrint(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> answer;

        while (size--)
        {
            Node *temp = q.front();
            q.pop();

            // traversing each component;
            while (temp)
            {
                answer.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    diagonalPrint(root);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << "  ";
        cout << endl;
    }

    return 0;
}
// Output
// 8  10  14
// 3  6  7  13
// 1  4
// Time Complexity: O(N), because we are visiting nodes once.

// Space Complexity: O(N), because we are using queue.