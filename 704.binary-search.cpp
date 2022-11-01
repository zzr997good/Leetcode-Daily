/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int sz=nums.size();
        int lo=0,hi=sz;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<target) lo=mid+1;
            else if(nums[mid]>target) hi=mid;
            else return mid;
        }
        return -1;
    }
};
// @lc code=end

