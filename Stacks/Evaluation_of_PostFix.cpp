// Evaluation of Postfix Expression 
// Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

 

// Example 1:

// Input: S = "231*+9-"
// Output: -4
// Explanation:
// After solving the given expression, 
// we have -4 as result.
// Example 2:

// Input: S = "123+*8-"
// Output: -3
// Explanation:
// After solving the given postfix 
// expression, we have -3 as result.

// Your Task:
// You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.


// Expected Time Complexity: O(|S|)
// Expected Auixilliary Space: O(|S|)

// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
          stack <int> stack;
            for(int i=0;i<S.size();i++)
            {
                if(S[i]>='0' && S[i]<='9')
                {
                    stack.push(S[i]-48);
                }
                else
                {
                    int a=stack.top();
                    stack.pop();
                    int b=stack.top();
                    stack.pop();
                    if(S[i]=='+')
                    {
                        stack.push(a+b);
                    }
                    else if(S[i]=='-')
                    {
                        stack.push (b-a);
                    }
                    else if(S[i]=='*')
                    {
                        stack.push (b*a);
                    }
                    else if(S[i]=='/')
                    {
                        stack.push (b/a);
                    }
                }
            }
            return stack.top();
            }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends

//   ANALYSIS
// Time Complexity: O(|S|)
// Auixilliary Space: O(|S|)

