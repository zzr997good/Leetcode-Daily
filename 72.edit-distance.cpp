/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        memo=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return dp(word1,m,word2,n);
}
private:
    vector<vector<int>> memo;
    int dp(string& word1, int i,string& word2, int j){
        if(i==0) return j;
        if(j==0) return i;
        if(memo[i][j]!=-1) return memo[i][j];
        if(word1[i-1]==word2[j-1]) memo[i][j]=dp(word1,i-1,word2,j-1);
        //if word1[i-1]!=word2[j-1], there are three possible operations
        //1.delete the word[i-1]
        else memo[i][j]=min(min(dp(word1,i-1,word2,j),dp(word1,i-1,word2,j-1)),dp(word1,i,word2,j-1))+1;
        return memo[i][j];
    }

};
// @lc code=end

