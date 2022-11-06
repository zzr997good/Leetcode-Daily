/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int left=0,right=s.size()-1;
        string tmp="aeiouAEIOU";
        unordered_set<char> vowel(tmp.begin(),tmp.end());
        while(left<right){
            if(vowel.count(s[left])&&vowel.count(s[right])) {
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else if(!vowel.count(s[left])) left++;
            else right--;
        }
        return s;
    }
};
// @lc code=end

