/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    //bottom to top,memorization
    int numSquares(int n) {
        vector<int> dp(n+1,10001);
        dp[0]=0;
        for(int square_num=1;square_num*square_num<=n;square_num++){
            //当前考虑的平方数从1...square*squre
            for(int j=square_num*square_num;j<=n;j++){
                //只考虑当前平方数的话dp[j]表示最少需要多少个平方数求和
                if(dp[j-square_num*square_num]!=10001){
                    dp[j]=min(dp[j],1+dp[j-square_num*square_num]);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

