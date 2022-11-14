/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 */

// @lc code=start
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length,0);
        for(int i=0;i<updates.size();i++){
            int start=updates[i][0];
            int end=updates[i][1];
            int addition=updates[i][2];
            diff[start]+=addition;
            if(end+1<length) diff[end+1]-=addition;
        }
        for(int i=1;i<diff.size();i++){
            diff[i]=diff[i-1]+diff[i];
        }
        return diff;
    }
};
// @lc code=end

