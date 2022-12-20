/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
// //Dynamic Programming Solution
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         memo=vector<int>(nums.size(),10001);
//         return dp(nums,nums.size()-1);
//     }
// private:
//     vector<int> memo;
//     int dp(vector<int>& nums,int i){
//         if(i==0) return 0;
//         if(memo[i]!=10001) return memo[i];
//         for(int j=0;j<i;j++){
//             if(j+nums[j]<i) continue;
//             memo[i]=min(memo[i],dp(nums,j)+1);
//         }
//         return memo[i];
//     }
// };

//Greedy Solution
class Solution {
public:
    int jump(vector<int>& nums) {
        //记录n jumps 之内能到达的最远距离 farthest
        int jump=0;
        int farthest=0;
        //next_farthest是n+1 jumps之内能到达的最远距离
        //他应该是由fathest里面每个点再继续跳一步的结果
        int next_farthest=-1;
        int i=0;
        while(farthest<nums.size()-1){
            next_farthest=max(next_farthest,i+nums[i]);
            if(i==farthest){
                farthest=next_farthest;
                jump++;
            }
            i++;
        }
        return jump;
    }
};
// @lc code=end

