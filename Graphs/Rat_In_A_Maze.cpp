//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<string> v;
    void dfs(int i, int j, vector<vector<int>> &m, int n, string s, vector<vector<bool>> &vis)
    {
        if (i >= n || j >= n || i < 0 || j < 0)
        {
            return;
        }
        if (m[i][j] == 0 || vis[i][j] == 1)
        {
            return;
        }

        if (i == n - 1 && j == n - 1)
        {
            v.push_back(s);
            return;
        }
        vis[i][j] = 1;
        dfs(i + 1, j, m, n, s + 'D', vis);
        dfs(i - 1, j, m, n, s + 'U', vis);
        dfs(i, j + 1, m, n, s + 'R', vis);
        dfs(i, j - 1, m, n, s + 'L', vis);
        vis[i][j] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        v.clear();
        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
        string s = "";
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        {
            return {"-1"};
        }
        dfs(0, 0, m, n, s, vis);
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends