/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// //dp Solution O(n^2)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         memo=vector<int>(n,0);
//         for(int i=0;i<n;i++) dp(nums,i);
//         return res;
//     }
// private:
//     vector<int> memo;
//     int res=1;
//     int dp(vector<int>& nums, int n){
//         if(n==0) return 1;
//         if(memo[n]!=0) return memo[n];
//         int ans=1;
//         for(int i=n-1;i>=0;i--){
//             if(nums[i]<nums[n]) ans=max(ans,dp(nums,i)+1);
//         }
//         memo[n]=ans;
//         res=max(res,ans);
//         return memo[n];
//     }
// };

//patience sorting Solution O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int piles=0;
        for(int i=0;i<n;i++){
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

