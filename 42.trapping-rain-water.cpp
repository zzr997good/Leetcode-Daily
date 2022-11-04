/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        //每个凹槽能够接的雨水有两种算法
        //算法1:单独看每个柱子能够容纳的雨水量，然后累加起来
        //算法2:单独看每个横条能够容纳的雨水量，然后累加起来
/*——————————————————————————————————————————————————————————————————————————*/
/*——————————————————————————————————————————————————————————————————————————*/
        //算法1:对于每个柱子，需要的信息有，该柱子左侧柱子最高值left_max，该柱子右侧最高值right_max，然后该柱子能够容纳的雨水量就是min(left_max,right_max)-height[i],同时还要注意计算出来的值是不是大于等于0，如果小于0的话说明该柱子比min(left_max,right_max)高，是无法接住雨水的

        //Way1: 先求得left_max数组和right_max数组，然后遍历数组求每个柱子雨水量然后求和
        // int sz=height.size();
        // vector<int> left_max(sz,0);
        // vector<int> right_max(sz,0);
        // int sum=0;
        // for(int i=1;i<sz;i++) left_max[i]=max(left_max[i-1],height[i-1]);
        // for(int i=sz-2;i>=0;i--) right_max[i]=max(right_max[i+1],height[i+1]);
        // for(int i=1;i<sz-1;i++) sum+=max(0,min(left_max[i],right_max[i])-height[i]);
        // return sum;
        // //Way1变体: left_max数组和right_max数组是包括i自己的左侧最大高度和右侧最大高度，这样就不需要把结果和0比较了
        // int sz=height.size();
        // vector<int> left_max(sz,0);
        // vector<int> right_max(sz,0);
        // int sum=0;
        // left_max[0]=height[0];
        // for(int i=1;i<sz;i++) left_max[i]=max(left_max[i-1],height[i]);
        // right_max[sz-1]=height[sz-1];
        // for(int i=sz-2;i>=0;i--) right_max[i]=max(right_max[i+1],height[i]);
        // for(int i=0;i<sz;i++) sum+=min(left_max[i],right_max[i])-height[i];
        // return sum;
/*——————————————————————————————————————————————————————————————————————————*/
        //Way2:双指针，因为left_max数组从左到右必然单调非减，right_max数组从右到左必然单调非减，因此整个数组中必然有一个点是left_max[i]=right_max[i]=height[i]，这个点左边所有的点min(right_max,left_max)==left_max，这个点右边所有的点min(right_max,left_max)==right_max,因此用左右指针分别从两端向中间遍历数组，左指针指向元素的left_max是已知的，右侧指针指向元素的right_max是已知的。
        //(a)当height[left]>left_max时，更新left_max=height[left];当height[right]>right_max时，更新right_max=height[right]
        //(b.1)当left_max<right_max时，可以确定的是left指向的柱子必然可以接雨水，因为height[left]<=left_max<right_max<right_max[left],能够接的雨水量为left_max-height[left],然后left++；
        //(b.2)当left_max>=right_max时，可以确定的是right指向的柱子必然可以接雨水，因为height[right]<=right_max<=left_max<=left_max[right],能够接的雨水量为right_max-height[right],然后right++；
            // int left=0,right=height.size()-1;
            // int left_max=0,right_max=0;
            // int sum=0;
            // while(left<right){
            //     if(height[left]>left_max) left_max=height[left];
            //     if(height[right]>right_max) right_max=height[right];
            //     if(left_max<right_max) {
            //         sum+=left_max-height[left];
            //         left++;
            //     }
            //     else{
            //         sum+=right_max-height[right];
            //         right--;
            //     }
            // }
            // return sum;

        // //Way2变体：left_max不包括left指向的柱子,right_max不包括right指向的柱子
        //     int left=0,right=height.size()-1;
        //     int left_max=0,right_max=0;
        //     int sum=0;
        //     while(left<=right){
        //         //比左侧所有柱子都高，不可能盛水
        //         if(height[left]>=left_max) {
        //             left_max=height[left];
        //             left++;
        //             continue;
        //         }
        //         //比右侧所有柱子都高，不可能盛水
        //         if(height[right]>=right_max) {
        //             right_max=height[right];
        //             right--;
        //             continue;
        //         }
        //         if(left_max<right_max) {
        //             sum+=left_max-height[left];
        //             left++;
        //         }
        //         else{
        //             sum+=right_max-height[right];
        //             right--;
        //         }
        //     }
        //     return sum;

/*——————————————————————————————————————————————————————————————————————————*/
/*——————————————————————————————————————————————————————————————————————————*/
        //算法2:从左向右遍历，同时维护一个单调递增栈。当一个柱子入栈的时候，如果前面的柱子高度大于等于它，那么它就有可能用来储水，正常入栈。当前面的柱子高度比他小，那么他就从右侧拦住的栈顶的柱子，此时栈顶柱子a左侧被栈顶下一个柱子b拦住，此时根据即将入栈的柱子高度和b的高度就能计算出一个横向水平面的水量，以此累加
        stack<int> monostack;
        int sum=0;
        for(int i=0;i<height.size();i++){
            while(!monostack.empty()&&height[monostack.top()]<height[i]){
                int top_index=monostack.top();
                monostack.pop();
                if(!monostack.empty()){
                    int left_index=monostack.top();
                    int water_level=min(height[i],height[left_index]);
                    int width=i-left_index-1;
                    sum+=width*(water_level-height[top_index]);
                }
            }
            monostack.push(i);
        }
        return sum;
    }
};
// @lc code=end

