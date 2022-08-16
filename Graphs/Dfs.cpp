//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsfunc(int i, vector<int> adj[], vector<int> &dfs, unordered_map<int, bool> &vis)
    {
        dfs.push_back(i);
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (vis[it] != 1)
            {
                dfsfunc(it, adj, dfs, vis);
            }
        }
        // return dfs;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> dfs;
        unordered_map<int, bool> vis;
        // IF THERE WERE MULTIPLE GRAPHS WHICH WERE NOT CONNECTED
        //  for(int i=0;i<V;i++){
        //      if(vis[i]!=1){
        //          dfs(i,adj,dfs,vis);
        //      }
        //  }
        dfsfunc(0, adj, dfs, vis);
        return dfs;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends