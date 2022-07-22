// Water Connection Problem
// MediumAccuracy: 52.42%Submissions: 9555Points: 4
// There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines.
// 1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.
// 2. Every house with only one incoming and no outgoing pipe gets a tap.
// The Geek council has proposed a network of pipes where connections are denoted by three input values: ai, bi, di denoting the pipe of diameter di from house ai to house bi.
// Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.
// Note: The generated output will have the following format. The first line will contain t, denoting the total number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, house number of tap, and the minimum diameter of pipe between them.

// Example 1:

// Input:
// n = 9, p = 6
// a[] = {7,5,4,2,9,3}
// b[] = {4,9,6,8,7,1}
// d[] = {98,72,10,22,17,66}
// Output:
// 3
// 2 8 22
// 3 1 66
// 5 6 10
// Explanation:
// Connected components are
// 3->1, 5->9->7->4->6 and 2->8.
// Therefore, our answer is 3
// followed by 2 8 22, 3 1 66, 5 6 10.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function solve() which takes an integer n(the number of houses), p(the number of pipes),the array a[] , b[] and d[] (where d[i] denoting the diameter of the ith pipe from the house a[i] to house b[i]) as input parameter and returns the array of pairs of tanks and taps installed i.e ith element of the array contains three integers: house number of tank, house number of tap and the minimum diameter of pipe between them.

// Expected Time Complexity: O(n+p)
// Expected Auxiliary Space: O(n+p)

// Constraints:
// 1<=n<=20
// 1<=p<=50
// 1<=a[i],b[i]<=20
// 1<=d[i]<=100
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void bfs(int s, int cd, int igt[], int icf[], int dia[], vector<int> &ans1)
    {
        if (igt[s] == 0)
        {
            ans1.push_back(s);
            ans1.push_back(cd);
            return;
        }
        cd = min(cd, dia[s]);
        bfs(igt[s], cd, igt, icf, dia, ans1);
        return;
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        // code here
        int igt[n + 1] = {0}; // ith_pipe_going_to
        int icf[n + 1] = {0}; // ith_pipe_coming_from
        int dia[n + 1] = {0};
        // memset(igt, 0, sizeof(igt));
        // memset(icf, 0, sizeof(icf));
        // memset(dia, 0, sizeof(dia));
        for (int i = 0; i < p; i++)
        {
            igt[a[i]] = b[i];
            icf[b[i]] = a[i];
            dia[a[i]] = d[i];
        }
        vector<vector<int>> ans;
        for (int i = 1; i < n + 1; i++)
        {
            if (igt[i] && icf[i] == 0)
            {
                int cd = dia[i];
                vector<int> ans1;
                ans1.push_back(i);
                bfs(i, cd, igt, icf, dia, ans1);
                ans.push_back(ans1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
        {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends