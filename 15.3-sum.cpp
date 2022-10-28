/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> TwoSum(vector<int>& nums,int start,int target){
        int sz=nums.size();
        int lo=start;
        int hi=nums.size()-1;
        vector<vector<int>> res;
        while(lo<hi){
            int left=nums[lo];
            int right=nums[hi];
            if(left+right<target){
                while(lo<hi&&nums[lo]==left) lo++;
            }
            else if(left+right>target){
                while(lo<hi&&nums[hi]==right) hi--;
            }
            else{
                res.push_back({left,right});
                while(lo<hi&&nums[lo]==left) lo++;
                while(lo<hi&&nums[hi]==right) hi--;
            }
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first=0;
        vector<vector<int>> res;
        while(first<nums.size()-2){
            int left=nums[first];
            if(left>0) break;
            vector<vector<int>> subproblem=TwoSum(nums,first+1,-left);
            for(vector<int>& subres:subproblem){
                subres.push_back(left);
                res.push_back(subres);
            }
            while(first<nums.size()-2&&nums[first]==left) first++;
        }
        return res;
    }
};
// @lc code=end

