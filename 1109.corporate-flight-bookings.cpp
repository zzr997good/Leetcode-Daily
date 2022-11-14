/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n,0);
        for(int i=0;i<bookings.size();i++){
            int start=bookings[i][0]-1;
            int end=bookings[i][1]-1;
            int addition=bookings[i][2];
            diff[start]+=addition;
            if(end+1<n) diff[end+1]-=addition;
        }
        for(int i=1;i<n;i++) diff[i]=diff[i-1]+diff[i];
        return diff;
    }
};
// @lc code=end

