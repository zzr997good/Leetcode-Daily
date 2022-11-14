/*
 * @lc app=leetcode id=1541 lang=cpp
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int need_right=0;
        for(char c:s){
            //Meet a left parentheses and the number of current needed right parentheses is even
            if(c=='('&&!(need_right&1)) need_right+=2; 
            //Meet a left parentheses and the number of current needed right parentheses is odd
            //Add a right parentheses immediately 
            else if(c=='('&&need_right&1) {
                ans++;
                // need_right--;
                // need_right+=2;
                need_right+=1;
            }
            //Meet a right parentheses when rigtht parentheses are needed
            else if(need_right>0) need_right--;
            //Meet a right parentheses when right parentheses are not needed
            //Add a left parentheses immediately
            else {
                ans++;
                need_right+=1;
            }
        }
        return ans+need_right;
    }
};
// @lc code=end

