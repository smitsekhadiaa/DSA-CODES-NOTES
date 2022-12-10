// //  Maximum Product of Splitted Binary Tree
// // Medium
// // 2.5K
// // 92
// // Companies
// // Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

// // Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// // Note that you need to maximize the answer before taking the mod and not after taking it.

// // Example 1:

// // Input: root = [1,2,3,4,5,6]
// // Output: 110
// // Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
// // Example 2:

// // Input: root = [1,null,2,3,4,null,null,5,6]
// // Output: 90
// // Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

// // Constraints:

// // The number of nodes in the tree is in the range [2, 5 * 104].
// // 1 <= Node.val <= 104
// /**
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
// class Solution
// {
// public:
//     int solve(TreeNode *node, unordered_map<TreeNode *, int> &u)
//     {
//         if (node == NULL)
//         {
//             return 0;
//         }
//         return u[node] = node->val + solve(node->left, u) + solve(node->right, u);
//     }
//     long long calculate(TreeNode *root, unordered_map<TreeNode *, int> &u, long long &totalsum, long long &ans)
//     {
//         if (root != NULL)
//         {
//             ans = max(ans, (long long)u[root] * (long long)(totalsum - u[root]));
//             calculate(root->left, u, totalsum, ans);
//             calculate(root->right, u, totalsum, ans);
//             return ans;
//         }
//         else
//             return 0;
//     }
//     int maxProduct(TreeNode *root)
//     {
//         unordered_map<TreeNode *, int> u;
//         long long ans = 0;
//         long long totalsum = solve(root, u);
//         ans = calculate(root, u, totalsum, ans);
//         ans = ans % 1000000007;
//         return ans;
//     }
// };