/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string,vector<int>> mp;
        return dp(expression,mp);
    }
private:
    vector<int> dp(const string& expression, unordered_map<string,vector<int>>mp){
        if(mp.count(expression)) return mp[expression];
        vector<int> res;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
                string left=expression.substr(0,i);
                string right=expression.substr(i+1);
                vector<int> left_res=dp(left,mp);
                vector<int> right_res=dp(right,mp);
                switch(expression[i]){
                    case '+':
                        for(int num1:left_res)
                            for(int num2:right_res)
                                res.push_back(num1+num2);
                        break;
                    case '-':
                        for(int num1:left_res)
                            for(int num2:right_res)
                                res.push_back(num1-num2);
                        break;
                    case '*':
                        for(int num1:left_res)
                            for(int num2:right_res)
                                res.push_back(num1*num2);
                        break;
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        mp[expression]=res;
        return mp[expression];
    }
};
// @lc code=end

