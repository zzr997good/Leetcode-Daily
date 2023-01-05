/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        memo=vector<vector<int>>(m,vector<int>(n,INT_MAX));
        return dp(dungeon,m,n,0,0);
    }
private:
    vector<vector<int>> memo;
    int dp(vector<vector<int>>& dungeon, int m,int n,int x, int y){
        if(x<0||y<0||x>=m||y>=n) return INT_MAX;
        if(x==m-1&&y==n-1){
            if(dungeon[x][y]>=0) return 1;
            else return 1-dungeon[x][y];
        } 
        if(memo[x][y]!=INT_MAX) return memo[x][y];
        int subproblem=min(dp(dungeon,m,n,x+1,y),dp(dungeon,m,n,x,y+1));
        if(dungeon[x][y]<0) memo[x][y]=subproblem-dungeon[x][y];
        else memo[x][y]=subproblem-dungeon[x][y]>0?subproblem-dungeon[x][y]:1;
        return memo[x][y];
    }
};
// @lc code=end

