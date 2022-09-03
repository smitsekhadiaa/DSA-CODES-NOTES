//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool iscycle(int node, unordered_map<int, int> &vis, unordered_map<int, int> &dfsvis, vector<int> adj[])
    {
        dfsvis[node] = 1;
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (iscycle(it, vis, dfsvis, adj))
                {
                    return true;
                }
            }
            else if (vis[it] == 1 && dfsvis[it] == 1)
            {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        unordered_map<int, int> vis;
        unordered_map<int, int> dfsvis;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (iscycle(i, vis, dfsvis, adj) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends