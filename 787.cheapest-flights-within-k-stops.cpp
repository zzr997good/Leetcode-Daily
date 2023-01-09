/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> map(n,vector<pair<int,int>>());
        for(vector<int>&edge:flights){
            map[edge[0]].push_back({edge[1],edge[2]});
        }
        memo=vector<vector<int>>(n,vector<int>(k+2,INT_MAX));
        return dp(map,src,dst,k+1);
    }
private:
    vector<vector<int>> memo;
    int dp(vector<vector<pair<int,int>>>& map,int src, int dst, int edges){
        if(src==dst) return 0;
        if(edges==0) return -1;
        if(memo[src][edges]!=INT_MAX) return memo[src][edges];
        for(pair<int,int> adj:map[src]){
            int next_src=adj.first;
            int price=adj.second;
            int subproblem=dp(map,next_src,dst,edges-1);
            if(subproblem!=-1) memo[src][edges]=min(memo[src][edges],subproblem+price);
        }
        if(memo[src][edges]==INT_MAX) memo[src][edges]=-1;
        return memo[src][edges];
    }

};
// @lc code=end

