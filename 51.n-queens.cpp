/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curboard(n,string(n,'.'));
        vector<vector<string>> res;
        backtracking(n, 0, curboard, res);
        return res;
    }
private:
    //这道题并不是只有唯一解，因此不需要通过返回子问题是否可行来剪枝
    //  bool backtracking(int n,int row,vector<string>& curboard,vector<vector<string>> ){
    
    // }

    void backtracking(int n,int row,vector<string>& curboard,vector<vector<string>>& res ){
        if(row==n){
            res.push_back(curboard);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(curboard,row,col)) {
                curboard[row][col]='Q';
                backtracking(n, row+1, curboard,res);
                curboard[row][col]='.';
            }
        }
    }

    bool isValid(vector<string>& curboard,int row,int col){
        int n=curboard.size();
        for(int i=0;i<row;i++){
            if(curboard[i][col]=='Q') return false;
        }
        for(int i=1;row-i>=0&&col-i>=0;i++){
            if(curboard[row-i][col-i]=='Q') return false;
        }
        for(int i=1;row-i>=0&&col+i<n;i++){
            if(curboard[row-i][col+i]=='Q') return false;
        }
        return true;
    }

};
// @lc code=end

