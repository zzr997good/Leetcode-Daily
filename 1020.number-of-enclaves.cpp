/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            dfsFlooding(grid, m, n, i, 0);
            dfsFlooding(grid, m, n, i, n-1);
        }
        for(int i=0;i<n;i++){
            dfsFlooding(grid, m, n, 0, i);
            dfsFlooding(grid, m, n, m-1, i);
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) res++;
            }
        }
        return res;
    }

private:
    void dfsFlooding(vector<vector<int>>& grid,int m,int n, int i,int j){
        if(i<0||j<0||i>=m||j>=n) return;
        if(grid[i][j]==0) return;
        grid[i][j]=0;
        dfsFlooding(grid, m, n, i-1, j);
        dfsFlooding(grid, m, n, i+1, j);
        dfsFlooding(grid, m, n, i, j-1);
        dfsFlooding(grid, m, n, i, j+1);
    }
};
// @lc code=end

