/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       memo=vector<vector<int>>(prices.size(),vector<int>(2,INT_MIN));
       return dp(prices,prices.size()-1,0,fee); 
    }
private:
    vector<vector<int>> memo;
    int dp(vector<int>&prices,int day,int state,int fee){
        if(day<0&&state==0) return 0;
        if(day<0&&state==1) return INT_MIN;
        if(memo[day][state]!=INT_MIN) return memo[day][state];
        if(state==0) memo[day][state]=max(dp(prices,day-1,state,fee),dp(prices,day-1,state+1,fee)+prices[day]);
        else memo[day][state]=max(dp(prices,day-1,state,fee),dp(prices,day-1,state-1,fee)-prices[day]-fee);
        return memo[day][state];
    }
};
// @lc code=end

