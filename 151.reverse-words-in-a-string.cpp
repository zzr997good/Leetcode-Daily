/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        removespace(s);
        int sz=s.size();
        if(sz==0) return s;
        int word_start=-1;
        int word_end=-1;
        for(int i=0;i<sz;){
            //Reverse every single word
            word_end=word_start=i;
            while(word_end<sz&&s[word_end]!=' ') word_end++;
            reverse(s.begin()+word_start,s.begin()+word_end);
            i=word_end+1;
        }
        //Reverse the whole sentense
        reverse(s.begin(),s.end());
        return s;
    }
private:
    void removespace(string& s){
        int fast=0,slow=-1;
        while(fast<s.size()){
            //Head Space
            if(slow==-1&&s[fast]==' ') fast++;
            //Consecut Space
            else if(slow!=-1&&s[fast]==' '&&s[fast-1]==' ') fast++;
            else s[++slow]=s[fast++];
        }
        //Final space
        if(slow==-1) s.resize(0);
        else if(s[slow]==' ') s.resize(slow);
        else s.resize(slow+1);
    }
};
// @lc code=end

