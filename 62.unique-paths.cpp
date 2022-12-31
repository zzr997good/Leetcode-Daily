class Solution {
public:
    int uniquePaths(int m, int n) {
        memo=vector<vector<int>>(m,vector<int>(n,-1));
        return dp(m-1,n-1);
    }
private:
    vector<vector<int>> memo;
    int dp(int row,int col){
        if(row<0||col<0) return 0;
        if(row==0||col==0) return 1;
        if(memo[row][col]!=-1) return memo[row][col];
        memo[row][col]=dp(row-1,col)+dp(row,col-1);
        return memo[row][col]; 
    }
};