/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        //If this is my turn
        //I will win if there are 1 or 2 or 3 stones
        //I will lose if there are 4 stones;
        //If there are 5 stones, I can pick 1 stone and make it 4 stones, and I will win
       if(n%4==0) return false;
       else return true; 
    }
};
// @lc code=end

