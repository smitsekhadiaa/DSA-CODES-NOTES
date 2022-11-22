// // Perfect Squares
// // Given an integer n, return the least number of perfect square numbers that sum to n.

// // A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// // Example 1:

// // Input: n = 12
// // Output: 3
// // Explanation: 12 = 4 + 4 + 4.
// // Example 2:

// // Input: n = 13
// // Output: 2
// // Explanation: 13 = 4 + 9.
// class Solution
// {
// public:
//     int helper(int i, vector<int> &dp)
//     {
//         if (i == 0)
//             return 0;
//         if (dp[i] != -1)
//             return dp[i];
//         int minCnt = INT_MAX;
//         for (int num = 1; num <= sqrt(i); ++num)
//         {
//             int curCnt = 1 + helper(i - (num * num), dp);
//             minCnt = min(curCnt, minCnt);
//         }
//         return dp[i] = minCnt;
//     }

//     int numSquares(int n)
//     {
//         vector<int> dp(n + 1, -1);
//         return helper(n, dp);
//     }
// };