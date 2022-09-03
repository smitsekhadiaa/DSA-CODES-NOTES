// // 62. Unique Paths
// // Medium

// // 10469

// // 321

// // Add to List

// // Share
// // There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// // Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// // The test cases are generated so that the answer will be less than or equal to 2 * 109.

// // Example 1:

// // Input: m = 3, n = 7
// // Output: 28
// // Example 2:

// // Input: m = 3, n = 2
// // Output: 3
// // Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// // 1. Right -> Down -> Down
// // 2. Down -> Down -> Right
// // 3. Down -> Right -> Down
// class Solution
// {
// public:
//     int solve(int m, int n, int i, int j, vector<vector<int>> &dp)
//     {
//         if (i == m || j == n)
//         {
//             return 0;
//         }
//         if (i == m - 1 && j == n - 1)
//         {
//             return 1;
//         }
//         if (dp[i][j] != -1)
//         {
//             return dp[i][j];
//         }
//         int a, b;
//         if (dp[i + 1][j] != -1)
//         {
//             a = dp[i + 1][j];
//         }
//         else
//         {
//             a = solve(m, n, i + 1, j, dp);
//         }
//         if (dp[i][j + 1] != -1)
//         {
//             b = dp[i][j + 1];
//         }
//         else
//         {
//             b = solve(m, n, i, j + 1, dp);
//         }
//         return dp[i][j] = a + b;
//     }
//     int uniquePaths(int m, int n)
//     {
//         int i = 0, j = 0;
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//         return solve(m, n, i, j, dp);
//     }
// };