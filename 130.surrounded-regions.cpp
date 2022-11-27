/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
// //UnionFind Solution
// class UnionFind{
// private:
//     vector<int> parent;
//     vector<int> rank;

// public:
//     UnionFind(int n){
//         parent=vector<int>(n);
//         rank=vector<int>(n,0);
//         for(int i=1;i<n;i++) parent[i]=i;
//     }

//     bool Union(int p,int q){
//         int rootP=find(p);
//         int rootQ=find(q);
//         if(rootP==rootQ) return false;
//         if(rank[rootP]<rank[rootQ]) parent[rootP]=rootQ;
//         else if(rank[rootP]>rank[rootQ]) parent[rootQ]=rootP;
//         else{
//             parent[rootQ]=rootP;
//             rank[rootP]++;
//         }
//         return true;
//     }

//     int find(int p){
//         if(parent[p]!=p) parent[p]=find(parent[p]);
//         return parent[p];
//     }

//     bool isUnion(int p,int q){
//         int rootP=find(p);
//         int rootQ=find(q);
//         return rootP==rootQ;
//     }
// };


// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int m=board.size();
//         int n=board[0].size();
//         UnionFind uf(m*n+1);
//         int dummy_sink=m*n;
//         for(int i=0;i<m;i++){
//             if(board[i][0]=='O') uf.Union(i*n+0,dummy_sink);
//             if(board[i][n-1]=='O') uf.Union(i*n+n-1,dummy_sink);
//         }
//         for(int j=0;j<n;j++){
//             if(board[0][j]=='O') uf.Union (j,dummy_sink);
//             if(board[m-1][j]=='O') uf.Union((m-1)*n+j,dummy_sink);
//         }
//         vector<pair<int,int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
//         for(int i=1;i<m-1;i++){
//             for(int j=1;j<n-1;j++){
//                 if(board[i][j]=='O'){
//                     for(auto direction:directions){
//                         int adjacent_x=i+direction.first;
//                         int adjacent_y=j+direction.second;
//                         if(board[adjacent_x][adjacent_y]=='O') uf.Union(i*n+j,adjacent_x*n+adjacent_y);
//                     }
//                 }
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(!uf.isUnion(i*n+j, dummy_sink)) board[i][j]='X';
//             }
//         }
//         return;

//     }
// };

//dfsFlooding Solution
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            dfsFlooding(board, i, 0);
            dfsFlooding(board, i, n-1);
        }
        for(int j=0;j<n;j++){
            dfsFlooding(board, 0, j);
            dfsFlooding(board, m-1, j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='Y') board[i][j]='X';
                else board[i][j]='O';
            }
        }
        return;
    }

    void dfsFlooding(vector<vector<char>>& board,int i,int j){
        //越界
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return;
        //遍历过了，并且已经改变过了
        if(board[i][j]=='Y') return;
        //是X，什么都不用做
        if(board[i][j]=='X') return;
        //board[i][j]=='O'
        board[i][j]='Y';
        dfsFlooding(board, i-1, j);
        dfsFlooding(board, i+1, j);
        dfsFlooding(board, i, j-1);
        dfsFlooding(board, i, j+1);
    }
};
// @lc code=end

