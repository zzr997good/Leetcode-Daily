/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size();
        int n=pizza[0].size();
        preSum=vector<vector<int>> (m+1,vector<int>(n+1,0));
        memo=vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(k,-1)));
        //Construct preSum
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                preSum[i][j]=preSum[i+1][j]+preSum[i][j+1]-preSum[i+1][j+1]+(pizza[i][j]=='A');
            }
        }
        return dp(m,n,0,0,k-1);
    }
private:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> preSum;
    int dp(int m,int n,int row,int col,int k){
        //Base Case
        if(preSum[row][col]==0) return 0;
        if(k==0) return 1;
        //If memo[row][col] is already computed
        if(memo[row][col][k]!=-1) return memo[row][col][k];
        int ans=0;
        //cut in horizontal
        for(int rrow=row+1;rrow<m;rrow++){
            if(preSum[row][col]-preSum[rrow][col]>0)
                ans=(ans+dp(m,n,rrow,col,k-1))%1000000007;
        }
        for(int ccol=col+1;ccol<n;ccol++){
            if(preSum[row][col]-preSum[row][ccol]>0)
                ans=(ans+dp(m,n,row,ccol,k-1))%1000000007;
        }
        memo[row][col][k]=ans;
        return memo[row][col][k];
    }
};
// @lc code=end

