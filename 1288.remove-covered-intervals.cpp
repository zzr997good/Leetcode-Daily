/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
public:
    static bool less(const vector<int>& itv1,const vector<int>& itv2){
        return itv1[0]==itv2[0]?itv1[1]>itv2[1]:itv1[0]<itv2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),less);
        vector<vector<int>> res;
        int left=-1;
        int right=-1;
        for(vector<int>& interval:intervals){
            if(interval[1]<=right) continue;
            else {
                res.push_back(interval);
                left=interval[0];
                right=interval[1];
            }
        }
        return res.size();

    }
};
// @lc code=end

