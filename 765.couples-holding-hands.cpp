/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 */

// @lc code=start
// //UnionFind Solution
// class UnionFind{
// public:
//     UnionFind(int n){
//         parent=vector<int> (n);
//         rank=vector<int> (n,0);
//         for(int i=0;i<n;i++) parent[i]=i;
//     }

//     bool Union(int p,int q){
//         int rootP=find(p);
//         int rootQ=find(q);
//         if(rootP==rootQ) return false;
//         if(rank[rootP]<rank[rootQ]) parent[rootP]=rootQ;
//         else if(rank[rootP]>rank[rootQ]) parent[rootQ]=rootP;
//         else {
//             parent[rootP]=rootQ;
//             rank[rootQ]++;
//         }
//         return true;
//     }

//     int find(int p){
//         if(parent[p]!=p) parent[p]=find(parent[p]);
//         return parent[p];
//     }

//     bool isUnion(int p, int q){
//         int rootP=find(p);
//         int rootQ=find(q);
//         return rootP==rootQ;
//     }
// private:
//     vector<int> parent;
//     vector<int> rank;
// };

// class Solution {
// public:
//     int minSwapsCouples(vector<int>& row) {
//         int n=row.size();
//         if(n==0) return 0;
//         UnionFind uf(n);
//         //uf表示n个人的连接情况，最终想要的结果：情侣之间必须连接
//         for(int i=0;i<n;i+=2){
//             //一开始的实际情况，相邻而坐的人连接起来了
//             uf.Union(row[i], row[i+1]);
//         }
//         int res=0;
//         //对每个人进行查看，看和其情侣之间连接起来了没，没连接起来的话，就得进行一次交换
//         for(int i=0;i<n;i+=2){
//             if(!uf.isUnion(i, i+1)){
//                 res++;
//                 uf.Union(i, i+1);
//             }
//         }
//         return res;
//     }
// };

// //Greedy Solution
// class Solution {
// public:
//     int minSwapsCouples(vector<int>& row) {
//         //对于座位上的每个人，他不动，让他的情侣坐过来
//         int n=row.size();
//         if(n==0) return 0;
//         int res=0;
//         unordered_map<int,int> id_to_pos;
//         for(int i=0;i<n;i++) id_to_pos[row[i]]=i;
//         for(int i=0;i<n;i+=2){
//             int my_id=row[i];
//             int couple_id=my_id^1;
//             if(row[i+1]==couple_id) continue;
//             else{
//                 int beside_id=row[i+1];
//                 int couple_pos=id_to_pos[couple_id];
//                 swap(row[i+1],row[couple_pos]);
//                 swap(id_to_pos[beside_id],id_to_pos[couple_id]);
//                 res++;
//             }
//         }
//         return res;
//     }
// };

//Cyclic Swap Algorithm
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        if(n==0) return 0;
        int res=0;
        vector<int> id_to_pos(n);
        for(int i=0;i<n;i++) id_to_pos[row[i]]=i;
        for(int i=0;i<n;){
            int my_id=row[i];
            int couple_id=my_id^1;
            int couple_pos=id_to_pos[couple_id];
            int expected_my_pos=couple_pos^1;
            if(i==expected_my_pos) i++;
            else{
                int exchanged_id=row[expected_my_pos];
                swap(row[i],row[expected_my_pos]);
                swap(id_to_pos[my_id],id_to_pos[exchanged_id]);
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

