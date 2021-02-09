/* Problem url: https://leetcode.com/problems/peeking-iterator
 * Code by: ldcduc
 * */
/* Begin of Solution */
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    bool hasPeeked;
    int peekElement;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        hasPeeked = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!hasPeeked) {
            peekElement = this->Iterator::next();
            hasPeeked = true;
        }
        return peekElement;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (!hasPeeked) {
            return this->Iterator::next();
        }
        hasPeeked = false;
        return peekElement;
	}
	
	bool hasNext() const {
        return hasPeeked || this->Iterator::hasNext();
	}
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: iterator, list
 * 
 * */
