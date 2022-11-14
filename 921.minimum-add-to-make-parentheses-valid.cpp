/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int need_right=0;
        int need_left=0;
        for(char c:s){
            //Need right parentheses
            if(c=='(') need_right++;
            //Give right parentheses
            else if(need_right>0) need_right--;
            //Too much right parentheses, need left parentheses
            else need_left++;
        }
        return need_left+need_right;
    }
};
// @lc code=end

