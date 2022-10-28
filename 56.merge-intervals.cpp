/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    static bool less(const vector<int>& ivl1, const vector<int>& ivl2){
        return ivl1[0]==ivl2[0]?ivl1[1]>ivl2[1]:ivl1[0]<ivl2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),less);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>res.back()[1]) res.push_back(intervals[i]);
            else if(intervals[i][1]>res.back()[1]) res.back()[1]=intervals[i][1];
        }
        return res;
    }
};
// @lc code=end

