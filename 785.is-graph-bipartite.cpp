/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        color=vector<bool> (graph.size(),false);
        visited=vector<bool> (graph.size(),false);
        for(int i=0;i<graph.size();i++){
            if(!visited[i]&&res==true) dfs(graph,i);
        }
        return res;
    }
private:
    vector<bool> color;
    vector<bool> visited;
    bool res=true;
    void dfs(vector<vector<int>>& graph,int cur_node){
        //if(visited[cur_node]) return;
        visited[cur_node]=true;
        if(res==false) return;
        for(int adjacent_node:graph[cur_node]){
            if(visited[adjacent_node]&&color[adjacent_node]==color[cur_node]){
                res=false;
                return;
            }
            if(!visited[adjacent_node]) {
                color[adjacent_node]=!color[cur_node];
                dfs(graph,adjacent_node);
            }
        }
        return;
    }
};
// @lc code=end

