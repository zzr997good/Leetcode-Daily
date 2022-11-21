/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder, int lo1,int hi1, vector<int>& postorder,int lo2,int hi2){
        if(lo1>hi1) return nullptr;
        int root_val=postorder[hi2];
        int pos=-1;
        for(pos=lo1;pos<=hi1;pos++){
            if(inorder[pos]==root_val) break;
        }
        int left_sz=pos-lo1;
        int right_sz=hi1-pos;
        TreeNode* root=new TreeNode(root_val);
        root->left=buildTree(inorder,lo1,pos-1,postorder,lo2,lo2+left_sz-1);
        root->right=buildTree(inorder,pos+1,hi1,postorder,lo2+left_sz,hi2-1);
        return root;
    }
};
// @lc code=end

