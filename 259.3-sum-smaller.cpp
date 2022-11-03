/*
 * @lc app=leetcode id=259 lang=cpp
 *
 * [259] 3Sum Smaller
 */

// @lc code=start
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int sz=nums.size();
        if(sz<3) return 0;
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i+2<sz;i++){
            int j=i+1;
            int k=sz-1;
            while(j<k){
                int left=nums[j];
                int right=nums[k];
                if(nums[j]+nums[k]<target-nums[i]) 
                {
                    //Since nums[j]+nums[k]<new_target
                    //Then nums[j]+nums[j+1 or j+2...or k]<new_target
                    res+=(k-j);
                    j++;
                }
                else{
                    while(j<k&&nums[k]==right)
                    k--;
                }
            }
        }
        return res;
    
    }
};
// @lc code=end

