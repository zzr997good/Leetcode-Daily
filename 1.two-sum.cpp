/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            //另一半找到了
            if(mp.count(target-nums[i])){
                return {i,mp[target-nums[i]]};
            }
            //另一半没找到
            else{
                //暴力替换，因为只需要找到最多一组
                mp[nums[i]]=i;
            }
        }
        return {};
    }
};
// @lc code=end

