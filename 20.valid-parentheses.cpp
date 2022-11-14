/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c:s){
            if(c=='('||c=='['||c=='{') stk.push(c);
            else{
                if(stk.empty()) return false;
                else if(!stk.empty()&&!validation(stk.top(),c)) return false;
                else stk.pop();
            }
        }
        return stk.empty();
    }

private:
    bool validation(char x,char y){
        if((x=='('&&y==')')||(x=='['&&y==']')||(x=='{'&&y=='}')) return true;
        else return false;
    }
};
// @lc code=end

