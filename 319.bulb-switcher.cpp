/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

// @lc code=start
class Solution {
public:
    //因子数量为偶数则熄灭
    //因子数量为奇数(平方数)则未熄灭
    int bulbSwitch(int n) {
        //如果n的平方根最大为k
        //那么从1到n就一共有k个平方数1^2,2^2,...k^2
        return sqrt(n);
    }
};
// @lc code=end

