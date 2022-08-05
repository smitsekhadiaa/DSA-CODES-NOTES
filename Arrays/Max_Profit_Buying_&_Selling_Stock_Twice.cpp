// // // 123. Best Time to Buy and Sell Stock III
// // // Hard

// // // 6041

// // // 122

// // // Add to List

// // // Share
// // // You are given an array prices where prices[i] is the price of a given stock on the ith day.

// // // Find the maximum profit you can achieve. You may complete at most two transactions.

// // // Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

// // // Example 1:

// // // Input: prices = [3,3,5,0,0,3,1,4]
// // // Output: 6
// // // Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// // // Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
// // // Example 2:

// // // Input: prices = [1,2,3,4,5]
// // // Output: 4
// // // Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// // // Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
// // // Example 3:

// // // Input: prices = [7,6,4,3,1]
// // // Output: 0
// // // Explanation: In this case, no transaction is done, i.e. max profit = 0.

// //  class Solution {
// class Solution
// {
// public:
//     int solve(int i, int trans, vector<int> &prices, int &n, vector<vector<int>> &dp)
//     {
//         if (i == n || trans == 4)
//         {
//             return 0;
//         }
//         if (dp[i][trans] != -1)
//         {
//             return dp[i][trans];
//         }
//         if (trans % 2 == 0)
//         {
//             return dp[i][trans] = max(solve(i + 1, trans + 1, prices, n, dp) - prices[i], solve(i + 1, trans, prices, n, dp));
//         }
//         else
//             return dp[i][trans] = max(prices[i] + solve(i + 1, trans + 1, prices, n, dp), solve(i + 1, trans, prices, n, dp));
//     }
//     int maxProfit(vector<int> &prices)
//     {
//         // int min1=INT_MAX;
//         // int profit1=0;
//         // int min2=INT_MAX;
//         // int profit2=0;
//         // for(int i=0;i<prices.size();i++){
//         //     min1=min(min1,prices[i]);
//         //     profit1=max(profit1,prices[i]-min1);
//         //     min2=min(min2,prices[i]-profit1);
//         //     profit2=max(profit2,prices[i]-min2);
//         // }
//         // return profit2;
//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(4, -1));
//         return solve(0, 0, prices, n, dp);
//     }
// };