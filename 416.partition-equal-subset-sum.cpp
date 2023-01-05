/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum=0;
       for(int i:nums) sum+=i;
       if(sum%2!=0) return false;
       int half_sum=sum/2;
       int n=nums.size();
       vector<vector<bool>> dp(n+1,vector<bool>(half_sum+1,false));
       for(int i=0;i<=n;i++) dp[i][0]=true;
       for(int i=1;i<=half_sum;i++) dp[0][i]=false;
       for(int i=1;i<=n;i++){
           for(int j=1;j<=half_sum;j++){
               bool notput=dp[i-1][j];
               bool put=j-nums[i-1]>=0?dp[i-1][j-nums[i-1]]:false;
               dp[i][j]=notput||put;
           }
       }
       return dp[n][half_sum];
    }
};
// @lc code=end


