/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};
// @lc code=end

