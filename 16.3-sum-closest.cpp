/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       int sum=-50000;
        for(int i=0;i+2<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int left=nums[j],right=nums[k];
                if(abs(target-nums[i]-nums[j]-nums[k])<abs(target-sum)) sum=nums[i]+nums[j]+nums[k];
                if(nums[j]+nums[k]<target-nums[i]){
                    while(j<k&&nums[j]==left) j++;
                }
                else if(nums[j]+nums[k]>target-nums[i]){
                    while(j<k&&nums[k]==right) k--;
                }
                else return target;
            }
        }
        return sum;
    }
};
// @lc code=end

