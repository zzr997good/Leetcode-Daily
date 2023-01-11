/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 */

// @lc code=start
class Solution {
public:
    //假设n=10，黑名单有2，4，8，那么不在黑名单中的数字就一共有7个
    //所有的数字已经按照顺序排好了
    //我们只在前7个数字中抽取随机数，如果那个数字是黑名单中的数字，那么这就意味着后三个数字中必然有一个数字不是黑名单中的数字，我们把那个黑名单数映射到后三个数字中不是黑名单的那个数
    //例：如果在前七个数字中抽到了2，那么我们应该抽取他映射后的那个数字9，如果抽到了4，我们应该应该抽取7(因为8也是黑名单数，不能把4映射到8)
    Solution(int n, vector<int>& blacklist) {
        sz=n-blacklist.size();
        for(int black:blacklist){
            //这一步是为了确定哪些数字是黑名单数
            //如果不先映射一次的话，就要去blacklist里面找，复杂度为O(N)
            black_to_white[black]=-1;
        }
        //对前sz个数中的黑名单数进行remap
        int last=n-1;
        for(int black:blacklist){
            if(black<sz){
                //映射后的数依旧是黑名单数，那么就往前继续找可以被映射后变成的白名单数，肯定存在，因为黑名单数字的个数固定，在前sz个数中出现黑名单数，那么就会在n-sz的其他数字中出现白名单数
                while(black_to_white.count(last)) last--;
                black_to_white[black]=last;
                last--;
            }
        }
    }
    
    int pick() {
        int r=rand()%sz;
        //抽到了一个黑名单数，转而去抽他remap之后的白名单数
        if(black_to_white.count(r)) return black_to_white[r];
        //抽到的就是白名单数
        else return r;
    }
private:
    int sz;
    unordered_map<int,int> black_to_white;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

