/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start
class Trie{
public:
    unordered_map<char,Trie*> children;
    char c;
    bool isWord=false;
    string wd;
    Trie(){
    }
    Trie(char c){
        this->c=c;
    }
};
class Solution {
private:
    void insert(string& word,Trie* root){
        Trie* cur=root;
        for(char ch:word){
            if(!cur->children.count(ch)){
                cur->children[ch]=new Trie(ch);
            }
            cur=cur->children[ch];
        }
        cur->isWord=true;
        cur->wd=word;
    }
    string res="";
    void dfs_traverse(Trie* root){
        if(root->children.size()==0) return;
        for(auto it=(root->children.begin());it!=(root->children.end());it++){
            if(!(it->second->isWord)) continue;
            else{
                if(it->second->wd.size()==res.size()){
                    res=min(it->second->wd,res);
                }
                if(it->second->wd.size()>res.size()){
                    res=it->second->wd;
                }
                dfs_traverse(it->second);
            }
        }
        return;
    }

public:
    string longestWord(vector<string>& words) {
        Trie* root=new Trie();
        for(string& word:words){
            insert(word,root);
        }
        dfs_traverse(root);
        return res;
    }
};
// @lc code=end

