/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo=vector<vector<int>>(text1.size()+1,vector<int>(text2.size()+1,-1));
        return dp(text1,text1.size(),text2,text2.size());
    }
private:
    vector<vector<int>> memo;
    int dp(string &text1,int i,string &text2, int j){
        if(i==0||j==0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(text1[i-1]==text2[j-1]) memo[i][j]=dp(text1,i-1,text2,j-1)+1;
        else memo[i][j]=max(dp(text1,i-1,text2,j),dp(text1,i,text2,j-1));
        return memo[i][j];
    }
};
// @lc code=end

