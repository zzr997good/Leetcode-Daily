/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001,0);
        for(int i=0;i<trips.size();i++){
            int addition=trips[i][0];
            int start=trips[i][1];
            int end=trips[i][2];
            diff[start]+=addition;
            if(end<=1000) diff[end]-=addition;
        }
        for(int i=1;i<1001;i++) diff[i]=diff[i-1]+diff[i];
        for(int i=0;i<1001;i++) if(diff[i]>capacity) return false;
        return true;
    }
};
// @lc code=end

