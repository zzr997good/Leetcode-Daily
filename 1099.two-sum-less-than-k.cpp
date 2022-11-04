/*
 * @lc app=leetcode id=1099 lang=cpp
 *
 * [1099] Two Sum Less Than K
 */

// @lc code=start
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        int sum=-1;
        int left=0,right=nums.size()-1;
        while(left<right){
            int left_val=nums[left];
            int right_val=nums[right];
            if(nums[left]+nums[right]<k){
                sum=max(sum,nums[left]+nums[right]);
                while(nums[left]==left_val) left++;
            }
            else{
                while(nums[right]==right_val) right--;
            }
        }
        return sum;
    }
};
// @lc code=end

