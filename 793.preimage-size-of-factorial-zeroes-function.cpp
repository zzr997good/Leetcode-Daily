/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */
#include<climits>
// @lc code=start
class Solution {
public:
    int preimageSizeFZF(int k) {
        //return f(INT_MAX)>1e+9;
        //The equation above returns false, which means INT_MAX! has less tail-0 than 10^9
        long long left=FindFirstNum(k);
        long long right=FindFirstNum(k+1);
        return (int) (right-left);
    }
private:
    long long FindFirstNum(long long k){
        long long lo=0,hi=LLONG_MAX;
        while(lo<hi){
            long long mid=lo+(hi-lo)/2;
            if(f(mid)<k) lo=mid+1;
            else if(f(mid)>k) hi=mid;
            else hi=mid;
        }
        return lo;
    }
    long long f(long long x){
        long long res=0;
        while(x/5>0){
            res+=x/5;
            x/=5;
        }
        return res;
    }
};
// @lc code=end
