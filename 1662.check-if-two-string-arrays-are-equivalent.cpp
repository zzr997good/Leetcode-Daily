/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        bool ans=true;
        int i=0,j=0;
        int ii=00,jj=0;
        while(i<word1.size()&&j<word2.size()){
            while(ii<word1[i].size()&&jj<word2[j].size()){
                if(word1[i][ii]!=word2[j][jj]) return false;
                ii++;
                jj++;
            }
            if(ii==word1[i].size()){
                i++;
                ii=0;
            }
            if(jj==word2[j].size()){
                j++;
                jj=0;
            }
        }
        return i==word1.size()&&j==word2.size();
    }
};
// @lc code=end

