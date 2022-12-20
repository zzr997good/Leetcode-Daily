/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> adjacents{
        {1,3},
        {0,2,4},
        {1,5},
        {0,4},
        {1,3,5},
        {2,4}
    };
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<string> que;
        unordered_set<string> visited;
        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++)
                start+=(board[i][j]+'0');
        }
        que.push(start);
        visited.insert(start);
        int step=0;
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                string cur=que.front();
                que.pop();
                if(cur=="123450") return step;
                int zero_pos=-1;
                for(zero_pos=0;zero_pos<6;zero_pos++){
                    if(cur[zero_pos]=='0') break;
                }
                for(int i:adjacents[zero_pos]){
                    swap(cur[i],cur[zero_pos]);
                    if(!visited.count(cur)){
                        que.push(cur);
                        visited.insert(cur);
                    }
                    swap(cur[i],cur[zero_pos]);
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

