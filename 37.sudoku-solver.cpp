/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board,0,0);
        return;
    }
private:
    //也可以用 void backtracking,只要在row==9的时候把board添加到res里面就行
    //在做出每个选择的时候只要负责把那个字符填进去，然后做下一个选择，如果得到可行解会自动添加到res中
    //如果没有可行解那么最终res会是空集，而board也会和原来一样
    //但是由于这道题的返回值是void soloveSudoku，所以这道题没有办法返回res，并且只有唯一解
    //就不得不用一个bool来获得信息：当前填入字符后，进行接下来的选择能不能得到解
    //当然也可以二者结合起来用
    bool backtracking(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;
        int next_pos_row;
        int next_pos_col;
        if(col<8){
            next_pos_row=row;
            next_pos_col=col+1;
        }
        else{
            next_pos_row=row+1;
            next_pos_col=0;
        }
        if(board[row][col]!='.') {
            return backtracking(board, next_pos_row, next_pos_col);
        }
        else{
            for(char c='1';c<='9';c++){
                if(isValid(board,row,col,c)){
                    board[row][col]=c;
                    //Get the answer
                    if(backtracking(board,next_pos_row,next_pos_col)) return true;
                    //Cant not fill in char c
                    board[row][col]='.';
                }
            }
            //None of '1'-'9' can be filled in this position
            return false;
        }
    }

    bool isValid(vector<vector<char>>&board,int row,int col,char c){
        //row test
        for(int i=0;i<9;i++) if(board[row][i]==c) return false;
        //col test
        for(int i=0;i<9;i++) if(board[i][col]==c) return false;
        //sub-box test
        int row_block=row/3;
        int col_block=col/3;
        for(int i=row_block*3;i<row_block*3+3;i++){
            for(int j=col_block*3;j<col_block*3+3;j++){
                if(board[i][j]==c) return false;
            }
        }
        return true;
    }
};
// @lc code=end

