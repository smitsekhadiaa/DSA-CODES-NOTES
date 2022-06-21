// Find minimum and maximum element in an array
// Basic Accuracy: 59.4% Submissions: 82859 Points: 1
// Given an array A of size N of integers. Your task is to find the minimum and maximum elements in the array.

// Example 1:

// Input:
// N = 6
// A[] = {3, 2, 1, 56, 10000, 167}
// Output:
// min = 1, max =  10000

// Example 2:

// Input:
// N = 5
// A[]  = {1, 345, 234, 21, 56789}
// Output:
// min = 1, max = 56789

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function getMinMax() which takes the array A[] and its size N as inputs and returns the minimum and maximum element of the array.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long long, long long> getMinMax(long long a[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        pair<ll, ll> pp = getMinMax(a, n);

        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
} // } Driver Code Ends

pair<long long, long long> getMinMax(long long a[], int n)
{
    pair<long long int, long long int> p;
    long long int x = a[0];
    long long int y = a[0];
    for (int i = 0; i < n; i++)
    {
        if (y > a[i])
        {
            y = a[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (x < a[i])
        {
            x = a[i];
        }
    }
    return p = {y, x};
}