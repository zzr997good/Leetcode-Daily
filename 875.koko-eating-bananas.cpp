/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */
#include<vector>

// @lc code=start
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int sz=piles.size();
        sort(piles.begin(),piles.end());
        int lo_speed=1,hi_speed=piles[sz-1];
        while(lo_speed<hi_speed){
            int mid_speed=lo_speed+(hi_speed-lo_speed)/2;
            if(TimeOfEatingAll(piles,mid_speed)<h) hi_speed=mid_speed;
            else if(TimeOfEatingAll(piles,mid_speed)>h) lo_speed=mid_speed+1;
            else hi_speed=mid_speed;
        }
        return lo_speed;
    }
private:
    //Given piles and speed, calculate the total time needed for koko to eat all piles
    int TimeOfEatingAll(std::vector<int>&piles, int speed){
        int hour=0;
        for(auto& pile:piles){
            hour+=((pile+speed-1)/speed);
        }
        return hour;
    }
};
// @lc code=end

