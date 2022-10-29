/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

// @lc code=start
class Solution {
public:
    static bool less(const vector<int>& interval1, const vector<int>& interval2){
        return interval1[0]==interval2[0]?interval1[1]>interval2[1]:interval1[0]<interval2[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end(),less);
        int sz=clips.size();
        int left=0,right=0;
        int res=0;
        for(int i=0;i<sz;){
            //对于每一个clip而言，[left,right]表示之前所有clip能合成的最大区间
            //存在时间空隙
            if(clips[i][0]>right) return -1;
            //不存在时间空隙，需要找到从i开始所有起点小于等于right的clip的最大延伸范围
            int most_extend=right;
            while(i<sz&&clips[i][0]<=right){
                most_extend=max(most_extend,clips[i][1]);
                i++;
            }
            //如果right被延长了,说明融合了一个新的clip,更新[left,right]
            if(most_extend>right) {
                right=most_extend;
                res++;
                //如果已经超过time范围了，直接返回结果
                if(right>=time) return res;
            }
        }
        //
        return right==time?res:-1;
    }
};
// @lc code=end

