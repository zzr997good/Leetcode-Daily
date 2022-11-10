/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
        //This is a dummy_MAX in stack
        day=-1;
        increasing_stk.push({INT_MAX,day});
    }
    
    int next(int price) {
        day++;
        while(!increasing_stk.empty()&&increasing_stk.top().first<=price){
            increasing_stk.pop();
        }
        //Since there is no price greater than INT_MAX, the only break condition is top().first>price
        int res=day-increasing_stk.top().second;
        increasing_stk.push({price,day});
        return res;
    }
private:
    stack<pair<int,int>> increasing_stk;
    int day;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

