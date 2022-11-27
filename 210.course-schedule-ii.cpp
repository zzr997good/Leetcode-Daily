/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited=vector<bool>(numCourses,false);
        visiting=vector<bool>(numCourses,false);
        vector<vector<int>> graph=buildGraph(numCourses, prerequisites);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]&&!isCycle) dfs(graph,i);
        }
        if(isCycle) return {};
        else return res;
    }
private:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses,vector<int>());
        for(vector<int>& prerequisite:prerequisites){
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        return graph;
    }

    vector<bool> visited;
    vector<bool> visiting;
    bool isCycle=false;
    vector<int> res;
    void dfs(vector<vector<int>>& graph, int cur_node){
        if(visited[cur_node]) return;
        if(visiting[cur_node]){
            isCycle=true;
            return;
        }
        if(isCycle) return;
        visiting[cur_node]=true;
        for(int next_node:graph[cur_node]){
            dfs(graph,next_node);
        }
        visiting[cur_node]=false;
        visited[cur_node]=true;
        //topological sort是要把最早结束的(sink node)放在结果的最后，所以应该是push_front
        //但是，此处图的顺序其实是反的，prerequisite[0]是结果，prerequisite[1]是前提，因此最早结束的是大部分结果的前提，因此需要放在结果最前面，用push_back
        res.push_back(cur_node);
    }
};
// @lc code=end

