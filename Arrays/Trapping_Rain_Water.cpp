// Trapping Rain Water
// Medium Accuracy: 49.62% Submissions: 100k+ Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

// Example 1:

// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10
// Explanation:

// Example 2:

// Input:
// N = 4
// arr[] = {7,4,0,9}
// Output:
// 10
// Explanation:
// Water trapped by above
// block of height 4 is 3 units and above
// block of height 0 is 7 units. So, the
// total unit of water trapped is 10 units.
// Example 3:

// Input:
// N = 3
// arr[] = {6,9,9}
// Output:
// 0
// Explanation:
// No water will be trapped.

// Your Task:
// You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here

        // METHOD 1 : TIME : O(N)  SPACE: O(N)

        // int left[n]={0};
        // int right[n]={0};
        // left[0]=arr[0];
        // right[n-1]=arr[n-1];
        // for(int i=1;i<n;i++){
        //     if(arr[i]>left[i-1]){
        //         left[i]=arr[i];
        //     }
        //     else{
        //         left[i]=left[i-1];
        //     }
        // }
        // for(int j=n-2;j>=0;j--){
        //     if(arr[j]>right[j+1]){
        //         right[j]=arr[j];
        //     }
        //     else{
        //         right[j]=right[j+1];
        //     }
        // }
        // long long ans=0;
        // for(int i=0;i<n;i++){
        //     ans=ans+(min(left[i],right[i])-arr[i]);
        // }
        // return ans;

        // METHOD 2 : TIME : O(N)  SPACE: O(1)

        int l = 0;
        int r = n - 1;
        long long ans = 0;
        int lmax = 0, rmax = 0;
        while (l <= r)
        {
            if (arr[l] <= arr[r])
            {
                if (arr[l] > lmax)
                {
                    lmax = arr[l];
                }
                else
                {
                    ans = ans + lmax - arr[l];
                }
                l++;
            }
            else
            {
                if (arr[r] > rmax)
                {
                    rmax = arr[r];
                }
                else
                {
                    ans = ans + rmax - arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends