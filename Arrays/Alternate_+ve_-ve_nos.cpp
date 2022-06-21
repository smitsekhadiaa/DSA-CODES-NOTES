// Alternate positive and negative numbers
// Easy Accuracy: 49.41% Submissions: 46662 Points: 2
// Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
// Note: Array should start with positive number.

// Example 1:

// Input:
// N = 9
// Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
// Output:
// 9 -2 4 -1 5 -5 0 -3 2
// Example 2:

// Input:
// N = 10
// Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
// Output:
// 5 -5 2 -2 4 -8 7 1 8 0
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        // code here
        queue<int> q1;
        queue<int> q2;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                q1.push(arr[i]);
            }
            else
            {
                q2.push(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (!q1.empty())
                {
                    arr[i] = q1.front();
                    q1.pop();
                }
                else
                {
                    arr[i] = q2.front();
                    q2.pop();
                }
            }
            else
            {
                if (!q2.empty())
                {
                    arr[i] = q2.front();
                    q2.pop();
                }
                else
                {
                    arr[i] = q1.front();
                    q1.pop();
                }
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends