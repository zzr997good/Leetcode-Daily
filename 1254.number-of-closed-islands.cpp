/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            //把周边不可能是closed island的island变成water
            //也不会影响closed island，因为closed island本身就被water包围
            dfsFlooding(grid, m, n, i, 0);
            dfsFlooding(grid, m, n, i, n-1);
        }
        for(int j=0;j<n;j++){
            dfsFlooding(grid, m, n, 0, j);
            dfsFlooding(grid, m, n, m-1,j);
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    res++;
                    dfsFlooding(grid, m, n, i, j);
                }
            }
        }
        return res;
    }
private:
    void dfsFlooding(vector<vector<int>>& grid,int m,int n,int i,int j){
        if(i<0||j<0||i>=m||j>=n) return;
        if(grid[i][j]==1) return;
        grid[i][j]=1;
        dfsFlooding(grid, m, n, i-1, j);
        dfsFlooding(grid, m, n, i+1, j);
        dfsFlooding(grid, m, n, i, j-1);
        dfsFlooding(grid, m, n, i, j+1);
    }
};
// @lc code=end

