// Factorials of large numbers
// Medium Accuracy: 51.61% Submissions: 46456 Points: 4
// Given an integer N, find its factorial.

// Example 1:

// Input: N = 5
// Output: 120
// Explanation : 5! = 1*2*3*4*5 = 120
// Example 2:

// Input: N = 10
// Output: 3628800
// Explanation :
// 10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

// Your Task:
// You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.

// Expected Time Complexity : O(N2)
// Expected Auxilliary Space : O(1)

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<int> factorial(int N)
    {
        // code here
        vector<int> v;
        int prod, carry = 0;
        v.push_back(1);
        for (int i = 2; i <= N; i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                prod = v[j] * i + carry;
                v[j] = prod % 10;
                carry = prod / 10;
            }
            while (carry > 0)
            {
                v.push_back(carry % 10);
                carry = carry / 10;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends