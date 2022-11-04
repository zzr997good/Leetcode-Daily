/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) {
                last++;
                nums[last]=nums[i];
            }
        }
        return last+1;
    }
};
// @lc code=end

