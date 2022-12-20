/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
// //dp Solution O(n)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         memo=vector<int>(n,INT_MIN);
//         dp(nums,n-1);
//         int res=INT_MIN;
//         for(int i=0;i<n;i++) res=max(res,memo[i]);
//         return res;
//     }
// private:
//     vector<int> memo;
//     int dp(vector<int>& nums,int tail_pos){
//         if(tail_pos==-1) return 0;
//         if(memo[tail_pos]!=INT_MIN) return memo[tail_pos];
//         memo[tail_pos]=max(nums[tail_pos],dp(nums,tail_pos-1)+nums[tail_pos]);
//         return memo[tail_pos];
//     }
// };

//Divide and Quanqer Solution O(nlogn)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return DivideAndQuanqer(nums, 0, n-1)[3];
    }

private:
    //This function will return four values
    //0.Sum of the whole vector
    //1.max prefix Sum of the vector
    //2.max suffix Sum of the vector
    //3.The max sum of aubarray
    //max prefix/suffix Sum of the vector is mainly used for the merged vector to get some info
    vector<int> DivideAndQuanqer(vector<int>&nums,int lo,int hi){
        if(lo==hi) return {nums[lo],nums[lo],nums[lo],nums[lo]};
        int mid=lo+(hi-lo)/2;
        vector<int> first_half=DivideAndQuanqer(nums, lo, mid);
        vector<int> second_half=DivideAndQuanqer(nums, mid+1, hi);
        int whole_sum=first_half[0]+second_half[0];
        int max_sum_prefix=max(first_half[1],first_half[0]+second_half[1]);
        int max_sum_suffix=max(second_half[2],second_half[0]+first_half[2]);
        int res=max(max(first_half[3],second_half[3]),first_half[2]+second_half[1]);
        //The max sum of subarray will happen in three conditions
        //1.that subarray is only in the first half
        //2.that subarray is only in the second half
        //3.the subarray is conposed of the first half and second half
        return {whole_sum,max_sum_prefix,max_sum_suffix,res};
    }
};

// @lc code=end

