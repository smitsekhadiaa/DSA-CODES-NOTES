// // 114. Flatten Binary Tree to Linked List
// // Medium

// // 8326

// // 484

// // Add to List

// // Share
// // Given the root of a binary tree, flatten the tree into a "linked list":

// // The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// // The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// // Example 1:

// // Input: root = [1,2,5,3,4,null,6]
// // Output: [1,null,2,null,3,null,4,null,5,null,6]
// // Example 2:

// // Input: root = []
// // Output: []
// // Example 3:

// // Input: root = [0]
// // Output: [0]

// // Constraints:

// // The number of nodes in the tree is in the range [0, 2000].
// // -100 <= Node.val <= 100
// /**

// SOLUTION
// APPROACH -> O ( N ) SPACE
// By using brute force, we can traverse the tree in preorder manner and store the result in a vector.
// Later using that vector , we can arrange nodes, such as

// vector[i] -> right = vector[i+1];
// vector[i] -> left = NULL;
// APPROACH -> O ( 1 ) SPACE

// From the diagram given , it can be seen all nodes are present on the right.
// All the nodes in left subtree come before the nodes in right subtree.
// For each node i

// IF there is no left node -> move to next right node.
// IF LEFT IS PRESENT ->
// Store the right subtree
// ADD left subtree to right of root,
// Now add the stored right subtree to the rightmost node of current tree.
// Also make node -> left =NULL.

//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* rightmost(TreeNode* root){
//         if(root->right==NULL){
//             return root;
//         }
//         while(root->right){
//             root=root->right;
//         }
//         return root;
//     }
//     void solve(TreeNode* root){
//         if(root==NULL){
//             return ;
//         }
//         TreeNode* rightmostnode;
//         TreeNode* nextrightnodetoroot;
//         while(root){
//             if(root->left){
//                 rightmostnode=rightmost(root->left);
//                 nextrightnodetoroot=root->right;
//                 root->right=root->left;
//                 root->left=NULL;
//                 rightmostnode->right=nextrightnodetoroot;

//             }
//             root=root->right;
//         }

//     }
//     void flatten(TreeNode* root) {

//         return solve(root);

//     }
// };