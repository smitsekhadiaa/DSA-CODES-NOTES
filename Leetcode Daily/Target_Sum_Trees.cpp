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
//     vector<vector<int>> ans;
//     vector<int> path;
//     void dfs(TreeNode *root, int cursum, int target)
//     {
//         if (root == NULL)
//         {
//             return;
//         }
//         cursum = cursum + root->val;
//         path.push_back(root->val);
//         if (cursum == target && root->left == NULL && root->right == NULL)
//         {
//             ans.push_back(path);
//         }
//         dfs(root->left, cursum, target);
//         dfs(root->right, cursum, target);
//         path.pop_back();
//     }
//     vector<vector<int>> pathSum(TreeNode *root, int targetSum)
//     {

//         dfs(root, 0, targetSum);
//         return ans;
//     }
// };