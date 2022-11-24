/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
//Recursive way
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==nullptr) return {};
        for(int i=0;i<root->children.size();i++){
            postorder(root->children[i]);
        }
        res.push_back(root->val);
        return res;
    }

private:
    vector<int> res;
};
// @lc code=end

