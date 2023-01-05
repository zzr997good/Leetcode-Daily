/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memo=vector<vector<int>>(prices.size(),vector<int>(3,INT_MIN));
        return dp(prices,prices.size()-1,2);
    }
private:
    vector<vector<int>> memo;
    int dp(vector<int>& prices, int day,int state){
        if(state==0) return 0;
        if(day<0&&state==1) return INT_MIN;
        if(day<0&&state==2) return 0;
        if(memo[day][state]!=INT_MIN) return memo[day][state];
        if(state==1) memo[day][state]=max(dp(prices,day-1,state),dp(prices,day-1,2)-prices[day]);
        if(state==2) memo[day][state]=max(dp(prices,day-1,state),dp(prices,day-1,1)+prices[day]);
        return memo[day][state]; 
    }
};
// @lc code=end

