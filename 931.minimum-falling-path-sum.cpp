/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        memo=vector<vector<int>>(n,vector<int>(n,INT_MAX));
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            res=min(res,dp(matrix,0,i));
        }
        return res;
    }
private:
    vector<vector<int>> memo;
    int dp(vector<vector<int>>& matrix,int row,int col){
        if(row==matrix.size()) return 0;
        if(col<0||col>=matrix.size()) return INT_MAX;
        if(memo[row][col]!=INT_MAX) return memo[row][col];
        memo[row][col]=min(dp(matrix,row+1,col-1),min(dp(matrix,row+1,col),dp(matrix,row+1,col+1)))+matrix[row][col];
        return memo[row][col];
    }
};
// @lc code=end

