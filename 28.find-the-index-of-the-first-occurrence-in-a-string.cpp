/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string t, string p) {
        int q=0;
        int m=p.size();
        vector<int> π=policy(p);
        for(int i=0;i<t.size();i++){
            while(q>0&&t[i]!=p[q])
                q=π[q];
            //最终匹配上了 q++，i++
            if(t[i]==p[q]) q++; 
            // else 没匹配上 只要i++
            if(q==m) return i-m+1;
        }
        return -1;
    }
private:
    vector<int> policy(string p){
        int sz=p.size();
        vector<int> π(sz+1);
        π[0]=0;
        π[1]=0;
        int k=0;
        for(int i=2;i<=sz;i++){
            //π[i-1]==k，接下来比较第i个字符和第k+1个字符
            while(k>0&&p[i-1]!=p[k])
                k=π[k];
            if(p[i-1]==p[k]) π[i]=++k; //匹配上了
            else π[i]=0; //k==0并且没匹配上
        }
        return π;
    }
};
// @lc code=end

