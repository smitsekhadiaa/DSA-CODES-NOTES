// // 200. Number of Islands
// // Medium

// // 16632

// // 383

// // Add to List

// // Share
// // Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// // An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// // Example 1:

// // Input: grid = [
// //   ["1","1","1","1","0"],
// //   ["1","1","0","1","0"],
// //   ["1","1","0","0","0"],
// //   ["0","0","0","0","0"]
// // ]
// // Output: 1
// // Example 2:

// // Input: grid = [
// //   ["1","1","0","0","0"],
// //   ["1","1","0","0","0"],
// //   ["0","0","1","0","0"],
// //   ["0","0","0","1","1"]
// // ]
// // Output: 3
 

// // Constraints:

// // m == grid.length
// // n == grid[i].length
// // 1 <= m, n <= 300
// // grid[i][j] is '0' or '1'.
// class Solution {
// public:
// //     void bfs(int m,int n,int i,int j,vector<vector<int>> &vis,vector<vector<char>> &grid){
// //         queue<pair<int,int>> q;
// //         q.push({i,j});
// //         vis[i][j]=1;
// //         while(!q.empty()){
// //             int x=q.front().first;
// //             int y=q.front().second;
            
// //                 if(vis[i][j+1]==-1 && grid[i][j+1]=='1' && j+1<m){
// //                     q.push({i,j+1});
// //                     vis[i][j+1]=1;
// //                 }
// //                 if(vis[i][j-1]==-1 && grid[i][j-1]=='1' && j-1>=0){
// //                     q.push({i,j-1});
// //                     vis[i][j-1]=1;
// //                 }
// //                 if(vis[i+1][j]==-1 && grid[i+1][j]=='1' && i+1<n){
// //                     q.push({i+1,j});
// //                     vis[i+1][j]=1;
// //                 }
// //                 if(vis[i-1][j]==-1 && grid[i-1][j]=='1' && i-1>=0){
// //                     q.push({i-1,j});
// //                     vis[i-1][j]=1;
// //                 }
// //         }
// //     }
//     int numIslands(vector<vector<char>>& grid) {
//          vector<vector<bool>> visit(grid.size(),vector<bool>(grid[0].size(),false));
//         int count = 0;
//         queue<pair<int,int>> q;
 
//         for(int  i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
//              if(visit[i][j] || grid[i][j]=='0')continue;
//                 q.push({i,j});
//                 count++;
//                 while(q.size()){
//                     int u = q.front().first;
//                     int v = q.front().second;
//                     q.pop();
//                     if(u>=grid.size() || u<0 || v>=grid[0].size() || v<0 || visit[u][v] || grid[u][v]=='0')continue;
//                     visit[u][v] = true; 
//                    q.push({u+1,v});
//                    q.push({u-1,v});
//                    q.push({u,v+1});
//                    q.push({u,v-1}); 
//                 }  
//             }   
//         }
        

//         return count;
//     }
// };
