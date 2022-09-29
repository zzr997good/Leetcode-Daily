/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dim=matrix.size();
        int rotate_times=dim/2;
        for(int pass=0;pass<rotate_times;pass++){
            //控制外圈
            int boundary=dim-(pass+1);
            for(int index=pass;index<boundary;index++){
                //正方形四角坐标
                //[pass,pass]----------------[pass,boundary]
                //[boundary,pass]------------[boundary,boundary]
                int offset=index-pass;
                //每一条边对应四个元素坐标  
                // matrix[pass][index];
                // matrix[index][boundary];
                // matrix[boundary][boundary-index];
                // matrix[boundary-index][pass];
                int temp1=matrix[pass][index];
                int temp2=matrix[index][boundary];
                int temp3=matrix[boundary][boundary-offset];
                int temp4=matrix[boundary-offset][pass];

                matrix[pass][index]=temp4;
                matrix[index][boundary]=temp1;
                matrix[boundary][boundary-offset]=temp2;
                matrix[boundary-offset][pass]=temp3;
            }
        }
    }
};
// @lc code=end

