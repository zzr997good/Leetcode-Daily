/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

// @lc code=start
// class Solution {
// public:
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         //pq用来找与当前MST连接的edge中weight最小的那个
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         int n=points.size();
//         //用intree数组记录当前在MST中的node
//         vector<bool> intree(n,false);
//         //count记录MST中包含的node数量
//         int count=0;
//         int MST=0;
//         //每次都是从node0开始慢慢建立整棵树
//         pq.push({0,0});
//         while(count<n){
//             //找到最小的edge
//             pair<int,int> safe_edge=pq.top();
//             pq.pop();
//             int dis=safe_edge.first;
//             int node=safe_edge.second;
//             //如果那个node还没在MST上
//             if(!intree[node]){
//                 //选取那个edge
//                 intree[node]=true;
//                 count++;
//                 MST+=dis;
//                 //那个node连接到MST上，把与那个node连接的edge放入pq
//                 for(int i=0;i<n;i++){
//                     if(!intree[i]){
//                         int dis_to_node=abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]);
//                         pq.push({dis_to_node,i});
//                     }
//                 }
//             }
//         }
//         return MST;
//     }
// };

//用数组来替代priority queue
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        //This vector record the min_dis of each node to MST, if the node is in MST, min_dis=0
        vector<int> min_dis_to_MST(n,INT_MAX);
        vector<bool> intree(n,false);
        int count=0;
        int MST=0;
        min_dis_to_MST[0]=0;
        while(count<n){
            int min_dis=INT_MAX;
            int chosen_node=-1;
            //找到离当前MST最近的点，也就是min_edge
            for(int i=0;i<n;i++){
                if(!intree[i]&&min_dis_to_MST[i]<min_dis){
                    chosen_node=i;
                    min_dis=min_dis_to_MST[i];
                }
            }
            //把那个点连上MST
            intree[chosen_node]=true;
            count++;
            MST+=min_dis;
            //更新min_dis_to_MST数组，因为和之前的MST相比，只多了一个chosen_node
            //因此其他点x到MST的最近距离就是min(x和chosen_node之间的距离，x原本的最近距离)
            for(int i=0;i<n;i++){
                if(!intree[i]){
                    int dis_to_chosen_node=abs(points[i][0]-points[chosen_node][0])+abs(points[i][1]-points[chosen_node][1]);
                    min_dis_to_MST[i]=min(dis_to_chosen_node,min_dis_to_MST[i]);
                }
            }
        }
        return MST;
    }
};
// @lc code=end

