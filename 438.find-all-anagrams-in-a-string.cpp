// @lc code=start
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> need(26,0);
       vector<int> window(26,0);
       for(char c:p) need[c-'a']++;
       vector<int> res;
       int left=0,right=-1;
       while(++right<s.size()){
            window[s[right]-'a']++;
            if(right-left+1==p.size()){
                if(window==need) res.push_back(left);
                window[s[left]-'a']--;
                left++;
            }
       }
       return res;
    }
};
// @lc code=end

