// Merge Without Extra Space
// Hard Accuracy: 36.41% Submissions: 100k+ Points: 8
// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

// Example 1:

// Input:
// N = 4, M = 5
// arr1[] = {1, 3, 5, 7}
// arr2[] = {0, 2, 6, 8, 9}
// Output: 0 1 2 3 5 6 7 8 9
// Explanation: Since you can't use any
// extra space, modify the given arrays
// to form
// arr1[] = {0, 1, 2, 3}
// arr2[] = {5, 6, 7, 8, 9}

// Example 2:

// Input:
// N = 2, M = 3
// arr1[] = {10, 12}
// arr2[] = {5, 18, 20}
// Output: 5 10 12 18 20
// Explanation: Since you can't use any
// extra space, modify the given arrays
// to form
// arr1[] = {5, 10}
// arr2[] = {12, 18, 20}

// Your Task:
// You don't need to read input or print anything. Complete the function merge() which takes the two arrays arr1[], arr2[] and their sizes n and m, as input parameters. The function does not return anything. Use the given arrays to sort and merge arr1[] and arr2[] in-place.
// Note: The generated output will print all the elements of arr1[] followed by all the elements of arr2[].

// Expected Time Complexity: O((n+m)*log(n+m))
// Expected Auxiliary Space: O(1
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int getgap(int curgap)
    {
        if (curgap <= 1)
        {
            return 0;
        }
        return (curgap / 2 + curgap % 2);
    }
    void merge(int arr1[], int arr2[], int n, int m)
    {
        // code here
        // GAP METHOD : TIME= (O(n+m)log(n+m))

        int curgap = n + m;
        int i = 0, j = 0;
        for (curgap = getgap(curgap); curgap > 0; curgap = getgap(curgap))
        {
            for (i = 0; i + curgap < n; i++)
            { // if both ptr are on first array
                if (arr1[i] > arr1[i + curgap])
                {
                    int temp = arr1[i];
                    arr1[i] = arr1[i + curgap];
                    arr1[i + curgap] = temp;
                }
            }
            for (j = (curgap > n) ? (curgap - n) : 0; i < n && j < m; i++, j++)
            {
                if (arr1[i] > arr2[j])
                { // if one is on 1st and other on second array u need to do jhol of index of second array so see for loop
                    int temp = arr1[i];
                    arr1[i] = arr2[j];
                    arr2[j] = temp;
                }
            }
            if (j < m)
            {
                for (j = 0; j + curgap < m; j++)
                { // if both are ob second array
                    if (arr2[j] > arr2[j + curgap])
                    {
                        int temp = arr2[j];
                        arr2[j] = arr2[j + curgap];
                        arr2[j + curgap] = temp;
                    }
                }
            }
        }

        // METHOD 2 : TIME= O(n*m)
        // int x,y;
        // for(int i=n-1;i<)
        // int last;
        // for(int i=m-1;i>=0;i--)
        // {
        //     int j;
        //     last=arr1[n-1];
        //     for(j=n-1;j>=0&&arr1[j]>arr2[i];j--){

        //         arr1[j+1]=arr1[j];
        //     }
        //     if(j!=n-1||last>arr2[i]){

        //         arr1[j+1]=arr2[i];
        //         arr2[i]=last;
        //     }
        // }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends