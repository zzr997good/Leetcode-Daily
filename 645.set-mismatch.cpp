/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1;
        int missing=-1;
        for(int i=0;i<nums.size();i++){
            int num_index=abs(nums[i])-1;
            if(nums[num_index]<0) dup=num_index+1;
            else nums[num_index]*=-1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) missing=i+1;
        }
        return {dup,missing};
    }
};
// @lc code=end

