/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memo=vector<int>(amount+1,INT_MAX);
        return dp(coins,amount);
    }
private:
    vector<int> memo;
    int dp(vector<int>& coins,int amount){
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(memo[amount]!=INT_MAX) return memo[amount];
        for(int coin:coins){
            int subproblem=dp(coins,amount-coin);
            if(subproblem==-1) continue;
            memo[amount]=min(memo[amount],subproblem+1);
        }
        if(memo[amount]==INT_MAX) memo[amount]=-1;
        return memo[amount];
    }
};
// @lc code=end

