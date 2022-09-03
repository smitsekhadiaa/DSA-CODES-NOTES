// Minimum Platforms
// MediumAccuracy: 46.78%Submissions: 100k+Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.

// Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.

// Example 1:

// Input: n = 6
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation:
// Minimum 3 platforms are required to
// safely arrive and depart all trains.
// Example 2:

// Input: n = 3
// arr[] = {0900, 1100, 1235}
// dep[] = {1000, 1200, 1240}
// Output: 1
// Explanation: Only 1 platform is required to
// safely manage the arrival and departure
// of all trains.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required at the railway station such that no train waits.

// Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this may be > 59).

// Expected Time Complexity: O(nLogn)
// Expected Auxiliary Space: O(n)

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    //  C++ | priority queue | easy explained ||

    // Approach : let's think little practically here what we need is priority wise arranging  trains, such that we use least platforms.

    // say we have an intelligent  data structure whose size represents the total platforms and maintains a pointer to a train of  lowest departure time among present trains on all platforms.

    // when new train comes (consider we have only one platform initially with only one train's departure data maintanded)

    // based on new train's arrival time we can

    // compare the lowest daparture time of existing trains with the arrival time of this new train.
    // if there exists such train on platforms whose departure is less than arrival time of this new train , then we will just add this new train to that platform and now data structure will maintain info of new train''s departure time and will remove the old train's data from that particular platform
    // if arrival time is greater than the existing train's lowest departure time time we will just add new platform for the train
    //  ( eventually platforms will dynamically change in the end the the required platforms  will be equal to the size of data structure)

    // we need priority queue which shows minimum element in the queue.

    // 	priority_queue<int, vector<int> , greater<int>> pq;
    // Solution :

    // store pair of arrival and departure into vector pair
    // sort vector pair as per the arrival time of trains
    // get min heap
    // if lowest departure time in existing platform queue is less
    //      than arrival time of new train then pop that train and add new train's departure time
    // else add new trains departure time to queue : assigning new platform to new train.
    // return size of platform queue.

    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({arr[i], dep[i]});
        }

        sort(vp.begin(), vp.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(vp[i].second);
            if (pq.top() < vp[i].first)
            {
                pq.pop();
            }
        }
        return pq.size();
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
}
// } Driver Code Ends