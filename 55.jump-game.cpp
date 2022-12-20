/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
// //DP Solution (TLE)
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         memo=vector<int>(nums.size(),-1);
//         return dp(nums,nums.size()-1);
//     }
// private:
//     vector<int> memo;
//     int dp(vector<int>&nums, int end){
//         if(end==0) return 1;
//         if(memo[end]!=-1) return memo[end];
//         for(int i=0;i<end;i++){
//             if(dp(nums,i)==1&&i+nums[i]>=end){
//                 memo[end]=1;
//                 return memo[end];
//             }
//         }
//         memo[end]=0;
//         return memo[end];
//     }
// };

//Greedy Solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0;
        for(int i=0;i<=farthest&&i<n;i++){
            farthest=max(farthest,i+nums[i]);
        }
        if(farthest>=n-1) return true;
        else return false;
    }
};
// @lc code=end

