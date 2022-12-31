/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memo=vector<vector<int>>(m,vector<int>(n,40000));
        return dp(grid,m-1,n-1);
    }
private:
    vector<vector<int>> memo;
    int dp(vector<vector<int>>&grid,int i,int j){
        //Base Case
        if(i<0||j<0) return INT_MAX;
        if(i==0&&j==0) return grid[0][0]; 
        if(memo[i][j]!=40000) return memo[i][j];
        memo[i][j]=min(dp(grid,i-1,j),dp(grid,i,j-1))+grid[i][j];
        return memo[i][j];
    }
};
// @lc code=end

