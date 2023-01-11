/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>> sorted_tasks;
        for(int i=0;i<tasks.size();i++){
            sorted_tasks.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(sorted_tasks.begin(),sorted_tasks.end(),cmp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available_tasks; 
        vector<int> res;
        long end_time=0;
        int new_task=0;
        while(res.size()<sorted_tasks.size()){
            //如果在当前end_time时刻没有可以处理的task并且也没有新的task可以入队
            if(available_tasks.empty()&&end_time<sorted_tasks[new_task][0]){
                end_time=sorted_tasks[new_task][0];
            }
            //如果有可以添加的新的task
            while(new_task<sorted_tasks.size()&&end_time>=sorted_tasks[new_task][0]){
                available_tasks.push({sorted_tasks[new_task][1],sorted_tasks[new_task][2]});
                new_task++;
            }
            pair<int,int> next_tast=available_tasks.top();
            available_tasks.pop();
            res.push_back(next_tast.second);
            end_time+=next_tast.first;
        }
        return res;

    }

    //依旧是按照起点排序，这次相同起点情况下，需要时间短的，也就是终点小的，排前面
    static bool cmp(vector<int>& task_x,vector<int>& task_y){
        return task_x[0]<task_y[0];
    }
};
// @lc code=end

