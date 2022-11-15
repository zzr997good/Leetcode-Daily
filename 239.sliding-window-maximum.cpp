/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<int> res;
        deque<int> que;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                while(!que.empty()&&que.back()<nums[i]) que.pop_back();
                que.push_back(nums[i]);
            }
            else{
                if(nums[i-k]==que.front()) que.pop_front();
                while(!que.empty()&&que.back()<nums[i]) que.pop_back();
                que.push_back(nums[i]);
            }
            if(i>=k-1) res.push_back(que.front());
        }
        return res;
    }
};
// @lc code=end

