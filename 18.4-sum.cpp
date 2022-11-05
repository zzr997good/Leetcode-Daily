/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz=nums.size();
        if(sz<4) return {};
        sort(nums.begin(),nums.end());
        //四数之和优化：如果第一个数字大于taget/4或者最后一个数字小于target/4说明不可能构成target
        //该优化可以用来优化k数之和的递归写法
        if(nums[0]>target/4) return {};
        if(nums[sz-1]<target/4) return {};
        vector<vector<int>> res;
        for(int first=0;first+3<nums.size();){
            //确定一个数字后变成三数之和问题
            //三数之和优化：如果第一个数字大于new_target/3或者最后一个数字小于new_target/3说明不可能构成new_target
            //如果情况1，第一个数字也不用继续遍历了，因为选择当前的first，后面所有的数字想要构成new_target=target-nums[first]而言都太大，如果first++，nums[first]继续变大，那么需要的三数之和new_target就会继续变小，平均数也会继续变小,但是从first+2开始的所有数字会更大，所以直接break了
            if(nums[first+1]>(target-nums[first])/3) break;
            //如果情况2，第一个数字要继续遍历了，因为选择当前的first，后面所有的数字想要构成new_target=target-nums[first]而言都太小，如果first++，nums[first]变大，那么需要的三数之和new_target就会继续变小，平均数也会继续变小,有可能到某个情况下，nums[sz-1]<(target-nums[first])/3，就有可能找到三元组
            if(nums[sz-1]<(target-nums[first])/3){
                int first_num=nums[first];
                while(first+3<nums.size()&&nums[first]==first_num) first++;
                continue;
                }
            for(int second=first+1;second+2<nums.size();){
                int third=second+1;
                int fourth=sz-1;
                while(third<fourth){
                    int left=nums[third];
                    int right=nums[fourth];
                    long long tmp=(long long)target-nums[first]-nums[second];
                    if(nums[third]+nums[fourth]<tmp)
                        while(third<fourth&&nums[third]==left) third++;
                    else if(nums[third]+nums[fourth]>tmp)
                        while(third<fourth&&nums[fourth]==right) fourth--;
                    else{
                        res.push_back({nums[first],nums[second],nums[third],nums[fourth]});
                        while(third<fourth&&nums[third]==left) third++;
                         while(third<fourth&&nums[fourth]==right) fourth--;
                    }
                }
                int second_num=nums[second];
                while(second+2<nums.size()&&nums[second]==second_num) second++;
            }
            int first_num=nums[first];
            while(first+3<nums.size()&&nums[first]==first_num) first++;
        }
        return res;
    }
};
// @lc code=end

