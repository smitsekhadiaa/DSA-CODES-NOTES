// Rotten Oranges
// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

// Example 1:

// Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// Output: 1
// Explanation: The grid is-
// 0 1 2
// 0 1 2
// 2 1 1
// Oranges at positions (0,2), (1,2), (2,0)
// will rot oranges at (0,1), (1,1), (2,2) and
// (2,1) in unit time.
// Example 2:

// Input: grid = {{2,2,0,1}}
// Output: -1
// Explanation: The grid is-
// 2 2 0 1
// Oranges at (0,0) and (0,1) can't rot orange at
// (0,3).

// Your Task:
// You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.

// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        // Code here
        queue<pair<int, int>> q;
        int r = grid.size();
        int c = grid[0].size();
        int i, j;
        int count = 0;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        q.push({-1, -1});
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            if (i == -1 && j == -1 && q.size() == 1)
            {
                q.pop();
                break;
            }
            else if (i == -1 && j == -1 && q.size() > 1)
            {
                count++;
                q.pop();
                q.push({-1, -1});
            }

            else
            {
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if (i + 1 < r && grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
                if (j + 1 < c && grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
                q.pop();
            }
        }
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends