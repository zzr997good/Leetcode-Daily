/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class UnionFind{
public:
    UnionFind(int n){
        parent=vector<int> (n);
        rank=vector<int> (n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    bool Union(int p,int q){
        int rootP=find(p);
        int rootQ=find(q);
        if(rootP==rootQ) return false;
        if(rank[rootP]<rank[rootQ]) parent[rootP]=rootQ;
        else if(rank[rootP]>rank[rootQ]) parent[rootQ]=rootP;
        else {
            parent[rootP]=rootQ;
            rank[rootQ]++;
        }
        return true;
    }

    int find(int p){
        if(parent[p]!=p) parent[p]=find(parent[p]);
        return parent[p];
    }

    bool isUnion(int p, int q){
        int rootP=find(p);
        int rootQ=find(q);
        return rootP==rootQ;
    }
private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for(string& equation:equations){
            if(equation[1]=='=') uf.Union(equation[0]-'a', equation[3]-'a');
        }
        for(string& equation:equations){
            if(equation[1]=='!'&&uf.isUnion(equation[0]-'a', equation[3]-'a')) return false;
        }
        return true;   
    }
};
// @lc code=end

