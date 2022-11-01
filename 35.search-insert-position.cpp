/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int sz=nums.size();
        int lo=0;
        int hi=sz;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target) lo=mid+1;
            else if(nums[mid]>target) hi=mid;
            else hi=mid;
        }
        return lo;
    }
};
// @lc code=end

