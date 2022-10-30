// // 242. Valid Anagram

// // Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// // An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// // Example 1:

// // Input: s = "anagram", t = "nagaram"
// // Output: true
// // Example 2:

// // Input: s = "rat", t = "car"
// // Output: false

// // Constraints:

// // 1 <= s.length, t.length <= 5 * 104
// // s and t consist of lowercase English letters.

// class Solution
// {
// public:
//     bool isAnagram(string s, string t)
//     {
//         unordered_map<char, int> mp1;
//         for (int i = 0; i < s.length(); i++)
//         {
//             mp1[s[i]]++;
//         }
//         for (int j = 0; j < t.length(); j++)
//         {
//             mp1[t[j]]--;
//         }
//         for (int i = 0; i < mp1.size(); i++)
//         {
//             if (mp1[s[i]] != 0 || mp1[t[i]] != 0)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
