/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
    MedianFinder() {
        st.insert(INT_MIN);
        st.insert(INT_MAX);
        first_half=st.begin();
        second_half=(--st.end());
    }
    
    void addNum(int num) {
        int sz=st.size();
        st.insert(num);
        //之前是偶数
        if(!(sz&1)){
            if(num>=*second_half) first_half++;
            else if(num<*first_half) second_half--;
            else {
                first_half++;
                second_half--;
            }
        }
        //之前是奇数
        else{
           if(num>=*second_half) second_half++;
           else first_half--;
        }
    }
    
    double findMedian() {
        double res=(*first_half)+(*second_half);
        return res/2;
    }
private:
    multiset<int> st;
    multiset<int>::iterator first_half;
    multiset<int>::iterator second_half;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

