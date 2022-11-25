/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        cur_stk.push(nestedList.begin());
        end_stk.push(nestedList.end());
    }
    
    int next() {
        int num=cur_stk.top()->getInteger();
        cur_stk.top()++;
        return num;
    }
    
    bool hasNext() {
        while(!cur_stk.empty()&&!end_stk.empty()){
            if(cur_stk.top()==end_stk.top()){
                cur_stk.pop();
                end_stk.pop();
                continue;
            }
            if(cur_stk.top()->isInteger()){
                return true;
            }
            else{
                auto cur_list=cur_stk.top();
                cur_stk.top()++;
                cur_stk.push(cur_list->getList().begin());
                end_stk.push(cur_list->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> cur_stk;
    stack<vector<NestedInteger>::iterator> end_stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

