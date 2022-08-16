//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.

    int minStepToReachTarget(vector<int> &k, vector<int> &t, int N)
    {
        // Code here
        vector<vector<int>> visited(N, vector<int>(N, 0));
        queue<pair<int, int>> q;
        q.push({k[0] - 1, k[1] - 1});
        visited[k[0] - 1][k[1] - 1] = 1;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            if ((p.first == t[0] - 1) && (p.second == t[1] - 1))
            {
                break;
            }

            if (p.first + 1 < N && p.second - 2 >= 0 && visited[p.first + 1][p.second - 2] == 0)
            {

                q.push({p.first + 1, p.second - 2});
                visited[p.first + 1][p.second - 2] = 1 + visited[p.first][p.second];
                if (p.first + 1 == t[0] - 1 && p.second - 2 == t[1] - 1)
                    break;
            }
            if (p.first + 2 < N && p.second - 1 >= 0 && visited[p.first + 2][p.second - 1] == 0)
            {
                q.push({p.first + 2, p.second - 1});
                visited[p.first + 2][p.second - 1] = 1 + visited[p.first][p.second];
                if (p.first + 2 == t[0] - 1 && p.second - 1 == t[1] - 1)
                    break;
            }
            if (p.first + 2 < N && p.second + 1 < N && visited[p.first + 2][p.second + 1] == 0)
            {
                q.push({p.first + 2, p.second + 1});
                visited[p.first + 2][p.second + 1] = 1 + visited[p.first][p.second];
                if (p.first + 2 == t[0] - 1 && p.second + 1 == t[1] - 1)
                    break;
            }
            if (p.first + 1 < N && p.second + 2 < N && visited[p.first + 1][p.second + 2] == 0)
            {
                q.push({p.first + 1, p.second + 2});
                visited[p.first + 1][p.second + 2] = 1 + visited[p.first][p.second];
                if ((p.first + 1 == t[0] - 1) && (p.second + 2 == t[1] - 1))
                    break;
            }
            if (p.first - 1 >= 0 && p.second - 2 >= 0 && visited[p.first - 1][p.second - 2] == 0)
            {
                q.push({p.first - 1, p.second - 2});
                visited[p.first - 1][p.second - 2] = 1 + visited[p.first][p.second];
                if ((p.first - 1 == t[0] - 1) && (p.second - 2 == t[1] - 1))
                    break;
            }
            if (p.first - 2 >= 0 && p.second - 1 >= 0 && visited[p.first - 2][p.second - 1] == 0)
            {

                q.push({p.first - 2, p.second - 1});
                visited[p.first - 2][p.second - 1] = 1 + visited[p.first][p.second];
                if ((p.first - 2 == t[0] - 1) && (p.second - 1 == t[1] - 1))
                    break;
            }
            if (p.first - 2 >= 0 && p.second + 1 < N && visited[p.first - 2][p.second + 1] == 0)
            {

                q.push({p.first - 2, p.second + 1});
                visited[p.first - 2][p.second + 1] = 1 + visited[p.first][p.second];
                if (p.first - 2 == t[0] - 1 && p.second + 1 == t[1] - 1)
                    break;
            }
            if (p.first - 1 >= 0 && p.second + 2 < N && visited[p.first - 1][p.second + 2] == 0)
            {

                q.push({p.first - 1, p.second + 2});
                visited[p.first - 1][p.second + 2] = 1 + visited[p.first][p.second];
                if (p.first - 1 == t[0] - 1 && p.second + 2 == t[1] - 1)
                    break;
            }
        }

        if (visited[t[0] - 1][t[1] - 1] == 0)
        {
            return -1;
        }
        return visited[t[0] - 1][t[1] - 1] - 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends