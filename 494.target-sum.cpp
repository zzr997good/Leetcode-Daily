/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int max_target=0;
        for(int n:nums) max_target+=abs(n);
        memo=vector<vector<int>> (nums.size()+1,vector<int>(abs(max_target)+1,-1));
        return dp(nums,nums.size(),abs(target),max_target);
    }
private:
    vector<vector<int>> memo;
    int dp(vector<int>&nums,int n,int target,int max_target){
        if(target>max_target) return 0;
        if(n==0&&target==0) return 1;
        if(n==0) return 0;
        if(memo[n][target]!=-1) return memo[n][target];
        int plus=abs(target-nums[n-1]);
        int minus=abs(target+nums[n-1]);
        memo[n][target]=dp(nums,n-1,plus,max_target)+dp(nums,n-1,minus,max_target);
        return memo[n][target];
    }
};
// @lc code=end

