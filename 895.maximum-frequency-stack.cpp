/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
public:
    FreqStack() {
        max_freq=0;
    }
    
    void push(int val) {
        if(!num_freq.count(val)) PushNewNum(val);
        else PushExistedNum(val);
    }
    
    int pop() {
        return PopMaxFreq();
    }
private:
    unordered_map<int, int> num_freq;
    unordered_map<int,list<int>> freq_nums; //If num=5, freq=3, then 5 should appear in freq[1] list, freq[2] list and freq[3] list, every back of the list is the element close to the top
    int max_freq;

    void PushNewNum(int num){
        num_freq[num]=1;
        freq_nums[1].push_back(num);
        if(max_freq==0) max_freq=1;
    }

    void PushExistedNum(int num){
        num_freq[num]++;
        int new_freq=num_freq[num];
        freq_nums[new_freq].push_back(num);
        if(new_freq>max_freq) max_freq=new_freq;
    }

    int PopMaxFreq(){
        int max_freq_num=freq_nums[max_freq].back();
        num_freq[max_freq_num]--;
        if(num_freq[max_freq_num]==0) num_freq.erase(max_freq_num);
        freq_nums[max_freq].pop_back();
        if(freq_nums[max_freq].empty()){
            freq_nums.erase(max_freq);
            max_freq--;
        }
        return max_freq_num;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

