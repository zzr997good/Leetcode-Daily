/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, 1, k);
        return res;
    }
private:
    vector<int> cur;
    vector<vector<int>> res;
    void backtrack(int n,int start, int k){
        if(cur.size()==k) res.push_back(cur);
        for(int i=start;i<=n;i++){
            cur.push_back(i);
            backtrack(n, i+1, k);
            cur.pop_back();
        }
    }
};
// @lc code=end

