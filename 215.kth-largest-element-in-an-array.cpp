/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz=nums.size();
        RandomQuickSort(nums,0,sz-1,k);
        return nums[k-1];
    }
private:
    // //Common QuickSort O(nlogn) worst case O(n^2)
    // void quickSort(vector<int>&nums, int lo,int hi,int k){
    //     if(lo>=hi) return;
    //     int pivot=nums[lo];
    //     int l=lo+1,r=hi;
    //     while(l<=r){
    //         if(nums[l]<pivot&&nums[r]>pivot){
    //             swap(nums[l],nums[r]);
    //             l++;
    //             r--;
    //         }
    //         if(nums[l]>=pivot) l++;
    //         if(nums[r]<=pivot) r--;
    //     }
    //     swap(nums[r],nums[lo]);
    //     if(r==k-1) return;
    //     if(r<k-1) quickSort(nums,r+1,hi,k);
    //     else quickSort(nums,lo,r-1,k);
    // }

    //Random Quick Sort O(nlogn)
    void RandomQuickSort(vector<int>&nums, int lo,int hi, int k){
        if(lo>=hi) return;
        int random_pivot=lo+rand()%(hi-lo+1);
        swap(nums[lo],nums[random_pivot]);
        int pivot=nums[lo];
        int l=lo+1,r=hi;
        while(l<=r){
            if(nums[l]<pivot&&nums[r]>pivot){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            if(nums[l]>=pivot) l++;
            if(nums[r]<=pivot) r--;
        }
        swap(nums[lo],nums[r]);
        if(r==k-1) return;
        else if(r<k-1) RandomQuickSort(nums,r+1,hi,k);
        else RandomQuickSort(nums, lo, r-1, k);
    }
};
// @lc code=end

