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
        curs.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    
    int next() {
        int nextint=curs.top()->getInteger();
        curs.top()++;
        return nextint;
    }
    
    bool hasNext() {
        while(!curs.empty()&&!ends.empty()){
            if(curs.top()==ends.top()){
                curs.pop();
                ends.pop();
                continue;
            }
            else if(curs.top()->isInteger()) return true;
            else {
                auto new_nestedlist=curs.top();
                curs.top()++;
                curs.push(new_nestedlist->getList().begin());
                ends.push(new_nestedlist->getList().end());
            }
        }
        return false;
    }
private:
    stack<vector<NestedInteger>::iterator> curs;
    stack<vector<NestedInteger>::iterator> ends;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

