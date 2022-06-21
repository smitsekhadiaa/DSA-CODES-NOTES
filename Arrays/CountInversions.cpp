// Count Inversions
// Medium Accuracy: 39.43% Submissions: 100k+ Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.
// Given an array of integers. Find the Inversion Count in the array.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Example 1:

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5
// has three inversions (2, 1), (4, 1), (4, 3).
// Example 2:

// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already
// sorted so there is no inversion count.
// Example 3:

// Input: N = 3, arr[] = {10, 10, 10}
// Output: 0
// Explanation: As all the elements of array
// are same, so there is no inversion count.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array as inputs and returns the inversion count of the given array.

// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long l, long long mid, long long r)
    {
        long long int i = l;
        long long int j = mid + 1;
        long long int k = l;
        long long int B[r + 1];
        long long int count = 0;

        while (i <= mid && j <= r)
        {
            if (arr[i] > arr[j])
            {
                count += mid - i + 1; // extra line added in merge sort
                B[k++] = arr[j++];
            }
            else
                B[k++] = arr[i++];
        }

        while (i <= mid)
        {
            B[k++] = arr[i++];
        }
        while (j <= r)
        {
            B[k++] = arr[j++];
        }

        for (int k = l; k <= r; k++)
        {
            arr[k] = B[k];
        }
        return count;
    }
    long long int merge_sort(long long a[], long long si, long long ei)
    {
        if (si >= ei)
        {
            return 0;
        }
        long long mid = (si + ei) / 2;
        long long int x = merge_sort(a, si, mid);
        long long int y = merge_sort(a, mid + 1, ei);
        long long int z = merge(a, si, mid, ei);
        return x + y + z;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return merge_sort(arr, 0, N - 1);
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends