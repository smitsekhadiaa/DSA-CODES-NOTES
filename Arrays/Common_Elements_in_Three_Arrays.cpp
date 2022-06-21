// Common elements
// Easy Accuracy: 38.69% Submissions: 100k+ Points: 2
// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

// Example 1:

// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80
// Explanation: 20 and 80 are the only
// common elements in A, B and C.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function commonElements() which take the 3 arrays A[], B[], C[] and their respective sizes n1, n2 and n3 as inputs and returns an array containing the common element present in all the 3 arrays in sorted order.
// If there are no such elements return an empty array. In this case the output will be printed as -1.

// Expected Time Complexity: O(n1 + n2 + n3)
// Expected Auxiliary Space: O(n1 + n2 + n3)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        // code here.
        map<int, int> mp1, mp2, mp3;
        int count = 0;
        for (int i = 0; i < n1; i++)
        {
            mp1[A[i]]++;
        }
        for (int j = 0; j < n2; j++)
        {
            mp2[B[j]]++;
        }
        for (int j = 0; j < n3; j++)
        {
            mp3[C[j]]++;
        }
        vector<int> v;
        for (int i = 0; i < n1; i++)
        {
            if (mp1[A[i]] > 0 && mp2[A[i]] > 0 && mp3[A[i]] > 0)
            {
                v.push_back(A[i]);
                mp1[A[i]] = 0;
            }
        }
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
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends