/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
// //Flooding在原数组的基础上进行直接修改，visited过的1直接变为0
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int res=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]=='1'){
//                     res++;
//                     dfsFlooding(grid, m, n, i, j);
//                 }
//             }
//         }
//         return res;
//     }

//     void dfsFlooding(vector<vector<char>>& grid,int m,int n,int i,int j){
//         if(i<0||j<0||i>=m||j>=n) return;
//         if(grid[i][j]=='0') return;
//         grid[i][j]='0';
//         dfsFlooding(grid,m,n,i-1,j);
//         dfsFlooding(grid, m, n, i+1, j);
//         dfsFlooding(grid, m, n, i, j-1);
//         dfsFlooding(grid, m, n, i, j+1);
//     }
// };

//传统DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    res++;
                    dfsFlooding(grid, m, n, i, j,visited);
                }
            }
        }
        return res;
    }

    void dfsFlooding(vector<vector<char>>& grid,int m,int n,int i,int j,vector<vector<bool>>& visited){
        if(i<0||j<0||i>=m||j>=n) return;
        if(grid[i][j]=='0') return;
        if(visited[i][j]) return;
        visited[i][j]=true;
        dfsFlooding(grid,m,n,i-1,j,visited);
        dfsFlooding(grid, m, n, i+1, j,visited);
        dfsFlooding(grid, m, n, i, j-1,visited);
        dfsFlooding(grid, m, n, i, j+1,visited);
    }
};
// @lc code=end

