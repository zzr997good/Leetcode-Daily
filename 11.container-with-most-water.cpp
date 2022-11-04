/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        int left=0,right=height.size()-1;
        while(left<right){
            maxarea=max(maxarea,(right-left)*min(height[left],height[right]));
            //假设高的交long_h,矮的叫short_h
            //移动long_h只会导致面积越来越小，如果新的long_h'>short_h，宽仍然是short_h，长在缩小，面积变小
            //如果long_h'<short_h,宽是long_h'，更小了，并且长在缩小，面积变小
            //移动short_h可能导致面积变大，如果新的short_h'>short_h，宽是min(short_h',long_h)，长在缩小,面积有可能变大
            //如果新的short_h'<short_h，宽是short_h'，长在缩小,面积变小
            if(height[left]<height[right]){
                int left_val=height[left];
                while(left<right&&height[left]<=left_val) left++;
            }
            else{
                int right_val=height[right];
                while(left<right&&height[right]<=right_val) right--;
            }
        }
        return maxarea;
    }
};
// @lc code=end

