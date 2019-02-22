class Solution {
    public:
        bool canJump(vector<int>& nums) {
            unsigned last = nums.size() - 1;
            for (unsigned i = nums.size() - 1; i < nums.size(); --i)
                // max jump + current pos
                if (nums[i] + i >= last) last = i;
            return last == 0; // from origin
        }
};
