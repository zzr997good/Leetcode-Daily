/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        bool hasOverLap=checkOverLap(ax1, ax2, bx1, bx2)&&checkOverLap(ay1, ay2, by1, by2);
        int overlap_area=0;
        if(hasOverLap){
            int len=min(ax2,bx2)-max(ax1,bx1);
            int height=min(ay2,by2)-max(ay1,by1);
            overlap_area=len*height;
        }
        return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-overlap_area;
    }
bool checkOverLap(int start1,int end1,int start2,int end2){
        int start=max(start1,start2);
        int end=min(end1,end2);
        return start<end;
    }
};
// @lc code=end

