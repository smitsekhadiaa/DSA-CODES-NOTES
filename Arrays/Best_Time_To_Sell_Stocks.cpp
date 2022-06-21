// // 121. Best Time to Buy and Sell Stock
// // Easy

// // 16967

// // 561

// // Add to List

// // Share
// // You are given an array prices where prices[i] is the price of a given stock on the ith day.

// // You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// // Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// // Example 1:

// // Input: prices = [7,1,5,3,6,4]
// // Output: 5
// // Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// // Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// // Example 2:

// // Input: prices = [7,6,4,3,1]
// // Output: 0
// // Explanation: In this case, no transactions are done and the max profit = 0.
//  class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//        vector<int> track_min(prices.size(), 0);
// 		vector<int> ans(prices.size(), 0);
// 		track_min[0] = prices[0];

// 		for(int i = 1; i < prices.size(); ++i){
// 			track_min[i] = min(track_min[i-1], prices[i]);
// 			ans[i] = prices[i] - track_min[i];
// 		}

// 		return *max_element(ans.begin(), ans.end());
        
//     }
// };

// METHOD 2
//   int min1=INT_MAX;
//         int profit1=0;
//         for(int i=0;i<prices.size();i++){
//             min1=min(min1,prices[i]);
//             profit1=max(profit1,prices[i]-min1);
          
//         }
//         return profit1;