// //  Longest Palindrome by Concatenating Two Letter Words
// // Medium

// // 1406

// // 27

// // Add to List

// // Share
// // You are given an array of strings words. Each element of words consists of two lowercase English letters.

// // Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

// // Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

// // A palindrome is a string that reads the same forward and backward.

 

// // Example 1:

// // Input: words = ["lc","cl","gg"]
// // Output: 6
// // Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
// // Note that "clgglc" is another longest palindrome that can be created.
// // Example 2:

// // Input: words = ["ab","ty","yt","lc","cl","ab"]
// // Output: 8
// // Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
// // Note that "lcyttycl" is another longest palindrome that can be created.
// // Example 3:

// // Input: words = ["cc","ll","xx"]
// // Output: 2
// // Explanation: One longest palindrome is "cc", of length 2.
// // Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

// // Constraints:

// // 1 <= words.length <= 105
// // words[i].length == 2
// // words[i] consists of lowercase English letters.


// // Approach
// 1) Here the main point is that the individual strings whose palindrome is not present in 
// the array will never be considered in the final string.

// 2) That is if there is a string "dc" then inorder for this string to be present in the
// final answer, we must also have string "cd" in the array.

// 3) So first of all we find the frequency of all the strings in the original array in the 
// hash map and then we consider the length to be added as the minimum of the frequencies of 
// the string and its palindrome. 
// That is if the array is ["cd","dc","gg","cd","gg","dc","dc"]
// Now here our hash map h={
//     "cd" = 2,
//     "dc" = 3,
//     "gg" = 2,
// }
// SO basically we know that if we take three "dc" strings then we cannot make the string
// palindrome as we only have two "cd" strings.Instead if we take two "cd" strings then we
// can take two "dc" strings to form the palindrome. That is we have to take the minimum of 
// the freq[str] and freq[reverse_of_str].

// Also we make the frequencies of str and reverse_of_str once the computation is done is
// order to avoid the repitition when reverse_of_str will be the original string.

// 4) One more case is that when the string itself is a palindrome. In above example "gg" 
// itself is palindrome.
// So suppose there were two such strings with frequencies in the hash map as :
// h={
//     "gg" = 5,
//     "ee" = 3,
// }
// Now here we can see that we can take either (4 "gg" and 3 "ee") or (5 "gg" and 2 "ee").
// So that means, for such kind of strings if there are odd frequencies, then  we can take 
// odd freq for only one such string.


// // // class Solution
// // // {
// // // public:
// // //     int longestPalindrome(vector<string> &words)
// // //     {
// // //         unordered_map<string, int> u;
// // //         for (int i = 0; i < words.size(); i++)
// // //         {
// // //             u[words[i]]++;
// // //         }
// // //         int flag = false;
// // //         int ans = 0;
// // //         for (int i = 0; i < words.size(); i++)
// // //         {
// // //             if (words[i][0] == words[i][1])
// // //             {
// // //                 if (flag == true)
// // //                 {
// // //                     ans = ans + (u[words[i]] - u[words[i]] % 2) * 2;
// // //                 }
// // //                 else
// // //                 {
// // //                     ans = ans + (u[words[i]]) * 2;
// // //                     if (u[words[i]] % 2 == 1)
// // //                     {
// // //                         flag = true;
// // //                     }
// // //                 }
// // //                 u[words[i]] = 0;
// // //             }
// // //             else
// // //             {
// // //                 string s1 = words[i];
// // //                 string s2 = words[i];
// // //                 reverse(s2.begin(), s2.end());
// // //                 ans = ans + min(u[s1], u[s2]) * 4;
// // //                 u[s1] = 0;
// // //                 u[s2] = 0;
// // //             }
// // //         }
// // //         return ans;
// // //     }
// // // };
