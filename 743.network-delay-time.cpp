/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
//Dijikstra O(V^2) requiring all weights are non-negative
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> min_dis_from_source(n,INT_MAX);
        int source=k-1;
        min_dis_from_source[source]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,source});
        vector<vector<pair<int,int>>> graph=buildGraph(times, n);
        while(!pq.empty()){
            pair<int,int> closest=pq.top();
            pq.pop();
            int closest_dis=closest.first;
            int closest_node=closest.second;
            //因为priority_queue没有办法动态的更新队内的数据，所以需要这一步来保障弹出的当前最近的点是up-to-date的信息
            if(closest_dis>min_dis_from_source[closest_node]) continue;
            for(pair<int,int>& adj:graph[closest_node]){
                if(closest_dis+adj.first<min_dis_from_source[adj.second]){
                    min_dis_from_source[adj.second]=closest_dis+adj.first;
                    pq.push({closest_dis+adj.first,adj.second});
                }
            }
        }
        //已经求得所有点的最短距离
        //检查是否有不可到达的点，并且输出结果
        int max_of_min=-1;
        for(int min_dis:min_dis_from_source){
            max_of_min=max(max_of_min,min_dis);
        }
        return max_of_min==INT_MAX?-1:max_of_min;
    }

private:
    vector<vector<pair<int,int>>> buildGraph(vector<vector<int>>& times,int n){
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        for(vector<int>&time:times){
            int from=time[0]-1;
            int to=time[1]-1;
            int weight=time[2];
            graph[from].push_back({weight,to});
        }
        return graph;
    }
};

// //Bellman Ford O(VE) 
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<int> min_dis_from_source(n,INT_MAX);
//         int source=k-1;
//         min_dis_from_source[source]=0;
//         //Origin Bellman Ford needs to relaxation every edge in V-1 iteration
//         for(int i=0;i<n-1;i++){
//             for(vector<int>&time:times){
//                 int from=time[0]-1;
//                 int to=time[1]-1;
//                 int weight=time[2];
//                 //It is impossible to relaxtion since dis to from is unknown
//                 if(min_dis_from_source[from]==INT_MAX) continue;
//                 //The dis to from is known, try to relaxtion its adjacent node
//                 if(min_dis_from_source[from]+weight<min_dis_from_source[to]){
//                     min_dis_from_source[to]=min_dis_from_source[from]+weight;
//                 }
//             }
//         }
//         int max_of_min=-1;
//         for(int min_dis:min_dis_from_source){
//             max_of_min=max(max_of_min,min_dis);
//         }
//         return max_of_min==INT_MAX?-1:max_of_min;
//     }
// };


// //Topologically Sort+Bellman Ford O(V+E) requires there is no cycle
// //Some test cases have the cycle, so the code below does not work
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<int> min_dis_from_source(n,INT_MAX);
//         int source=k-1;
//         min_dis_from_source[source]=0;
//         vector<vector<pair<int,int>>> graph=buildGraph(times, n);
//         //Topologically Sort takes O(V)
//         vector<int> order=topoSort(graph);
//         //Every edge will be relaxtion once totally, it takes O(E)
//         for(int i=n-1;i>=0;i--){
//             int node=order[i];
//             if(min_dis_from_source[node]==INT_MAX) continue;
//             for(pair<int,int>& adj:graph[node]){
//                 if(min_dis_from_source[node]+adj.first<min_dis_from_source[adj.second]){
//                     min_dis_from_source[adj.second]=min_dis_from_source[node]+adj.first;
//                 }
//             }
//         }
//         int max_of_min=-1;
//         for(int min_dis:min_dis_from_source){
//             max_of_min=max(max_of_min,min_dis);
//         }
//         return max_of_min==INT_MAX?-1:max_of_min;
//     }

// private:
//     vector<vector<pair<int,int>>> buildGraph(vector<vector<int>>& times,int n){
//         vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
//         for(vector<int>&time:times){
//             int from=time[0]-1;
//             int to=time[1]-1;
//             int weight=time[2];
//             graph[from].push_back({weight,to});
//         }
//         return graph;
//     }

//     vector<int> topoSort(vector<vector<pair<int,int>>>&graph){
//         int n=graph.size();
//         vector<int> order;
//         vector<bool> visited(n,false);
//         for(int i=0;i<n;i++){
//             if(!visited[i]) dfs(graph,i,visited,order);
//         }
//         //注意此处返回的order顺序是反的，因为push_back时间复杂度O(1)，因此我就用了push_back没有用push_front，这样到时候用这个order的时候倒着遍历就行
//         return order;
//     }

//     void dfs(vector<vector<pair<int,int>>>&graph,int cur_node,vector<bool>& visited,vector<int>& order){
//         visited[cur_node]=true;
//         for(pair<int,int>& adj:graph[cur_node]){
//             int adj_node=adj.second;
//             if(!visited[adj_node]) dfs(graph,adj_node,visited,order);
//         }
//         order.push_back(cur_node);
//     }
// };
// @lc code=end

