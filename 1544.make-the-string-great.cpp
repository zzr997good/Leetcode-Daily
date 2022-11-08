/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for(char c:s){
            if(!stk.empty()&&(stk.top()-c=='A'-'a'||stk.top()-c=='a'-'A')) stk.pop();
            else{
                stk.push(c);
            }
        }
        string res="";
        while(!stk.empty()) {
            char c=stk.top();
            res+=c;
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
// @lc code=end

