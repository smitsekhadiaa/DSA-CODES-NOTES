// Queue Reversal 

// Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.

// Example 1:

// Input:
// 6
// 4 3 1 10 2 6

// Output: 
// 6 2 10 1 3 4

// Explanation: 
// After reversing the given
// elements of the queue , the resultant
// queue will be 6 2 10 1 3 4.
// Example 2:

// Input:
// 4
// 4 3 2 1 

// Output: 
// 1 2 3 4

// Explanation: 
// After reversing the given
// elements of the queue , the resultant
// queue will be 1 2 3 4.
// Your Task:
//  You only need to complete the function rev that takes a queue as parameter and returns the reversed queue. The printing is done automatically by the driver code.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(n)

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
void func(queue <int> &q)
{
    if(q.size()!=0)
    {
        int data;
        data=q.front();
        q.pop();
        func(q);
        q.push(data);
    }
}
queue<int> rev(queue<int> q)
{
    func(q);
    return q;
}

// ANALYSIS:
// TIME: O(n)
// SPACE: O(n)