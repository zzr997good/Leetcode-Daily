/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        //想要nums1对nums2的优势最大，就需要对nums1的每个数字充分利用，不能浪费
        //原则1:对于nums1当前的最小元素，如果他能击败nums2当前最小元素，就必须匹配，因为这样，nums1留下的其他元素会更大，更有可能击败nums2中的大元素
        //原则2:对于nums1当前的最小元素，如果它不能击败nums2当前最小元素，那它就不可能击败任何nums2剩下的其他元素，它唯一的作用就是拉着nums2剩下的最大元素自爆.
        vector<pair<int,int>> nums2_with_index;
        for(int i=0;i<nums2.size();i++) nums2_with_index.push_back({nums2[i],i});
        sort(nums2_with_index.begin(),nums2_with_index.end(),up);
        sort(nums1.begin(),nums1.end());
        vector<int> res(nums1.size());
        int ptr1=0,ptr2=0;
        int last=nums2.size();
        while(ptr1<nums1.size()&&ptr2<nums2.size()){
            if(nums1[ptr1]<=nums2_with_index[ptr2].first) { 
                //自爆
                last--;
                int index=nums2_with_index[last].second;
                res[index]=nums1[ptr1];
                ptr1++;
            }
            else {
                //击败
                int index=nums2_with_index[ptr2].second;
                res[index]=nums1[ptr1];
                ptr2++;
                ptr1++;
            }
        }
        return res;

    }
private:
    static bool up(const pair<int,int>& x, const pair<int,int>& y){
        return x.first==y.first?x.second<y.second:x.first<y.first;
    }
};
// @lc code=end

