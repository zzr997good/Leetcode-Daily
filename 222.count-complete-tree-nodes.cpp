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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int depth=getDepth(root);
         //there are 2^depth-1 nodes above last floor
        int lo=0,hi=(1<<depth);
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(exist(root,depth,mid)){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        return (1<<depth)-1+lo;
    }
private:
    int getDepth(TreeNode* root){
        int depth=-1;
        while(root!=nullptr){
            depth++;
            root=root->left;
        }
        return depth;
    }
    bool exist(TreeNode* root, int depth,int no){
        //The nodes in depth are labeled from 0 to 2^depth-1
        int start=0,last=(1<<depth)-1;
        while(start!=last){
            int mid=start+(last-start)/2;
            if(no<=mid){
                root=root->left;
                last=mid;
            }
            else{
                root=root->right;
                start=mid+1;
            }
        }
        return root!=nullptr;
    }
};
// @lc code=end

