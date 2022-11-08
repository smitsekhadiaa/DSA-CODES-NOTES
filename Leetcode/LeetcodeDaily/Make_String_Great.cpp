// // Make The String Great

// // Given a string s of lower and upper case English letters.

// // A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

// // 0 <= i <= s.length - 2
// // s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
// // To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

// // Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

// // Notice that an empty string is also good.

// // Example 1:

// // Input: s = "leEeetcode"
// // Output: "leetcode"
// // Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
// // Example 2:

// // Input: s = "abBAcC"
// // Output: ""
// // Explanation: We have many possible scenarios, and all lead to the same answer. For example:
// // "abBAcC" --> "aAcC" --> "cC" --> ""
// // "abBAcC" --> "abBA" --> "aA" --> ""
// // Example 3:

// // Input: s = "s"
// // Output: "s"

// class Solution
// {
// public:
//     string makeGood(string s)
//     {
//         //         BRUTE FORCE
//         //  string ans;
//         //  for(int i=0;i<s.length();i++){
//         //      ans.push_back(s[i]);
//         //      while(ans.length() && ans.back()==s[i+1]+32 || ans.back()==s[i+1]-32){
//         //          ans.pop_back();
//         //          i++;
//         //      }
//         //  }
//         // return ans;
//         //         OPTIMAL SOLUTION : stack
//         stack<char> st;
//         st.push(s[0]);
//         for (int i = 1; i < s.length(); i++)
//         {
//             if (st.empty() || st.top() != s[i] + 32 && st.top() != s[i] - 32)
//             {
//                 st.push(s[i]);
//             }
//             else
//             {
//                 st.pop();
//             }
//         }
//         string ans = "";
//         while (!st.empty())
//         {
//             char c = st.top();
//             ans = ans + c;
//             st.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };