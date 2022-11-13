// // Reverse Words in a String
// // Medium

// // 4717

// // 4344

// // Add to List

// // Share
// // Given an input string s, reverse the order of the words.

// // A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// // Return a string of the words in reverse order concatenated by a single space.

// // Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// // Example 1:

// // Input: s = "the sky is blue"
// // Output: "blue is sky the"
// // Example 2:

// // Input: s = "  hello world  "
// // Output: "world hello"
// // Explanation: Your reversed string should not contain leading or trailing spaces.
// // Example 3:

// // Input: s = "a good   example"
// // Output: "example good a"
// // Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// // Constraints:

// // 1 <= s.length <= 104
// // s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// // There is at least one word in s.

// // Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         reverse(s.begin(), s.end());
//         s.push_back(' ');
//         string ans = "";
//         string temp = "";
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (s[i] != ' ')
//             {
//                 temp.push_back(s[i]);
//             }
//             else if (s[i] == ' ')
//             {
//                 reverse(temp.begin(), temp.end());
//                 ans = ans + temp;
//                 ans.push_back(' ');
//                 temp = "";
//             }
//         }
//         if (ans[0] == ' ')
//         {
//             while (ans[0] == ' ')
//             {
//                 ans.erase(ans.begin() + 0);
//             }
//         }
//         if (ans[ans.length() - 1] == ' ')
//         {
//             while (ans[ans.length() - 1] == ' ')
//             {
//                 ans.pop_back();
//             }
//         }
//         for (int i = 0; i < ans.length() - 1; i++)
//         {
//             if (ans[i] == ' ')
//             {
//                 if (ans[i + 1] == ' ')
//                 {
//                     while (ans[i + 1] == ' ')
//                     {
//                         ans.erase(ans.begin() + (i + 1));
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };