/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        set<pair<int,int>> corner;
        int X1=INT_MAX;
        int Y1=INT_MAX;
        int X2=INT_MIN;
        int Y2=INT_MIN;
        long long sum_area=0;
        for(vector<int>& rectangle:rectangles){
            //求拼凑图形的面积
            long long len=rectangle[2]-rectangle[0];
            long long ht=rectangle[3]-rectangle[1];
            sum_area+=len*ht;
            //更新完美矩形的理论顶点
            X1=min(X1,rectangle[0]);
            Y1=min(Y1,rectangle[1]);
            X2=max(X2,rectangle[2]);
            Y2=max(Y2,rectangle[3]);
            //更新拼凑图形的顶点
            for(int i=0;i<4;i+=2){
                for(int j=1;j<4;j+=2){
                    if(corner.count({rectangle[i],rectangle[j]}))
                        corner.erase({rectangle[i],rectangle[j]});
                    else
                        corner.insert({rectangle[i],rectangle[j]});
                    
                }
            }
        }
        long long idea_area=(long long)(X2-X1)*(long long)(Y2-Y1);
        if(corner.size()!=4) return false;
        if(!corner.count({X1,Y1})||!corner.count({X1,Y2})||!corner.count({X2,Y1})||!corner.count({X2,Y2})) return false;
        if(idea_area!=sum_area) return false;
        return true;
    }
};
// @lc code=end

