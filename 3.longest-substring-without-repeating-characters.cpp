/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // unordered_set<char> substring;
        // int left = 0, right = -1;
        // int res = 0;
        // //Try to enlarge the window size
        // while ((++right) < s.size())
        // {
        //     //If enlarge, repeating characters exists
        //     //Shink the window
        //     while (substring.count(s[right]))
        //     {
        //         substring.erase(s[left]);
        //         left++;
        //     }
        //     //There is no repeating characters any more
        //     //Enlarge the window size
        //     substring.insert(s[right]);
        //     //Update the res
        //     res = max(res, right - left + 1);
        // }
        // return res;

        //Use hashmap char->index to accelerate
        unordered_map<char, int> substring;
        int res = 0;
        int left = 0, right = -1;
        while (++right < s.size())
        {
            if (substring.count(s[right]) && substring[s[right]] != -1)
            {
                int new_left = substring[s[right]] + 1;
                for (int i = left; i < new_left; i++)
                    substring[s[i]] = -1;
                left = new_left;
            }
            substring[s[right]] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end
