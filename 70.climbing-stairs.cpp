/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        memo=vector<int>(n+1,-1);
        return dp(n);
    }
private:
    vector<int> memo;
    int dp(int n){
        if(n==0) return 1;
        if(n==1) return 1;
        if(memo[n]!=-1) return memo[n];
        memo[n]=dp(n-1)+dp(n-2);
        return memo[n];
    }
};
// @lc code=end

