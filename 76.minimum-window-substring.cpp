/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int start=-1;
        int sz=INT_MAX;
        int match=0;
        //-1 means this character is not needed
        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for(char c:t){
            need[c]++;
        }
        int left=0,right=-1;
        while(++right<s.size()){
            //Enlarge the window
            if(!need.count(s[right])) continue; //This character is not needed
            else{
                window[s[right]]++; 
                if(need[s[right]]==window[s[right]]){
                    match++; //One character is matched
                    while(match==need.size()) //All characters are matched
                    {
                    //Update the result
                    if(right-left+1<sz) {
                        start=left;
                        sz=right-left+1;
                    }
                    //Shrink the window
                    if(need.count(s[left])){
                        if(window[s[left]]==need[s[left]]) match--;
                        window[s[left]]--;
                    }
                    left++;
                    }
                }
            }
        }
        return start==-1?"":s.substr(start,sz);
    }
};
// @lc code=end

