/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        memo=vector<vector<int>>(amount+1,vector<int>(coins.size()+1,-1));
        return dp(amount,coins,coins.size());
    }
private:
    vector<vector<int>> memo;
    int dp(int amount,vector<int>& coins,int n){
        if(amount<0) return 0;
        if(amount==0) return 1;
        if(n==0) return 0;
        if(memo[amount][n]!=-1) return memo[amount][n];
        memo[amount][n]=dp(amount-coins[n-1],coins,n)+dp(amount,coins,n-1);
        return memo[amount][n];
    }
};
// @lc code=end

