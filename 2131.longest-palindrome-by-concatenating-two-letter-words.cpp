/*
 * @lc app=leetcode id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int res=0;
        for(auto& word:words){
            string reverse_word=GetReverse(word);
            // //case1:word!=reverse_word
            // if(word!=reverse_word){
                if(mp.count(reverse_word)&&mp[reverse_word]>0){
                    //Get a couple
                    mp[reverse_word]--;
                    res+=4;
                }
                else mp[word]++;
        }
            // }
            // //case2:word==reverse_word
            // else{
            //     if(mp.count(reverse_word)&&mp[reverse_word]>0){
            //         //Get a couple
            //         mp[reverse_word]--;
            //         res+=4;
            //     }
            //     else mp[word]++;
            // }
            for(auto kv:mp){
                if(kv.first==GetReverse(kv.first)&&kv.second>0){
                    res+=2;
                    break;
                }
            }
            return res;
    }
private:
    string GetReverse(const string& x){
        string y="";
        y+=x[1];
        y+=x[0];
        return y;
    }
};
// @lc code=end

