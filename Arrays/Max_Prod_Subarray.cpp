// Maximum Product Subarray
// Medium Accuracy: 29.84% Submissions: 100k+ Points: 4
// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

// Example 1:

// Input:
// N = 5
// Arr[] = {6, -3, -10, 0, 2}
// Output: 180
// Explanation: Subarray with maximum product
// is [6, -3, -10] which gives product as 180.
// Example 2:

// Input:
// N = 6
// Arr[] = {2, 3, 4, 5, -1, 0}
// Output: 120
// Explanation: Subarray with maximum product
// is [2, 3, 4, 5] which gives product as 120.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
// Note: Use 64-bit integer data type to avoid overflow.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        long long prod = 1;
        long long ans = arr[0];
        if (n == 1)
        {
            return arr[0];
        }
        for (int i = 0; i < n; i++)
        {
            if (prod == 0)
            {
                prod = 1;
            }
            prod = prod * arr[i];
            ans = max(ans, prod);
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (prod == 0)
            {
                prod = 1;
            }

            prod = prod * arr[i];
            ans = max(ans, prod);
        }
        return ans;
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
        vector<int> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends