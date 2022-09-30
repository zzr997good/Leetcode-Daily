/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //Pascal's Triangle A
        //A[n][k]=Cn,k=(n!)/[(k!)(n-k)!]
        //A[n][0]=1
        //A[n][k]/A[n][k-1]=(n-k+1)/k
        vector<int> res(rowIndex+1,1);
        for(int i=1;i<rowIndex+1;i++){
            res[i]=(int)((long long)res[i-1]*(rowIndex-i+1)/i);
        }
        return res;
    }
};
// @lc code=end

