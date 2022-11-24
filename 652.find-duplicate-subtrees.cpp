/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return res;
    }

private:
    unordered_map<string,int> map;
    vector<TreeNode*> res;
    //后序遍历树，然后把数序列化，查看map里出现过没有与root为根结点的子树重复的子树
    string traversal(TreeNode* root){
        if(root==nullptr) return "#";
        string left=traversal(root->left);
        string right=traversal(root->right);
        string cur=left+","+right+","+to_string(root->val);
        if(!map.count(cur)) map[cur]=1;
        else if(map[cur]==1) {
            res.push_back(root);
            map[cur]++;
        }
        else map[cur]++;
        return cur;
    }
};
// @lc code=end

