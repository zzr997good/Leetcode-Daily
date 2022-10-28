/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
       int i=0,j=0;
        vector<vector<int>> res;
       while(i<firstList.size()&&j<secondList.size()){
           int left=max(firstList[i][0],secondList[j][0]);
           int right=min(firstList[i][1],secondList[j][1]);
           if(left<=right) res.push_back({left,right});
           if(secondList[j][1]>firstList[i][1]) i++;
           else j++;
       }
        return res;
    }
};
// @lc code=end

