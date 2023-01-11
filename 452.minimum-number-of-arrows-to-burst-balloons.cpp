/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>&point_x,vector<int>&point_y){
        return point_x[0]==point_y[0]?point_x[1]>point_y[1]:point_x[0]<point_y[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end(),cmp);
       int res=0;
       int end=points[0][1];
       for(int i=1;i<points.size();i++){
           if(points[i][0]>end){
               res++;
               end=points[i][1];
           }
           else{
               end=min(end,points[i][1]);
           }
       }
       res++;
       return res;
    }
};
// @lc code=end

