// Minimum number of Coins
// EasyAccuracy: 68.3%Submissions: 8730Points: 2
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } and a target value N.
// Find the minimum number of coins and/or notes needed to make the change for Rs N.

// Example 1:

// Input: N = 43
// Output: 20 20 2 1
// Explaination:
// Minimum number of coins and notes needed
// to make 43.

// Example 2:

// Input: N = 1000
// Output: 500 500
// Explaination: minimum possible notes
// is 2 notes of 500.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function minPartition() which takes the value N as input parameter and returns a list of integers in decreasing order.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ N ≤ 106
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> v = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int count = 0;
        vector<int> ans;
        int i = 0;
        while (N != 0)
        {
            if (N < v[i])
            {
                i++;
            }
            else
            {
                N = N - v[i];
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends