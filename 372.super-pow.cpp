/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

// @lc code=start
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a==1) return 1;
        if(b.size()==0) return 1;
        int sz=b.size();
        int digit=b[sz-1];
        b.pop_back();
        return reminderOfPow(superPow(a,b),10)*reminderOfPow(a, digit)%base;
    }
private:
    const int base=1337;
    int reminderOfPow(int a,int b){
        int mul=a%base;
        int res=1;
        for(int i=0;i<b;i++){
            res=(res*mul)%base;
        }
        return res;
    }
};
// @lc code=end

