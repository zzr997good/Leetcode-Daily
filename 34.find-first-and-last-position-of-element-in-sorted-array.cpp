/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=FindFirstIndex(nums,target);
        int right=FindLastIndex(nums,target);
        return {left,right};
    }
private:
    //This function will find the first element that is equal or greater than target
    int FindFirstIndex(vector<int>& nums, int target){
        int sz=nums.size();
        int lo=0,hi=sz;
        while(lo<hi){
            int mid =lo+(hi-lo)/2;
            if(nums[mid]<target) lo=mid+1;
            else if (nums[mid]>target) hi=mid;
            else hi=mid;
        }
        if(lo==sz) return -1;
        return nums[lo]==target?lo:-1;
    }

       //This function will find the first element that is greater than target
    int FindLastIndex(vector<int>& nums, int target){
        int sz=nums.size();
        int lo=0,hi=sz;
        while(lo<hi){
            int mid =lo+(hi-lo)/2;
            if(nums[mid]<target) lo=mid+1;
            else if (nums[mid]>target) hi=mid;
            else lo=mid+1;
        }
        if(lo==0) return -1; //从lo开始的数字都比target大
        return nums[lo-1]==target?lo-1:-1;
    }
};
// @lc code=end

