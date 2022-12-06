/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> min_effort_from_start(m,vector<int>(n,INT_MAX));
        min_effort_from_start[0][0]=0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto cur_min=pq.top();
            pq.pop();
            int min_effort=cur_min.first;
            pair<int,int> min_pos=cur_min.second;
            if(min_effort>min_effort_from_start[min_pos.first][min_pos.second]) continue;
            if(min_pos.first==m-1&&min_pos.second==n-1) return min_effort;
            for(pair<int,int>& adj:getAdj(min_pos,m,n)){
                //This is the "weight" between two node
                int abs_diff=abs(heights[min_pos.first][min_pos.second]-heights[adj.first][adj.second]);
                //After relaxation, the effort of adj node >= global minium effort of cur node
                int effort_after_relaxation=max(min_effort,abs_diff);
                //But it coule be less than the effort of adj node in other path
                if(effort_after_relaxation<min_effort_from_start[adj.first][adj.second]){
                    min_effort_from_start[adj.first][adj.second]=effort_after_relaxation;
                    pq.push({effort_after_relaxation,adj});
                }
            }
        }
        return 0;
    }

private:
    vector<pair<int,int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    vector<pair<int,int>> getAdj(pair<int,int>& pos,int m,int n){
        int x=pos.first;
        int y=pos.second;
        vector<pair<int,int>> adjpos;
        for(const pair<int,int>& direction:directions){
            int adj_x=x+direction.first;
            int adj_y=y+direction.second;
            if(adj_x<0||adj_x>=m||adj_y<0||adj_y>=n) continue;
            adjpos.push_back({adj_x,adj_y});
        }
        return adjpos;

    }
};
// @lc code=end

