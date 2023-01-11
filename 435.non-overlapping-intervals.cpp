/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int right=INT_MIN;
        int res=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=right){
                right=intervals[i][1];
            }
            else{
                res++;
                right=min(right,intervals[i][1]);
            }
        }
        return res;
    }

    static bool cmp(vector<int>& interval_x,vector<int>& interval_y){
        return interval_x[0]==interval_y[0]?interval_x[1]>interval_y[1]:interval_x[0]<interval_y[0];
    }
};
// @lc code=end

