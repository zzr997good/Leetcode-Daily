/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start

// * Below is the interface for Iterator, which is already defined for you.
// * **DO NOT** modify the interface for Iterator.
// *
// *  class Iterator {
// *		struct Data;
// * 		Data* data;
// *  public:
// *		Iterator(const vector<int>& nums);
// * 		Iterator(const Iterator& iter);
// *
// * 		// Returns the next element in the iteration.
// *		int next();
// *
// *		// Returns true if the iteration has more elements.
// *		bool hasNext() const;
// *	};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        if(Iterator::hasNext()) cache_next=Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return cache_next.value();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int temp=cache_next.value();
        if(Iterator::hasNext()) cache_next=Iterator::next();
        else cache_next={};
        return temp;
	}
	
	bool hasNext() const {
	     return cache_next.has_value();
	}
private:
    std::optional<int> cache_next;
};
// @lc code=end

