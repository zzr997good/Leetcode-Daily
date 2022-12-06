/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
//Dijkstra algorithm is a greedy algorithm
//Its accuracy is ensured by non-negative edges
//So when we get the current closest node to the source, it is impossible to get a closer node after relaxation
//This problem has the same property,when we get the current max-prob node to the source, it is impossible to get a greater-prob node after relaxation 
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,int>>> graph=buildGraph(n, edges, succProb);
        vector<double> max_prob_from_start(n,0);
        max_prob_from_start[start]=1;
        priority_queue<pair<double,int>, vector<pair<double,int>>> pq;
        pq.push({1,start});
        while(!pq.empty()){
            pair<double,int> cur_max_prob_node=pq.top();
            pq.pop();
            double prob=cur_max_prob_node.first;
            int node=cur_max_prob_node.second;
            if(prob<max_prob_from_start[node]) continue;
            if(node==end) return prob;
            for(pair<double,int>& adj:graph[node]){
                if(prob*adj.first>max_prob_from_start[adj.second]){
                    max_prob_from_start[adj.second]=prob*adj.first;
                    pq.push({prob*adj.first,adj.second});
                }
            }
        }
        return 0;
    }

private:
    vector<vector<pair<double,int>>> buildGraph(int n,vector<vector<int>>&edges,vector<double>& succProb){
        vector<vector<pair<double,int>>> graph(n,vector<pair<double,int>>());
        for(int i=0;i<edges.size();i++){
            int from=edges[i][0];
            int to=edges[i][1];
            double prob=succProb[i];
            graph[from].push_back({prob,to});
            graph[to].push_back({prob,from});
        }
        return graph;
    }
};

// //Bellman Ford (TLE)
// //Cant use topologically sort because there is cycle
// class Solution {
// public:
//     double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//         vector<double> max_prob_from_start(n,0);
//         max_prob_from_start[start]=1;
//         for(int i=0;i<n-1;i++){
//             for(int j=0;j<edges.size();j++){
//                 int node_x=edges[j][0];
//                 int node_y=edges[j][1];
//                 double prob=succProb[j];
//                 if(!max_prob_from_start[node_x]==0){
//                     if(max_prob_from_start[node_x]*prob>max_prob_from_start[node_y])
//                         max_prob_from_start[node_y]=max_prob_from_start[node_x]*prob;
//                 }
//                 if(!max_prob_from_start[node_y]==0){
//                     if(max_prob_from_start[node_y]*prob>max_prob_from_start[node_x])
//                         max_prob_from_start[node_x]=max_prob_from_start[node_y]*prob;
//                 }
//             }
//         }
//         return max_prob_from_start[end];
//     }

// };
// @lc code=end

