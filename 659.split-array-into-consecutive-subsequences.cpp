/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> need;
        for(int num:nums) freq[num]++;
        for(int num:nums){
            //明明有这个数，但是出现频率却为0，说明在这个数已经被用完了
            if(freq[num]==0) continue;
            else if(need.count(num)&&need[num]>0){
                    freq[num]--;
                    need[num]--;
                    need[num+1]++;
            }
            else if(freq[num+1]>0&&freq[num+2]>0){
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                need[num+3]++;
            }
            else return false;
        }
        return true;
    }
};
// @lc code=end

