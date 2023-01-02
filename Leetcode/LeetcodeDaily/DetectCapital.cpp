// // . Detect Capital

// // We define the usage of capitals in a word to be right when one of the following cases holds:

// // All letters in this word are capitals, like "USA".
// // All letters in this word are not capitals, like "leetcode".
// // Only the first letter in this word is capital, like "Google".
// // Given a string word, return true if the usage of capitals in it is right.

// // Example 1:

// // Input: word = "USA"
// // Output: true
// // Example 2:

// // Input: word = "FlaG"
// // Output: false

// // Constraints:

// // 1 <= word.length <= 100
// // word consists of lowercase and uppercase English letters.

// class Solution
// {
// public:
//     bool detectCapitalUse(string word)
//     {
//         int flag = 0;
//         int n = word.length();
//         if (n == 1)
//         {
//             return true;
//         }
//         if (!isupper(word[0]))
//         {
//             for (int i = 1; i < word.length(); i++)
//             {
//                 if (isupper(word[i]))
//                 {
//                     return false;
//                 }
//             }
//         }

//         else if (isupper(word[0]))
//         {
//             for (int i = 1; i < n; i++)
//             {
//                 if (isupper(word[i]))
//                 {
//                     flag = 1;
//                 }
//                 else if (!isupper(word[i]))
//                 {
//                     flag = 0;
//                 }
//             }
//         }
//         if (flag == 1)
//         {
//             for (int i = 1; i < n; i++)
//             {
//                 if (!isupper(word[i]))
//                 {
//                     return false;
//                 }
//             }
//         }
//         else if (flag == 0)
//         {
//             for (int i = 1; i < n; i++)
//             {
//                 if (isupper(word[i]))
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };