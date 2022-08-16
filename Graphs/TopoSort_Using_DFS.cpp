// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution
// {
// public:
//     // Function to return list containing vertices in Topological order.
//     void topo(int node, vector<int> &ans, unordered_map<int, int> &vis, vector<int> adj[], stack<int> &st)
//     {
//         vis[node] = 1;

//         for (auto it : adj[node])
//         {
//             if (!vis[it])
//             {
//                 topo(it, ans, vis, adj, st);
//             }
//         }
//         st.push(node);
//     }
//     vector<int> topoSort(int V, vector<int> adj[])
//     {
//         // code here
//         unordered_map<int, int> vis;
//         stack<int> st;
//         vector<int> ans;
//         for (int i = 0; i < V; i++)
//         {
//             if (!vis[i])
//             {
//                 topo(i, ans, vis, adj, st);
//             }
//         }
//         while (!st.empty())
//         {
//             int a = st.top();
//             st.pop();
//             ans.push_back(a);
//         }
//         return ans;
//     }
// };

// //{ Driver Code Starts.

// /*  Function to check if elements returned by user
//  *   contains the elements in topological sorted form
//  *   V: number of vertices
//  *   *res: array containing elements in topological sorted form
//  *   adj[]: graph input
//  */
// int check(int V, vector<int> &res, vector<int> adj[])
// {

//     if (V != res.size())
//         return 0;

//     vector<int> map(V, -1);
//     for (int i = 0; i < V; i++)
//     {
//         map[res[i]] = i;
//     }
//     for (int i = 0; i < V; i++)
//     {
//         for (int v : adj[i])
//         {
//             if (map[i] > map[v])
//                 return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     int T;
//     cin >> T;
//     while (T--)
//     {
//         int N, E;
//         cin >> E >> N;
//         int u, v;

//         vector<int> adj[N];

//         for (int i = 0; i < E; i++)
//         {
//             cin >> u >> v;
//             adj[u].push_back(v);
//         }

//         Solution obj;
//         vector<int> res = obj.topoSort(N, adj);

//         cout << check(N, res, adj) << endl;
//     }

//     return 0;
// }
// // } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        queue<int> q;
        vector<int> topo;
        vector<int> indegree(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */

// KAHNS ALGO USING BFS
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends