/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        memo=vector<int> (n+1,-1);
        return dp(n);
    }

private:
    vector<int> memo;
    int dp(int n){
        if(n==0) return 1;
        if(memo[n]!=-1) return memo[n];
        int res=0;
        for(int i=1;i<=n;i++){
            int left=dp(i-1);
            int right=dp(n-i);
            res+=left*right;
        }
        memo[n]=res;
        return memo[n];
    }
};
// @lc code=end

