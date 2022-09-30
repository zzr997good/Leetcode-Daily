/*
 * @lc app=leetcode id=170 lang=cpp
 *
 * [170] Two Sum III - Data structure design
 */

// @lc code=start
#include<unordered_set>
#include<vector>
using namespace std;
class TwoSum {
private:
    unordered_set<int> sums;
    unordered_set<int> nums;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        if(nums.count(number)){
            sums.insert(number*2);
        } 
        else{
            for(int num:nums) sums.insert(num+number);
            nums.insert(number);
        }
    }
    
    bool find(int value) {
        return sums.count(value);
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
// @lc code=end

