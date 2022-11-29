/*
 * @lc app=leetcode id=1135 lang=cpp
 *
 * [1135] Connecting Cities With Minimum Cost
 */

// @lc code=start
class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int group;
public:
    UnionFind(int n){
        parent=vector<int>(n);
        rank=vector<int>(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        group=n;
    }

    int getGroup(){
        return group;
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

    bool tryUnion(int p,int q){
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
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int weight=0;
        sort(connections.begin(),connections.end(),less);
        for(vector<int>&connection:connections){
            int node_x=connection[0]-1;
            int node_y=connection[1]-1;
            int edge_weight=connection[2];
            if(!uf.isUnion(node_x, node_y)){
                uf.tryUnion(node_x, node_y);
                weight+=edge_weight;
            }
        }
        return uf.getGroup()==1?weight:-1;
    }
private:
    static bool less(const vector<int>&edge1,const vector<int>&edge2){
        return edge1[2]<edge2[2];
    }
};
// @lc code=end

