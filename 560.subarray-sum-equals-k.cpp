/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sz=nums.size();
        int res=0;
        vector<int> preSum(sz+1,0);
        unordered_map<int,int> mp;
        mp.insert({0,1});
        for(int i=1;i<=sz;i++) {
            preSum[i]=preSum[i-1]+nums[i-1];
            if(mp.count(preSum[i]-k)) res+=mp[preSum[i]-k];
            mp[preSum[i]]++;
        }
        return res;
    }
};
// @lc code=end

