/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string str:strs){
            mp[StrSort(str)].push_back(str);
        }
        vector<vector<string>> res;
        for(auto v:mp) res.push_back(v.second);
        return res;
    }
private:
    string StrSort(string& str){
        string res="";
        vector<int> count(26,0);
        for(char c:str){
            count[c-'a']++;
        }
        for(int i=0;i<26;i++)
            res=res+"#"+to_string(count[i]);
        return res;
    }
};
// @lc code=end

