/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        memo=vector<vector<int>>(ring.size(),vector<int>(key.size(),INT_MAX));
        return dp(ring,0,key,0);
    }
private:
    vector<vector<int>> memo;
    int dp(string& ring, int pos1,string& key,int pos2){
        if(pos2==key.size()) return 0;
        if(memo[pos1][pos2]!=INT_MAX) return memo[pos1][pos2];
        int sz=ring.size();
        char c=key[pos2];
        for(int i=0;i<ring.size();i++){
            if(ring[i]==c){
                int steps=min(abs(i-pos1),sz-abs(i-pos1));
                memo[pos1][pos2]=min(memo[pos1][pos2],steps+1+dp(ring,i,key,pos2+1));
            }
        }
        return memo[pos1][pos2];
    }
};
// @lc code=end

