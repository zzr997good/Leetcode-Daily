/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
    // //     //Basic Way to deal with a single word 
    // //     //Time Complexity O(n) n=s.size()
    // //     int i=0;
    // //     int j=0;
    // //     while(i<s.size()&&j<word.size()){
    // //         if(s[i]==word[j]) j++;
    // //         i++;
    // //     }
    // //     return j==word.size();
    
    // //1. 用上面那种基础方法去一个一个处理words中的word，所需时间复杂度为O(n*words_sz)
    // //2. 把上面那种基础方法时间复杂度用hashmap+二分搜索优化到单个时间复杂度为O(mlogn)
    // //2. 然后一个一个去处理words中的word，所需总时间复杂度为O(mlogn*words_sz)
    // // Binary search way to deal with a single word
    // // Time Complexity O(mlogn) m=word.size() n=s.size()
    //     std::unordered_map<char,std::vector<int>> mp;
    //     int res=0;
    //     for(int i=0;i<s.size();i++) mp[s[i]].push_back(i);
    //     for(std::string& word:words){
    //         int pos=-1;
    //         for(int i=0;i<word.size();i++){
    //             if(!mp.count(word[i])) break; //s does not contain this char
    //             std::vector<int> indices=mp[word[i]];
    //             //find the first index that is greater than pos in indices;
    //             int lo=0,hi=indices.size();
    //             while(lo<hi){
    //                 int mid=lo+(hi-lo)/2;
    //                 if(indices[mid]<pos) lo=mid+1;
    //                 else if(indices[mid]>pos) hi=mid;
    //                 else lo=mid+1;
    //             }
    //             //all indices are equal or smaller than pos;
    //             if(lo==indices.size()) break;
    //             //find the smallest index that is greater than pos;
    //             else{
    //                 pos=indices[lo];
    //                 if(i==word.size()-1) res++;
    //             } 
    //         }
    //     }
    //     return res;

    //3. 用基础方法去并行处理所有words
    int res=0;
    std::vector<std::vector<const char*>> need(26);
    for(auto& word:words) need[word[0]-'a'].push_back(word.c_str());
    for(auto& c:s){
        //No string needs c
        if(need[c-'a'].size()==0) continue;
        //Some string needs c
        auto cpy=need[c-'a'];
        //Delete need[c-'a'] first, otherwise if c='b' and next needing char is also 'b' for some word, error happens
        need[c-'a'].clear();
        for(auto ptr:cpy){
            ptr++;
            if((*ptr)=='\0') res++;
            else need[(*ptr)-'a'].push_back(ptr);
        }
    }
    return res;
    }
};
// @lc code=end

