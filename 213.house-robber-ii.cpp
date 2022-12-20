/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        memo=vector<int>(n,-1);
        return max(dp(nums,0,n-2),dp(nums,1,n-1));
    }
private:
    vector<int> memo;
    int dp(vector<int>& nums,int start, int n){
        if(n<start) return 0;
        if(n==start) return nums[start];
        if(memo[n]!=-1) return memo[n];
        memo[n]=max(dp(nums,start,n-1),dp(nums,start,n-2)+nums[n]);
        return memo[n];
    }
};
// @lc code=end

