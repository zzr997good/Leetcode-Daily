/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int exp_sum=(1+n)*n/2;
       int sum=0;
       for(int i=0;i<nums.size();i++){
           sum+=nums[i];
       }
       return exp_sum-sum; 
    }
};
// @lc code=end

