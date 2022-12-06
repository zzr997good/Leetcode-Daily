/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> map{"#","#","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string cur="";
        vector<string> res;
        backtrack(digits,0,map,cur,res);
        return res;
    }

private:
    void backtrack(const string& digits, int pos,const vector<string>& map,string& cur,vector<string>& res){
        char num_c=digits[pos];
        string choices=map[num_c-'0'];
        for(char c:choices){
            cur.push_back(c);
            if(cur.size()==digits.size()){
                res.push_back(cur);
                cur.pop_back();
            }
            else{
                backtrack(digits, pos+1, map, cur, res);
                cur.pop_back();
            }

        }
    }
};
// @lc code=end

