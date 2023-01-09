/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int total=0;
       for(int i:gas) total+=i;
       //There is no solution
       for(int i:cost) {
           total-=i;
           if(total<0) return -1;
       } 
       //There must be a solution
       int start=0;
       int tank=0;
       for(int i=0;i<gas.size();i++){
           tank+=gas[i]-cost[i];
           if(tank<0){
               tank=0;
               start=i+1;
           }
       }
       if(start==gas.size()) return 0;
       else return start;
    }
};
// @lc code=end

