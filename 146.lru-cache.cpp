/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class Node{
public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int key,int val){
        this->key=key;
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};


class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        dummy_head=new Node(-1,-1);
        dummy_tail=new Node(-1,-1);
        dummy_head->next=dummy_tail;
        dummy_tail->prev=dummy_head;
    }
    
    int get(int key) {
        if(!key_to_val.count(key)) return -1;
        if(!isRecent(key)) MakeRecent(key);
        return key_to_val[key]->val;
    }
    
    void put(int key, int value) {
        //This key exists, update it
        if(key_to_val.count(key)){
            if(!isRecent(key)) MakeRecent(key);
            key_to_val[key]->val=value;
        }
        //This key does not exist, but the number of pairs is less than capacity
        else if(key_to_val.size()<capacity){
            key_to_val[key]=Add(key,value);
        }
        //This key does not exist, but the number of pairs is equal to capacity, must delete the last element in the list, which is the least recently used
        else{
            int least_recent_key=RemoveLeastRecent();
            key_to_val.erase(least_recent_key);
            key_to_val[key]=Add(key,value);    
        }
    }
private:
    unordered_map<int, Node* > key_to_val;
    int capacity;
    Node *dummy_head;
    Node *dummy_tail;

    // void MakeRecent(int key){
    //     Node* cur=key_to_val[key];
    //     int val=cur->val;
    //     //First Delete this old node
    //     cur->next->prev=cur->prev;
    //     cur->prev->next=cur->next;
    //     cur->next=nullptr;
    //     cur->prev=nullptr;
    //     delete(cur);
    //     //Then add the new node with same value to the head
    //     cur=new Node(val);
    //     cur->next=dummy_head->next;
    //     cur->prev=dummy_head;
    //     dummy_head->next=cur;
    //     cur->next->prev=cur;
    //     //Update the value of key_to_val[key];
    //     key_to_val[key]=cur;
    // }

    void Remove(Node* cur){
        cur->next->prev=cur->prev;
        cur->prev->next=cur->next;
        cur->next=nullptr;
        cur->prev=nullptr;
        delete(cur);
    }

    Node* Add(int key,int val){
        Node* cur=new Node(key,val);
        cur->next=dummy_head->next;
        cur->prev=dummy_head;
        dummy_head->next=cur;
        cur->next->prev=cur;
        return cur;
    }

    void MakeRecent(int key){
        Node* cur=key_to_val[key];
        int val=cur->val;
        Remove(cur);
        key_to_val[key]=Add(key,val);
    }
    
    int RemoveLeastRecent(){
        Node* cur=dummy_tail->prev;
        int key=cur->key;
        Remove(cur);
        return key;
    }

    bool isRecent(int key){
        return key_to_val[key]==dummy_head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

