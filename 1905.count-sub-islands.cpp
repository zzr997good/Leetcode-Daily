/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==0&&grid2[i][j]==1){
                    dfsFlooding(grid2, m , n, i, j);
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    dfsFlooding(grid2, m , n, i, j);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfsFlooding(vector<vector<int>>& grid,int m,int n,int i,int j){
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

