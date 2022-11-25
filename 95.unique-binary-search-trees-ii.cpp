/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1,n);
    }

    vector<TreeNode*> build(int start,int end){
        if(start>end) return {nullptr};
        vector<TreeNode*> res;
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=build(start,i-1);
            vector<TreeNode*> right=build(i+1,end);
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

