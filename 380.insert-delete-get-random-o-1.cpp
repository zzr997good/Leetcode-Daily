/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {
        sz=0;
    }
    
    bool insert(int val) {
        if(val_to_index.count(val)) return false;
        else {
            val_to_index[val]=sz;
            valset.push_back(val);
            sz++;
            return true;
        }
    }
    
    bool remove(int val) {
        if(!val_to_index.count(val)) return false;
        int index=val_to_index[val];
        swap(valset[index],valset[sz-1]);
        val_to_index[valset[index]]=index;
        valset.pop_back();
        val_to_index.erase(val);
        sz--;
        return true;
    }
    
    int getRandom() {
        return valset[rand()%sz];
    }
private:
    unordered_map<int, int> val_to_index;
    vector<int> valset;
    int sz;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

