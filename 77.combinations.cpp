/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        backtracking(n, 1, cur, k, res);
        return res;
    }

    //n and start is the current choices
    //cur is the current situation
    //k is the amount of number required
    void backtracking(int n,int start,vector<int>& cur, int k,vector<vector<int>>& res){
        if(k==0){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<=n;i++){
            cur.push_back(i);
            backtracking(n,i+1,cur,k-1,res);
            cur.pop_back();
        }
    }
};
// @lc code=end

