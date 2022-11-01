// // Where Will the Ball Fall
// // https://leetcode.com/problems/where-will-the-ball-fall/
// // You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

// // Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

// // A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
// // A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.
// // We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

// // Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

// // Example 1:

// // Input: grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]
// // Output: [1,-1,-1,-1,-1]
// // Explanation: This example is shown in the photo.
// // Ball b0 is dropped at column 0 and falls out of the box at column 1.
// // Ball b1 is dropped at column 1 and will get stuck in the box between column 2 and 3 and row 1.
// // Ball b2 is dropped at column 2 and will get stuck on the box between column 2 and 3 and row 0.
// // Ball b3 is dropped at column 3 and will get stuck on the box between column 2 and 3 and row 0.
// // Ball b4 is dropped at column 4 and will get stuck on the box between column 2 and 3 and row 1.
// // Example 2:

// // Input: grid = [[-1]]
// // Output: [-1]
// // Explanation: The ball gets stuck against the left wall.
// // Example 3:

// // Input: grid = [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]
// // Output: [0,1,2,3,4,-1]

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 1 <= m, n <= 100
// // grid[i][j] is 1 or -1.

// class Solution
// {
// public:
//     // vector<int> findBall(vector<vector<int>>& grid) {
//     //      int m = grid.size(), n = grid[0].size();
//     // vector<int> ans;
//     // // iterate each column
//     // for (int col = 0; col < n; col++) {
//     //     int cur_col = col;
//     //     // iterate each row
//     //     for (int cur_row = 0; cur_row < m; cur_row++) {
//     //         // the next column would be the current column + the value of the current cell
//     //         // e.g. column 0 + 1 = column 1 (move to the right)
//     //         // e.g. column 3 - 1 = column 2 (move to the left)
//     //         int next_col = cur_col + grid[cur_row][cur_col];
//     //         // after that we need to check if the ball gets stuck at the same column
//     //         // and there are three cases
//     //         // 1. the ball on the leftmost column is moving to the left
//     //         // hence, we check `next_col < 0`
//     //         // 2. the ball on the rightmost column is moving to the right
//     //         // hence, we check `next_col >= n`
//     //         // 3. the ball is stuck at a V shape position
//     //         // e.g. ball 2 and ball 3 in column 2 and column 3 in row 0
//     //         // hence, we check if the if grid[cur_row][cur_col] is different than grid[cur_row][next_col]
//     //         if (next_col < 0 || next_col >= n || grid[cur_row][cur_col] ^ grid[cur_row][next_col]) {
//     //             // the ball is stuck at some point, which means it couldn't reach to the end
//     //             // hence, we can set -1 and break here
//     //             cur_col = -1;
//     //             break;
//     //         }
//     //         // continue the above process with the updated cur_col
//     //         cur_col = next_col;
//     //     }
//     //     // the ball reaches to the end,
//     //     // cur_col is the final destination
//     //     ans.push_back(cur_col);
//     // }
//     // return ans;
//     // }

//     // RECURSION (dp)
//     int m, n;
//     int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
//     {
//         if (r == m)
//             return c;
//         if (dp[r][c] != -1)
//         {
//             return dp[r][c];
//         }
//         if (grid[r][c] == 1)
//         {
//             if (c + 1 >= n || grid[r][c + 1] == -1)
//             {
//                 return -1;
//             }
//             return dp[r][c] = solve(r + 1, c + 1, grid, dp);
//         }
//         if (c - 1 < 0 || grid[r][c - 1] == 1)
//             return -1;
//         return dp[r][c] = solve(r + 1, c - 1, grid, dp);
//     }
//     vector<int> findBall(vector<vector<int>> &grid)
//     {
//         m = grid.size(), n = grid[0].size();
//         vector<int> ans(n, -1);
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         for (int c = 0; c < n; c++)
//         {
//             ans[c] = solve(0, c, grid, dp);
//         }
//         return ans;
//     }
// };
