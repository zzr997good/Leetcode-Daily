/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
// //backtracking (TLE)
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         if(nums.size()==0) return 0;
//         int sum=0;
//         return backtrack(nums, target, 0, sum);
//     }

// private:
//     int backtrack(vector<int>&nums,int target,int pos,int sum){
//         if(pos==nums.size()&&sum==target) return 1;
//         if(pos==nums.size()) return 0;
//         int res=0;
//         res+=backtrack(nums, target, pos+1, sum+nums[pos]);
//         res+=backtrack(nums,target,pos+1,sum-nums[pos]);
//         return res;
//     }
// };

//dynamic programming: dp[i][j]表示通过添加加减号让前i个数字的和等于j的方法数
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int max_sum=0;
        for(int num:nums) max_sum+=abs(num);
        if(abs(target)>max_sum) return 0;
        vector<vector<int>> dp(n+1,vector<int>(max_sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=max_sum;j++){
                //dp[i][j]和dp[i][-j]应该是相等的，因为如果和为负数，那么所有符号取反就得到正数和
                //....+nums[i-1]=j
                int use_plus=abs(j-nums[i-1]);
                //....-nums[i-1]=j
                int use_minus=abs(j+nums[i-1]);
                dp[i][j]=(use_plus<=max_sum?dp[i-1][use_plus]:0)+(use_minus<=max_sum?dp[i-1][use_minus]:0);
            }
        }
        return dp[n][abs(target)];
    }

};
// @lc code=end

