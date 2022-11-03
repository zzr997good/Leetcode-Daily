/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> need(26,0);
       vector<int> window(26,0);
       int left=0,right=-1;
       for(char c:s1) need[c-'a']++;
       while(++right<s2.size()){
            window[s2[right]-'a']++;
            if(right-left+1==s1.size()){
                if(window==need) return true;
                window[s2[left]-'a']--;
                left++;
            }
       }
       return false;     
    }
};
// @lc code=end

