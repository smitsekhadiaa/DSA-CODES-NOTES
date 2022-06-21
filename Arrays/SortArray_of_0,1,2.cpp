// Sort an array of 0s, 1s and 2s
// Easy Accuracy: 51.36% Submissions: 100k+ Points: 2
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Example 1:

// Input:
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.
// Example 2:

// Input:
// N = 3
// arr[] = {0 1 0}
// Output:
// 0 0 1
// Explanation:
// 0s 1s and 2s are segregated
// into ascending order.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
// { Driver Code Starts
// Initial Template for C
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                x++;
            else if (a[i] == 1)
                y++;
            else
                z++;
        }
        int k = 0;
        for (int i = 0; i < x; i++)
        {
            a[k++] = 0;
        }
        for (int i = 0; i < y; i++)
        {
            a[k++] = 1;
        }
        for (int i = 0; i < z; i++)
        {
            a[k++] = 2;
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends