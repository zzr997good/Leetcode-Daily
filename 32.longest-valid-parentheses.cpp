/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk; //This is an index stack
        bool new_turn=true;
        int new_start=-1;
        int res=0;
        for(int i=0;i<s.size();i++){
            //stack only pushes the left parentheses
            if(s[i]=='(') {
                if(new_turn) {
                    new_start=i;
                    new_turn=false;
                }
                stk.push(i);
            }
            //Meet the right parentheses
            //If it is not needed, window starts from next char
            else if(stk.empty()) new_turn=true;
            //If it is needed
            else{
                //Match
                stk.pop();
                //1.Enlarge the window and renew the result
                if(stk.empty()) res=max(res,i-new_start+1);
                //2.Some waiting left parentheses is matched, renew the result
                //stk.top() is the next ( waiting to be matched, suppose its index is x
                //if x+1 is ), it should not in the stk
                //so s+1 is (, and it is already matched.
                else res=max(res,i-stk.top());
            }
        }
        return res;
    }
};
// @lc code=end

