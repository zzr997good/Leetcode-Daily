/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
//Two queue implementation
// //Two queue implementation
// class MyStack {
// public:
//     MyStack() {
        
//     }
    
//     void push(int x) {
//         //always make x the top element in the queue
//         second.push(x);
//         while(!first.empty()){
//             second.push(first.front());
//             first.pop();
//         }
//         swap(first,second);
//     }
    
//     int pop() {
//         int x=first.front();
//         first.pop();
//         return x;
//     }
    
//     int top() {
//         return first.front();
//     }
    
//     bool empty() {
//         return first.empty();
//     }
// private:
//     queue<int> first;
//     queue<int> second;
// };

//Single queue implementation
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        //always make x the top element in the queue
        que.push(x);
        int sz=que.size();
        for(int i=0;i<sz-1;i++){
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int x=que.front();
        que.pop();
        return x;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

