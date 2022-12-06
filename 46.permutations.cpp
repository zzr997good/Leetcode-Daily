/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(nums, used, cur, res);
        return res;
    }
private:
    //nums and used is the current choices
    //cur is the current situation
    void backtracking(vector<int>&nums,vector<bool>&used,vector<int>&cur,vector<vector<int>>& res){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!used[i]){
                cur.push_back(nums[i]);
                used[i]=true;
                backtracking(nums, used,cur, res);
                used[i]=false;
                cur.pop_back();
            }
        }
    }
};
// @lc code=end

