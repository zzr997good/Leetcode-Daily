/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */
#include<vector>
#include<deque>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQue que;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(i<k) que.push(nums[i]);
            else{
                if(que.front()==nums[i-k]) que.pop();
                que.push(nums[i]);
            }
            if(i>=k-1) res.push_back(que.front());

        }
        return res;
    }
private:
    //单调递增队列
    class MonotonicQue{
        private:
            deque<int> que;
        public:
            void pop(){
                if(!que.empty()) que.pop_front();
            }

            void push(int num){
                while(!que.empty()&&que.back()<num) que.pop_back();
                que.push_back(num);
            }

            int front(){
                return que.front();
            }
    };
};
// @lc code=end

