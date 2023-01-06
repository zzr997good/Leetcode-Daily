/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
       int n=word1.size();
       int m=word2.size();
       memo=vector<vector<int>>(n+1,vector<int>(m+1,-1));
       return dp(word1,n,word2,m);
    }
private:
    vector<vector<int>> memo;
    int dp(string& word1,int i,string& word2, int j){
        if(i==0) return j;
        if(j==0) return i;
        if(memo[i][j]!=-1) return memo[i][j];
        if(word1[i-1]==word2[j-1]) memo[i][j]=dp(word1,i-1,word2,j-1);
        else memo[i][j]=min(dp(word1,i-1,word2,j),dp(word1,i,word2,j-1))+1;
        return memo[i][j];
    }
};
// @lc code=end

