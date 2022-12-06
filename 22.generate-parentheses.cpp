/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string cur="";
        vector<string> res;
        backtracking(n, n, cur, res);
        return res;

    }
private:
    //left and right decides current choices and current position
    void backtracking(int left,int right,string& cur, vector<string>& res){
        if(left==0&&right==0) {
            res.push_back(cur);
            return;
        }
        if(left>right) return;
        if(left<0||right<0) return;
        cur+='(';
        backtracking(left-1, right, cur, res);
        cur.pop_back();
        cur+=')';
        backtracking(left, right-1, cur, res);
        cur.pop_back();
    }
};
// @lc code=end

