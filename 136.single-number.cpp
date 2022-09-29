/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num:nums){
            if(st.count(num)) st.erase(num);
            else st.insert(num);
        }
        return *st.begin();
    }
};
// @lc code=end

