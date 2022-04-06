// Next Greater Element 
// Medium Accuracy: 48.92% Submissions: 87256 Points: 4
// Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// Example 1:

// Input: 
// N = 4, arr[] = [1 3 2 4]
// Output:
// 3 4 4 -1
// Explanation:
// In the array, the next larger element 
// to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
// since it doesn't exist, it is -1.
// Example 2:

// Input: 
// N = 5, arr[] [6 8 0 1 3]
// Output:
// 8 -1 1 3 -1
// Explanation:
// In the array, the next larger element to 
// 6 is 8, for 8 there is no larger elements 
// hence it is -1, for 0 it is 1 , for 1 it 
// is 3 and then for 3 there is no larger 
// element on right and hence -1.
// Your Task:
// This is a function problem. You only need to complete the function nextLargerElement() that takes list of integers arr[ ] and N as input parameters and returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(N)



// METHOD 1: BRUTE FORCE ; TIME:O(n^2)

// { Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;


//  // } Driver Code Ends
// class Solution
// {
//     public:
//     //Function to find the next greater element for each element of the array.
//     vector<long long> nextLargerElement(vector<long long> arr, int n){
//         // Your code here
//         vector <long long> ans;
//         int flag=0;
//         for(int i=0;i<n;i++)
//         {
//             flag=1;
//             int j=i+1;
//             while(arr[j]<arr[i] && j!=n)
//             {
               
//                j++;
//             }
//             if(j==n)
//             {
//                 ans.push_back(-1);
//             }
//             else
//             {
//                 ans.push_back(arr[j]);
//             }
//         }
//       return ans;  
//     }
// };

// // { Driver Code Starts.

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
        
//         int n;
//         cin>>n;
//         vector<long long> arr(n);
//         for(int i=0;i<n;i++)
//             cin>>arr[i];
        
//         Solution obj;
//         vector <long long> res = obj.nextLargerElement(arr, n);
//         for (long long i : res) cout << i << " ";
//         cout<<endl;
//     }
// 	return 0;
// }  // } Driver Code Ends


// Method 2: STACKS ; TIME: O(n)

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){

    // METHOD 2: STACKS
    
    vector <long long> ans;
    stack<long long> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        {
            ans.push_back(-1);
        }
        else if( s.size()>0 && s.top()>arr[i])
        {
            ans.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<arr[i])
        {
            while(s.size()>0 && s.top()<arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
 
 }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends