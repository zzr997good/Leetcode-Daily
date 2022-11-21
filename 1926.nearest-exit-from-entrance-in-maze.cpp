/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<pair<int,int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> que;
        set<pair<int,int>> visiting_visited;
        int m=maze.size();
        int n=maze[0].size();
        int step=0;
        que.push({entrance[0],entrance[1]});
        visiting_visited.insert({entrance[0],entrance[1]});
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                pair<int,int> cur_pos=que.front();
                int x=cur_pos.first;
                int y=cur_pos.second;
                que.pop();
                //Find an exit and it is not the entrance
                if((x!=entrance[0]||y!=entrance[1])&&(x==0||x==m-1||y==0||y==n-1)) return step;
                //Not an exit 
                for(auto direction:directions){
                    int next_x=x+direction.first;
                    if(next_x<0||next_x>=m) continue;
                    int next_y=y+direction.second;
                    if(next_y<0||next_y>=n) continue;
                    if(maze[next_x][next_y]=='.'&&!visiting_visited.count({next_x,next_y})){
                        que.push({next_x,next_y});
                        visiting_visited.insert({next_x,next_y});
                    }
                }
            }
            step++;
        }
        return -1;
    }

};
// @lc code=end

