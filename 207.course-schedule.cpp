/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited=vector<bool> (numCourses,false);
        visiting=vector<bool> (numCourses,false);
        vector<vector<int>> graph=buildGraph(numCourses, prerequisites);
        for(int i=0;i<numCourses;i++){
            //如果没访问过该节点并且还没发现环，就继续dfs
            if(!visited[i]&&!isCycle) dfs(graph,i);
        }
        //有环则失败，无环(所有节点都变成了visited)则成功    
        return !isCycle;
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
    void dfs(vector<vector<int>>&graph, int cur_node){
        //访问过了，dfs结束了
        if(visited[cur_node]) return;
        //当前正在访问的路径上的
        if(visiting[cur_node]){
            isCycle=true;
            return;
        }
        //not visited or visiting
        if(isCycle) return;
        visiting[cur_node]=true;
        for(int next_node:graph[cur_node]){
            dfs(graph,next_node);
        }
        visiting[cur_node]=false;
        visited[cur_node]=true;
    }
};
// @lc code=end

