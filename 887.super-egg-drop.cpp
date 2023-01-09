/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int k, int n) {
        memo=vector<vector<int>>(k+1,vector<int>(n+1,INT_MAX));
        return dp(k,n);
    }
private:
    vector<vector<int>> memo;
    int dp(int k,int n){
        if(k==1) return n;
        if(n==0) return 0;
        if(memo[k][n]!=INT_MAX) return memo[k][n];
        int lo=1,hi=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int broke=dp(k-1,mid-1);
            int unbroke=dp(k,n-mid);
            if(broke<unbroke) lo=mid+1;
            else hi=mid-1;
            memo[k][n]=min(memo[k][n],1+max(broke,unbroke));
        }
        return memo[k][n];
    }
};
// @lc code=end

