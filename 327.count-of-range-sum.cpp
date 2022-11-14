/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int sz=nums.size();
        this->lower=lower;
        this->upper=upper;
        vector<long> preSum(sz+1,0);
        backup=vector<long>(sz+1,0);
        for(int i=1;i<=sz;i++) preSum[i]=preSum[i-1]+nums[i-1];
        int res=MergeSort(preSum,0,sz);
        return res;
    }
private:
    int lower;
    int upper;
    vector<long> backup;
    int MergeSort(vector<long>& preSum,int lo, int hi){
        if(lo==hi) return 0;
        int mid=lo+(hi-lo)/2;
        return MergeSort(preSum, lo, mid)+MergeSort(preSum,mid+1,hi)+Merge(preSum,lo,mid,hi);
    }
    int Merge(vector<long>& preSum,int lo,int mid,int hi){
        for(int i=lo;i<=hi;i++) backup[i]=preSum[i];
        int start=mid+1;
        int end=mid+1;
        int res=0;
        for(int i=lo;i<mid+1;i++){
            //对于左半sorted区间的每一个数字需要在右半区间找到第一个preSum[start]-preSum[i]>=lower
            //对于左半sorted区间的每一个数字需要在右半区间找到第一个preSum[end]-preSum[i]>upper
            //对半搜索(但是不会影响整体Merge的时间复杂度，因为Merge受到后面合并操作的影响必然O(n))
            int left=start;
            int right=hi+1;
            while(left<right){
                int mmid=left+(right-left)/2;
                if(preSum[mmid]<preSum[i]+lower) left=mmid+1;
                else if(preSum[mmid]>preSum[i]+lower) right=mmid;
                else right=mmid;
            }
            start=left;
            left=end;
            right=hi+1;
            while(left<right){
                int mmid=left+(right-left)/2;
                if(preSum[mmid]<preSum[i]+upper) left=mmid+1;
                else if(preSum[mmid]>preSum[i]+upper) right=mmid;
                else left=mmid+1;
            }
            end=left;
            res+=end-start;
        }
        //开始合并两个区间
        int i=lo;
        int j=mid+1;
        for(int pos=lo;pos<=hi;pos++){
            if(i==mid+1) preSum[pos]=backup[j++];
            else if(j==hi+1) preSum[pos]=backup[i++];
            else if(backup[i]<backup[j]) preSum[pos]=backup[i++];
            else preSum[pos]=backup[j++];
        }
        return res;
    }

};
// @lc code=end

