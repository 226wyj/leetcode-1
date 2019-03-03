class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            unsigned index = 0;
            for (int n : nums)
                if (!n) continue;
                else nums[index++] = n;
            for (; index < nums.size(); ++index)
                nums[index] = 0;
        }
};
