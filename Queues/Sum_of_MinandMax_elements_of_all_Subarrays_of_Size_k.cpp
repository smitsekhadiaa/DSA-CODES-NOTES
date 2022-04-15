// Sum of minimum and maximum elements of all subarrays of size k.

// Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.
// Examples: 
 

// Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
//         K = 4
// Output : 18
// Explanation : Subarrays of size 4 are : 
//      {2, 5, -1, 7},   min + max = -1 + 7 = 6
//      {5, -1, 7, -3},  min + max = -3 + 7 = 4      
//      {-1, 7, -3, -1}, min + max = -3 + 7 = 4
//      {7, -3, -1, -2}, min + max = -3 + 7 = 4   
//      Sum of all min & max = 6 + 4 + 4 + 4 
//                           = 18               
 

// Recommended: Please try your approach on {IDE} first, before moving on to the solution.
// This problem is mainly an extension of below problem. 
// Maximum of all subarrays of size k 
// Method 1 (Simple) 
// Run two loops to generate all subarrays of size k and find maximum and minimum values. Finally, return sum of all maximum and minimum elements. 
// Time taken by this solution is O(n*k).

// Method 2 (Efficient using Dequeue) 
// The idea is to use Dequeue data structure and sliding window concept. We create two empty double-ended queues of size k (‘S’ , ‘G’) that only store indices of elements of current window that are not useless. An element is useless if it can not be maximum or minimum of next subarrays. 
 

//  a) In deque 'G', we maintain decreasing order of 
//     values from front to rear
//  b) In deque 'S', we maintain increasing order of 
//     values from front to rear

// 1) First window size K
//   1.1) For deque 'G', if current element is greater 
//        than rear end element, we remove rear while 
//        current is greater.
//   1.2) For deque 'S', if current element is smaller 
//        than rear end element, we just pop it while 
//        current is smaller.
//   1.3) insert current element in both deque 'G' 'S'

// 2) After step 1, front of 'G' contains maximum element
//    of first window and front of 'S' contains minimum 
//    element of first window. Remaining elements of G
//    and S may store maximum/minimum for subsequent 
//    windows.

// 3) After that we do traversal for rest array elements.
//   3.1) Front element of deque 'G' is greatest and 'S' 
//        is smallest element of previous window 
//   3.2) Remove all elements which are out of this 
//        window [remove element at front of queue ]
//   3.3) Repeat steps 1.1 , 1.2 ,1.3 

// 4) Return sum of minimum and maximum element of all 
//    sub-array size k.

// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;
 
// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
    int sum = 0;  // Initialize result
 
    // The queue will store indexes of useful elements
    // in every window
    // In deque 'G' we maintain decreasing order of
    // values from front to rear
    // In deque 'S' we  maintain increasing order of
    // values from front to rear
    deque< int > S(k), G(k);
 
    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        // Remove all previous greater elements
        // that are useless.
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear
 
        // Remove all previous smaller that are elements
        // are useless.
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }
 
    // Process rest of the Array elements
    for (  ; i < n; i++ )
    {
        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively
        sum += arr[S.front()] + arr[G.front()];
 
        // Remove all elements which are out of this
        // window
        while ( !S.empty() && S.front() <= i - k)
            S.pop_front();
        while ( !G.empty() && G.front() <= i - k)
            G.pop_front();
 
        // remove all previous greater element that are
        // useless
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear
 
        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }
 
    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];
 
    return sum;
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}