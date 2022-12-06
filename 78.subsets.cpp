/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(nums, 0, cur,res);
        return res;
    }

private:
    //当前的集合状态为cur
    //当前的选择有nums[pos]-nums[end]的所有元素，都可以选择包含获胜则不包含
    void backtracking(vector<int>&nums,int pos,vector<int>& cur,vector<vector<int>>& res){
        //不包含任何元素，那么当前集合就是一个子集
        res.push_back(cur);
        for(int i=pos;i<nums.size();i++){
            //包含该元素
            cur.push_back(nums[i]);
            //更新集合状态和新的选择子问题
            backtracking(nums, i+1, cur, res);
            //不包含该元素
            cur.pop_back();
        }
    }
};
// @lc code=end

