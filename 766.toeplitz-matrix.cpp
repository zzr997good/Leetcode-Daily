/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // //Follow up1:
        // unordered_map<int,int> mp;
        // for(int row=0;row<matrix.size();row++){
        //     for(int col=0;col<matrix[0].size();col++){
        //         if(!mp.count(row-col)) mp[row-col]=matrix[row][col];
        //         else{
        //             if(matrix[row][col]!=mp[row-col]) return false;
        //         }
        //     }
        // }
        // return true;
        //Follow up2:
        for(int row=1;row<matrix.size();row++){
            for(int col=1;col<matrix[0].size();col++){
                if(matrix[row][col]!=matrix[row-1][col-1]) return false;
            }
        }
        return true;
    }
};
// @lc code=end

