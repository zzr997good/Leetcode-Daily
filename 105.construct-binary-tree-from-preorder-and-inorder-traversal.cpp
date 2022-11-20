/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder,int lo1,int hi1,vector<int>&inorder, int lo2,int hi2){
        if(lo1>hi1) return nullptr;
        int root_val=preorder[lo1];
        int pos=-1;
        for(pos=lo2;pos<=hi2;pos++){
            if(inorder[pos]==root_val)
            break;
        }
        int left_sz=pos-lo2;
        int right_sz=hi2-pos;
        TreeNode* root=new TreeNode(root_val);
        root->left=buildTree(preorder, lo1+1, lo1+left_sz, inorder, lo2, pos-1);
        root->right=buildTree(preorder, lo1+left_sz+1, hi1, inorder, pos+1, hi2);
        return root;
    }
};
// @lc code=end

