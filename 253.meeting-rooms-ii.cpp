/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */

// @lc code=start
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> timeline;
        int count=0;
        int res=0;
        for(vector<int>& interval:intervals){
            timeline.push_back({interval[0],1});
            timeline.push_back({interval[1],0});
        }
        sort(timeline.begin(),timeline.end());
        for(pair<int,int>& time:timeline){
            if(time.second==1) count++;
            else count--;
            res=max(res,count);
        }
        return res;
    }
};
// @lc code=end

