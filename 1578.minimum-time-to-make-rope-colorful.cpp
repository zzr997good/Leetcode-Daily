/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int all_sum=0; //全部保留需要的时间
        int needed_sum=0;
        int left=0;   
        while(left<n){
            int right=left;
            int needed=0; //相同颜色里面留下的必然是需要最长时间的
            while(right<n){
                if(colors[right]==colors[left]){
                    needed=max(needed,neededTime[right]);
                    all_sum+=neededTime[right];
                    right++;
                }
                else break;
            }
            needed_sum+=needed;
            left=right;
        }
        return all_sum-needed_sum;
    }
};
// @lc code=end

