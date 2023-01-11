/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>&interval_x,vector<int>&interval_y){
        return interval_x[0]==interval_y[0]?interval_x[1]>interval_y[1]:interval_x[0]<interval_y[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int res=0;
        int start=-1;
        int end=-1;
        for(vector<int>&interval:intervals){
            if(interval[1]<=end){
                res++;
            }
            else{
                start=interval[0];
                end=interval[1];
            }
        }
        return intervals.size()-res;
    }
};
// @lc code=end

