// link for explanation of code: https://www.youtube.com/watch?v=VdQuwtEd10M

// Valid Substring
// Easy Accuracy: 48.25% Submissions: 4297
// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
// NOTE: Length of the smallest valid substring ( ) is 2.

// Example 1:

// Input: S = "(()("
// Output: 2
// Explanation: The longest valid
// substring is "()". Length = 2.
// Example 2:

// Input: S = "()(())("
// Output: 6
// Explanation: The longest valid
// substring is "()(())". Length = 6.

// Your Task:
// You dont need to read input or print anything. Complete the function findMaxLen() which takes S as input parameter and returns the maxlength.

// Expected Time Complexity:O(n)
// Expected Auxiliary Space: O(1)

// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int findMaxLen(string s)
    {
        // code here

        // METHOD 1  TIME:O(n) SPACE:O(n)

        // stack <int> st;
        // int count=0;
        // st.push(-1);
        // for(int i=0;i<s.length();i++)
        // {
        //   if(s[i]=='(')
        //   {
        //       st.push(i);
        //   }
        //   else
        //   {
        //       st.pop();
        //       if(st.empty())
        //       {
        //          st.push(i);
        //       }
        //       else
        //       {
        //           count=max(count,i-st.top());
        //       }

        //   }
        // }
        // return count;

        // METHOD 2(EFFICIENT)TIME : O(n) SPACE : O(1)

        int open = 0,
        int close = 0;
        int maximum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            if (open == close)
            {
                maximum = max(maximum, open * 2);
            }
            else if (close > open)
            {
                open = 0;
                close = 0;
            }
        }
        open = {close = 0};
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else
            {
                close++;
            }
            if (close == open)
            {
                maximum = max(maximum, open * 2);
            }
            else if (close < open)
            {
                open = 0;
                close = 0;
            }
        }
        return maximum;
    };

    // { Driver Code Starts.
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            string S;
            cin >> S;
            Solution ob;
            cout << ob.findMaxLen(S) << endl;
        }
        return 0;
    }
    // } Driver Code Ends
