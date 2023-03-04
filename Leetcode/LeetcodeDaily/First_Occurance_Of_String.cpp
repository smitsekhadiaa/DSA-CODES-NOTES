// // 28. Find the Index of the First Occurrence in a String
// // Medium
// // 2.8K
// // 136
// // Companies
// // Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// // Example 1:

// // Input: haystack = "sadbutsad", needle = "sad"
// // Output: 0
// // Explanation: "sad" occurs at index 0 and 6.
// // The first occurrence is at index 0, so we return 0.
// // Example 2:

// // Input: haystack = "leetcode", needle = "leeto"
// // Output: -1
// // Explanation: "leeto" did not occur in "leetcode", so we return -1.

// // Constraints:

// // 1 <= haystack.length, needle.length <= 104

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         int n = needle.length();
//         int i = 0;
//         int j = 0;
//         int m = haystack.size();
//         string temp = "";
//         while (j < m)
//         {
//             if (j - i + 1 < n)
//             {
//                 temp.push_back(haystack[j]);
//                 j++;
//             }
//             if (j - i + 1 == n)
//             {
//                 temp.push_back(haystack[j]);
//                 if (temp == needle)
//                 {
//                     return i;
//                 }
//                 else
//                 {
//                     temp.erase(0, 1);
//                     i++;
//                     j++;
//                 }
//             }
//         }
//         return -1;
//     }
// };