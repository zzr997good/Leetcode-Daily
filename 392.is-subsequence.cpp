/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */
#include<string>
// @lc code=start
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i=0;
        int j=0;
        while(i<s.size()&&j<t.size()){
            if(t[j]==s[i]) i++;
            j++;
        }
        return i==s.size();
    }
};
// @lc code=end

