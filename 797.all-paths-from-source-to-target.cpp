/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
//这是一个backtrack问题，不是一个dfs或者bfs问题
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        backtrack(graph, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> path;
    void backtrack(vector<vector<int>>& graph,int cur_state){
        path.push_back(cur_state);
        if(cur_state==graph.size()-1) {
            res.push_back(path);
            path.pop_back();
            return;
        }
        for(int next_state:graph[cur_state]){
            backtrack(graph,next_state);
        }
        path.pop_back();
        return;
    }
};
// @lc code=end

