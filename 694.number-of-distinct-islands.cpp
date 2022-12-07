/*
 * @lc app=leetcode id=694 lang=cpp
 *
 * [694] Number of Distinct Islands
 */

// @lc code=start
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> st;
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    string sequence=dfsFlooding(grid, m, n, i, j);
                    if(!st.count(sequence)){
                        res++;
                        st.insert(sequence);
                    }
                }
            }
        }
        return res;
    }
private:
    string dfsFlooding(vector<vector<int>>& grid,int m,int n, int i,int j){
        if(i<0||j<0||i>=m||j>=n) return "#";
        if(grid[i][j]==0) return "#";
        string sequence="";
        grid[i][j]=0;
        sequence=sequence+"W"+dfsFlooding(grid,m,n,i-1,j)+"S"+dfsFlooding(grid,m,n,i+1,j)+"A"+dfsFlooding(grid,m,n,i,j-1)+"D"+dfsFlooding(grid, m, n, i, j+1)+"B";
        return sequence;
    }
};
// @lc code=end

