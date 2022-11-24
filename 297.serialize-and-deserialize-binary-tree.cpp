/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "#";
        string str_tree;
        str_tree+=to_string(root->val);
        str_tree+=",";
        str_tree+=serialize(root->left);
        str_tree+=",";
        str_tree+=serialize(root->right);
        return str_tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="#") return nullptr;
        //make sure that the data_list is not empty
        list<string> data_list;
        char* token=strtok(const_cast<char*>(data.c_str()),",");
        while(token!=nullptr){
            data_list.push_back(token);
            token=strtok(NULL,",");
        }
        return getTree(data_list);
    }

private:
    TreeNode* getTree(list<string>& data_list){
        string node_val=data_list.front();
        data_list.pop_front();
        if(node_val=="#") return nullptr;
        TreeNode* root=new TreeNode(stoi(node_val));
        root->left=getTree(data_list);
        root->right=getTree(data_list);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

