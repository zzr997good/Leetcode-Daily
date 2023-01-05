/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memo=vector<vector<int>>(nums.size(),vector<int>(nums.size(),-1));
        return dp(nums,1,nums.size()-2);
    }
private:
    vector<vector<int>> memo;
    int dp(vector<int>&nums,int start,int end){
        if(start>end) return 0;
        if(memo[start][end]!=-1) return memo[start][end];
        for(int i=start;i<=end;i++){
            memo[start][end]=max(memo[start][end],nums[i]*nums[start-1]*nums[end+1]+dp(nums,start,i-1)+dp(nums,i+1,end));
        }
        return memo[start][end];
    }
};
// @lc code=end

