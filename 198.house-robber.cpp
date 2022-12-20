/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        memo=vector<int>(n,-1);
        return dp(nums,n-1);
        }
private:
    //memo[i] means the maximum income when considering nums[0...i]
    vector<int> memo;
    int dp(vector<int>& nums,int n){
        if(n==0) return nums[0];
        if(n==1) return max(nums[0],nums[1]);
        if(memo[n]!=-1) return memo[n];
        memo[n]=max(nums[n]+dp(nums,n-2),dp(nums,n-1));
        return memo[n];
    }
};
// @lc code=end

