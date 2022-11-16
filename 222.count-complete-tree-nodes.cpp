/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int depth=getDepth(root);
        int left=0,right=(1<<depth)-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isExist(root,depth,mid)) left=mid+1;
            else right=mid-1;
        }
        return (1<<depth)-1+(right-0+1);
    }
private:
    int getDepth(TreeNode* root){
        TreeNode* cur=root;
        int depth=-1;
        while(cur){
            depth++;
            cur=cur->left;
        }
        return depth;
    }

    int isExist(TreeNode* root, int depth, int index){
        TreeNode* cur=root;
        int left=0,right=(1<<depth)-1;
        for(int i=0;i<depth;i++){
            int mid=left+(right-left)/2;
            if(index<=mid){
                cur=cur->left;
                right=mid;
            }
            else{
                cur=cur->right;
                left=mid+1;
            }
        }
        return !(cur==nullptr);
    }
};
// @lc code=end

