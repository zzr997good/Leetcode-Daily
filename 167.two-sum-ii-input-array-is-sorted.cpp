/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo=0;
        int hi=numbers.size()-1;
        while(lo<hi){
            int sum=numbers[lo]+numbers[hi];
            if(sum==target) return {lo+1,hi+1};
            else if(sum>target){
                int right=numbers[hi];
                while(lo<hi&&numbers[hi]==right) hi--;
            }
            else{
                int left=numbers[lo];
                while(lo<hi&&numbers[lo]==left) lo++;
            }
        }
        return {};
    }
};
// @lc code=end

