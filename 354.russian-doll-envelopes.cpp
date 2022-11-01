/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */
#include<vector>
// @lc code=start
class Solution {
static bool less(const std::vector<int>& evp1, const std::vector<int>& evp2){
    return evp1[0]==evp2[0]?evp1[1]>evp2[1]:evp1[0]<evp2[0];
}
public:
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),less);
        std::vector<int> heights;
        for(int i=0;i<envelopes.size();i++) heights.push_back(envelopes[i][1]);
        return LongestIncreaseSeq(heights);
    }

private:
    // //DP leads to TLE!!
    // int LongestIncreaseSeq(std::vector<int>&nums){
    //     int res=1;
    //     std::vector<int> dp(nums.size(),1);
    //     for(int i=1;i<nums.size();i++){
    //         for(int j=0;j<i;j++){
    //             if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
    //         }
    //         res=max(res,dp[i]);
    //     }
    //     return res;
    // }
    int LongestIncreaseSeq(std::vector<int>&nums){
        int sz=nums.size();
        int piles=0;
        for(int i=0;i<sz;i++){
            int lo=0,hi=piles;
            while(lo<hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]<nums[i]) lo=mid+1;
                else if(nums[mid]>nums[i]) hi=mid;
                else hi=mid;
            }
            if(lo==piles) piles++;
            nums[lo]=nums[i];
        }
        return piles;
    }
};

// @lc code=end

