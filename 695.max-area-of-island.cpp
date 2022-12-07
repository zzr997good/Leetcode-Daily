/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) res=max(res,dfsFlooding(grid, m, n, i, j));
            }
        }
        return res;
    }

    int dfsFlooding(vector<vector<int>>& grid,int m,int n,int i,int j){
        if(i<0||j<0||i>=m||j>=n) return 0;
        if(grid[i][j]==0) return 0;
        grid[i][j]=0;
        return 1+dfsFlooding(grid, m, n, i-1, j)+dfsFlooding(grid, m, n, i+1, j)+dfsFlooding(grid, m, n, i, j-1)+dfsFlooding(grid, m, n, i, j+1);
    }
};
// @lc code=end

