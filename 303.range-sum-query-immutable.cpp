/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        preSum=vector<int>(nums.size()+1,0);
        for(int i=1;i<preSum.size();i++) preSum[i]=preSum[i-1]+nums[i-1];
    }
    
    int sumRange(int left, int right) {
        return preSum[right+1]-preSum[left];
    }
private:
    vector<int> preSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

