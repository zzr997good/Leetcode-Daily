/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
       int bits=0;
       while(n!=0){
           n&=n-1;
           bits++;
       } 
       return bits;
    }
};
// @lc code=end

