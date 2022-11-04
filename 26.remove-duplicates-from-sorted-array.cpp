/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last=-1;
        for(int next=0;next<nums.size();next++){
            if(last==-1||nums[next]!=nums[last]){
                last++;
                nums[last]=nums[next];
            }
        }
        return last+1;
    }
};
// @lc code=end

