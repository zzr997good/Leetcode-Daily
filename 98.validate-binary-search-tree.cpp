/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
 
//  //Recursive way
// class Solution {
// public:
//     //一边判断是否BST，一边记录最大最小值
//     bool isValidBST(TreeNode* root) {
//         if(root==nullptr) return true;
//         bool left=isValidBST(root->left);
//         if(!left) return false;
//         int left_max;
//         int left_min;
//         if(root->left!=nullptr) {
//             left_max=max;
//             left_min=min;
//             if(left_max>=root->val) return false;
//         }
//         else{
//             left_max=root->val;
//             left_min=root->val;
//         }
//         bool right=isValidBST(root->right);
//         if(!right) return false;
//         int right_max;
//         int right_min;
//         if(root->right!=nullptr){
//             right_max=max;
//             right_min=min;
//             if(right_min<=root->val) return false;
//         }
//         else{
//             right_max=root->val;
//             right_min=root->val;
//         }
//         max=right_max;
//         min=left_min;
//         return true;
//     }
// private:
//     int max;
//     int min;
//};

//中序遍历是单调递增数组    
class Solution{
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        if(!isValidBST(root->left)) return false;
        if(prev&&prev->val>=root->val) return false;
        prev=root;
        return isValidBST(root->right);
    }
private:
    TreeNode* prev=nullptr;
};
// @lc code=end

