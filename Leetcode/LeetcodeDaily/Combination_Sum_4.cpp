// // 77. Combination Sum IV
// // Medium

// // 4053

// // 445

// // Add to List
// 
// // Share
// // Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// // The test cases are generated so that the answer can fit in a 32-bit integer.

// // Example 1:

// // Input: nums = [1,2,3], target = 4
// // Output: 7
// // Explanation:
// // The possible combination ways are:
// // (1, 1, 1, 1)
// // (1, 1, 2)
// // (1, 2, 1)
// // (1, 3)
// // (2, 1, 1)
// // (2, 2)
// // (3, 1)
// // Note that different sequences are counted as different combinations.
// // Example 2:

// // Input: nums = [9], target = 3
// // Output: 0

// // Constraints:

// // 1 <= nums.length <= 200
// // 1 <= nums[i] <= 1000
// // All the elements of nums are unique.
// // 1 <= target <= 1000

// class Solution
// {
// public:
//     // int solve(vector<int> &nums,int target,int n){
//     //     if(n==0){
//     //         return 0;
//     //     }
//     //     if(nums[n-1]<=target){
//     //         return max(1+solve(nums,target-nums[n-1],n),solve(nums,target,n-1));
//     //     }
//     //     else{
//     //         return solve(nums,target,n-1);
//     //     }
//     // }
//     int solve(vector<int> &nums, int target, int n, vector<int> &dp)
//     {
//         if (target == 0)
//         {
//             return 1;
//         }
//         if (dp[target] != -1)
//         {
//             return dp[target];
//         }
//         int a = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] <= target)
//             {
//                 a = a + solve(nums, target - nums[i], n, dp);
//             }
//         }
//         return dp[target] = a;
//     }
//     int combinationSum4(vector<int> &nums, int target)
//     {
//         int n = nums.size();
//         vector<int> dp(target + 1, -1);
//         return solve(nums, target, n, dp);
//     }
// };