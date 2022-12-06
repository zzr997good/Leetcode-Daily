/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
// //backtracking(TLE)
// class Solution {
// public:
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int sum=0;
//         for(int num:nums) sum+=num;
//         if(sum%k!=0) return false;
//         vector<bool> used(nums.size(),false);
//         int required_sum=sum/k;
//         sort(nums.begin(),nums.end(),greater());
//         return backtracking(nums,0,k,0,required_sum,used);
//     }

//     //这道题只有唯一解，所以用bool返回值就可以
//     int satisfied_set=0;
//     bool backtracking(vector<int>& nums,int pos,int k,int sum,int required_sum,vector<bool>&used){
//         if(satisfied_set==k-1) return true;
//         if(sum==required_sum) {
//             satisfied_set++;
//             if(backtracking(nums,0,k,0,required_sum,used)) return true;
//             satisfied_set--;
//             return false;
//         }
//         for(int i=pos;i<nums.size();i++){
//             if(!used[i]&&sum+nums[i]<=required_sum){
//                 used[i]=true;
//                 if(backtracking(nums, i+1, k, sum+nums[i], required_sum, used)) return true;
//                 used[i]=false;
//             }
//         }
//         return false;
//     }
// };


//backtracking+dp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum%k!=0) return false;
        vector<bool> used(nums.size(),false);
        int required_sum=sum/k;
        sort(nums.begin(),nums.end(),greater());
        int bitmap=0;
        return backtracking(nums,0,k,0,required_sum,bitmap);
    }

    //这道题只有唯一解，所以用bool返回值就可以
    int satisfied_set=0;
    unordered_map<int, bool> memo;
    bool backtracking(vector<int>& nums,int pos,int k,int sum,int required_sum,int& bitmap){
        //Base Case
        if(satisfied_set==k-1) return true;
        //Recorded Case
        if(memo.count(bitmap)) return memo[bitmap];
        //Unrecorded Case
        if(sum==required_sum) {
            satisfied_set++;
            memo[bitmap]=backtracking(nums,0,k,0,required_sum,bitmap);
            satisfied_set--;
            return memo[bitmap];
        }
        for(int i=pos;i<nums.size();i++){
            if(!isUsed(bitmap, i)&&sum+nums[i]<=required_sum){
                setUsed(bitmap, i);
                if(backtracking(nums, i+1, k, sum+nums[i], required_sum, bitmap)) {
                    memo[bitmap]=true;
                    return true;
                }
                setUnused(bitmap, i);
            }
        }
        memo[bitmap]=false;
        return false;
    }

    bool isUsed(int& bitmap,int i){
        return (bitmap>>i)&1;
    }

    void setUsed(int& bitmap,int i){
        bitmap=bitmap|(1<<i);
    }

    void setUnused(int& bitmap,int i){
        if(isUsed(bitmap,i)) bitmap=bitmap^(1<<i);
    }
};
// @lc code=end

