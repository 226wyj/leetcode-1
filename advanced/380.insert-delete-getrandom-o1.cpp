class RandomizedSet {
    private:
        vector<int> nums;
        unordered_map<int, int> locs;
        // if allow duplicate: use set for value
        // always remove the last element from the set
        // unordered_map<int, set<int>> locs;
        // set<int> s = locs[val];
        // s.erase(s.end());
    public:
        /** Initialize your data structure here. */
        RandomizedSet() {
        }

        /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
        bool insert(int val) {
            if (locs.find(val) != locs.end()) return false;
            nums.push_back(val);
            locs[val] = nums.size() - 1;
            return true;
        }

        /** Removes a value from the set. Returns true if the set contained the specified element. */
        bool remove(int val) {
            if (locs.find(val) == locs.end()) return false;
            // move the last element to the last one of the list
            // so it's easy to be 'pop_back' O(1)
            int last = nums.back();
            locs[last] = locs[val];
            nums[locs[val]] = last;
            nums.pop_back();
            locs.erase(val);
            return true;
        }

        /** Get a random element from the set. */
        int getRandom() {
            return nums[rand() % nums.size()];
        }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
