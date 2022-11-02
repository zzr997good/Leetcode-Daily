/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo_capacity=0,hi_capacity=25000000;
        for(auto& weight:weights) lo_capacity=max(lo_capacity,weight);
        while(lo_capacity<hi_capacity){
            int mid_capacity=lo_capacity+(hi_capacity-lo_capacity)/2;
            if(DaysGivenCapacity(weights,mid_capacity)<days) hi_capacity=mid_capacity;
            else if(DaysGivenCapacity(weights,mid_capacity)>days) lo_capacity=mid_capacity+1;
            else  hi_capacity=mid_capacity;
        }
        return lo_capacity;
    }
private:
    int DaysGivenCapacity(vector<int>&weights,int capacity){
        int days=0;
        int load=0;
        int i=0;
        while(i<weights.size()){
            if(load+weights[i]>capacity){
                days++;
                load=0;
            }
            else{
                load+=weights[i];
                i++;
            }
        }
        days++;
        return days;
    }
};
// @lc code=end

