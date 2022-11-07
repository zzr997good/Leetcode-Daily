/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
    int maximum69Number (int num) {
        // //way1: O(m)+O(m)
        // string str_num=to_string(num);
        // for(int i=0;i<str_num.size();i++){
        //     if(str_num[i]=='6'){
        //         str_num[i]='9';
        //         break;
        //     } 
        // }
        // return stoi(str_num);

        //way2: O(m)+O(1)
        int temp=num;
        int count=0;
        int offset=-1;
        while(temp>0){
            int digit=temp%10;
            temp/=10;
            if(digit==6) offset=count;
            count++;
        }
        if(offset==-1) return num;
        else return (num+3*pow(10,offset));
    }
};
// @lc code=end

