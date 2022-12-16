/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> que;
        unordered_set<string> visited(deadends.begin(),deadends.end());
        int step=0;
        if(!visited.count("0000")) {
            que.push("0000");
            visited.insert("0000");
        }
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                string cur=que.front();
                que.pop();
                if(cur==target) return step;
                for(int i=0;i<4;i++){
                    string up=rotate_up(cur, i);
                    string down=rotate_down(cur, i);
                    if(!visited.count(up)) {
                        que.push(up);
                        visited.insert(up);
                    }
                    if(!visited.count(down)) {
                        que.push(down);
                        visited.insert(down);
                    }
                }

            }
            step++;
        }
        return -1;
    }

private:
    string rotate_up(string str,int pos){
        if(str[pos]=='9') str[pos]='0';
        else str[pos]++;
        return str;
    }

    string rotate_down(string str,int pos){
        if(str[pos]=='0') str[pos]='9';
        else str[pos]--;
        return str;
    }
};
// @lc code=end

