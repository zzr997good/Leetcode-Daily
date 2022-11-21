/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         vector<vector<int>> max_dp(nums.size(),vector<int>(nums.size(),-1));
//         for(int i=0;i<nums.size();i++) max_dp[i][i]=i;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 int last_max=nums[max_dp[i][j-1]];
//                 max_dp[i][j]=(last_max>nums[j]?max_dp[i][j-1]:j);
//             }
//         }
//         return buildTree(nums,0,nums.size()-1,max_dp);
//     }
// private:
//     TreeNode* buildTree(vector<int>&nums,int lo,int hi,vector<vector<int>>& max_dp){
//         if(lo>hi) return nullptr;
//         int index=max_dp[lo][hi];
//         TreeNode* root=new TreeNode(nums[index]);
//         root->left=buildTree(nums,lo,index-1,max_dp);
//         root->right=buildTree(nums, index+1, hi, max_dp);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //Monotonically increasing stack/queue
        deque<TreeNode*> que;
        for(int num:nums){
            TreeNode* cur=new TreeNode(num);
            while(!que.empty()&&que.back()->val<num){
                cur->left=que.back();
                que.pop_back();
            }
            if(!que.empty()) que.back()->right=cur;
            que.push_back(cur);
        }
        return que.front();
        
    }
};
// @lc code=end

