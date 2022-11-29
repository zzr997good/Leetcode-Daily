/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */

// @lc code=start
// //DFS Solution
// class Solution {
// public:
//     bool validTree(int n, vector<vector<int>>& edges) {
//         visited=vector<bool>(n,false);
//         vector<vector<int>> graph=buildGraph(n,edges);
//         if(dfsIsCycle(graph,0,-1)) return false;
//         for(int i=0;i<n;i++) if(!visited[i]) return false;
//         return true;
        

//     }

// private:
//     vector<vector<int>> buildGraph(int n,vector<vector<int>>& edges){
//         vector<vector<int>> graph(n,vector<int>());
//         for(vector<int>& edge:edges){
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
//         return graph;
//     }

//     vector<bool> visited;
//     bool dfsIsCycle(vector<vector<int>>&graph, int cur_node,int parent){
//         visited[cur_node]=true;
//         for(int adjacent_node:graph[cur_node]){
//             if(!visited[adjacent_node]){
//                 if(dfsIsCycle(graph,adjacent_node,cur_node)) return true;
//             }
//             else{
//                 if(adjacent_node!=parent) return true;
//             }
//         }
//         return false;
//     }
// };

class UnionFind{
public:
    UnionFind(int n){
        parent=vector<int>(n);
        rank=vector<int>(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        group=n;
    }

    int find(int p){
        if(parent[p]!=p) parent[p]=find(parent[p]);
        return parent[p];
    }

    bool isUnion(int p,int q){
        int rootp=find(p);
        int rootq=find(q);
        return rootp==rootq;
    }

    bool Union(int p,int q){
        int rootp=find(p);
        int rootq=find(q);
        if(rootp==rootq) return false;
        if(rank[rootp]<rank[rootq]) parent[rootp]=rootq;
        else if(rank[rootp]>rank[rootq]) parent[rootq]=rootp;
        else{
            parent[rootp]=rootq;
            rank[rootq]++;
        }
        group--;
        return true;
    }

    int getGroup(){
        return group;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int group;
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(vector<int>& edge:edges){
            if(uf.isUnion(edge[0], edge[1])) return false;
            else{
                uf.Union(edge[0],edge[1]);
            }
        }
        return uf.getGroup()==1;
    }
};
// @lc code=end

