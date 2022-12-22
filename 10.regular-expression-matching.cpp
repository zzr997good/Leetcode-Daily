/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i+=2) dp[0][i]=false;
        for(int i=1;i<=m;i++) dp[i][0]=false;
        for(int i=2;i<=n;i+=2) {
            if(p[i-1]=='*'&&dp[0][i-2]){
                dp[0][i]=true;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]==s[i-1]||p[j-1]=='.') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    if(p[j-2]==s[i-1]||p[j-2]=='.') dp[i][j]=dp[i][j-2]||dp[i][j-1]||dp[i-1][j];
                    else dp[i][j]=dp[i][j-2];
                }
                else dp[i][j]=false;
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

