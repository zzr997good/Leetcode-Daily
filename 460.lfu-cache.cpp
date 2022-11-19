/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        cur_sz=0;
    }
    
    int get(int key) {
        if(!key_freq_and_val.count(key)) return -1;
        else {
            IncreaseFreq(key);
            return key_freq_and_val[key].second->second;
        }
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(key_freq_and_val.count(key)){
            IncreaseFreq(key);
            key_freq_and_val[key].second->second=value;
        }
        else if(cur_sz<capacity) AddKey(key,value);
        else {
            RemoveLeastFreqKey();
            AddKey(key, value);
        }
    }

private:
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> key_freq_and_val;
    unordered_map<int,list<pair<int,int>>> freq_key_val_lists;
    int capacity;
    int cur_sz;
    int min_freq;
    void IncreaseFreq(int key){
        int old_freq=key_freq_and_val[key].first;
        auto pos=key_freq_and_val[key].second;
        int val=(*pos).second;
        //Delete the old node
        freq_key_val_lists[old_freq].erase(pos);
        if(freq_key_val_lists[old_freq].empty()){
            freq_key_val_lists.erase(old_freq);
            if(old_freq==min_freq) min_freq++;
        }
        //Add the new node
        freq_key_val_lists[old_freq+1].push_back({key,val});
        key_freq_and_val[key].first++;
        key_freq_and_val[key].second=--freq_key_val_lists[old_freq+1].end();
    }

    void AddKey(int key,int val){
        min_freq=1;
        cur_sz++;
        freq_key_val_lists[1].push_back({key,val});
        auto pos=--freq_key_val_lists[1].end();
        key_freq_and_val[key]={1,pos};
    }

    void RemoveLeastFreqKey(){
        cur_sz--;
        int deleted_key=freq_key_val_lists[min_freq].front().first;
        key_freq_and_val.erase(deleted_key);
        freq_key_val_lists[min_freq].pop_front();
        if(freq_key_val_lists[min_freq].empty()) freq_key_val_lists.erase(min_freq);

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

