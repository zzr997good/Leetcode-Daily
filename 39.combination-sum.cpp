/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(candidates,0,target,cur,res);
        return res;
    }
private:
    void backtracking(vector<int>& sorted_candidates,int pos,int target,vector<int>& cur,vector<vector<int>>& res){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(target<0) return;
        for(int i=pos;i<sorted_candidates.size();i++){
            if(sorted_candidates[i]>target) break;
            cur.push_back(sorted_candidates[i]);
            backtracking(sorted_candidates,i, target-sorted_candidates[i], cur, res);
            cur.pop_back();
        }
    }
};
// @lc code=end

