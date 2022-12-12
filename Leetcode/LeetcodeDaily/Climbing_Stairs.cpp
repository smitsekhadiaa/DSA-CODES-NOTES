// // 70. Climbing Stairs
// // Easy
// // 16.2K
// // 484
// // Companies
// // You are climbing a staircase. It takes n steps to reach the top.

// // Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// // Example 1:

// // Input: n = 2
// // Output: 2
// // Explanation: There are two ways to climb to the top.
// // 1. 1 step + 1 step
// // 2. 2 steps
// // Example 2:

// // Input: n = 3
// // Output: 3
// // Explanation: There are three ways to climb to the top.
// // 1. 1 step + 1 step + 1 step
// // 2. 1 step + 2 steps
// // 3. 2 steps + 1 step

// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         int a = 2;
//         int b = 1;
//         int count = 0;
//         if (n == 0)
//         {
//             return 0;
//         }
//         if (n == 1)
//         {
//             return 1;
//         }
//         if (n == 2)
//         {
//             return 2;
//         }
//         for (int i = 2; i < n; i++)
//         {
//             count = a + b;
//             b = a;
//             a = count;
//         }
//         return count;
//     }
// };