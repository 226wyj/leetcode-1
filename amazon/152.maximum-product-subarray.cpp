class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int size = nums.size();
            if (size == 0) { return 0; }
            int oldMin = nums[0];
            int oldMax = nums[0];
            int ret = nums[0];
            for (size_t i = 1; i < size; ++i) {
                int newMax = max(nums[i], nums[i] > 0 ? oldMax * nums[i] : oldMin * nums[i]);
                int newMin = min(nums[i], nums[i] > 0 ? oldMin * nums[i] : oldMax * nums[i]);
                printf("newMax is: %d newMin is: %d\n", newMax, newMin);
                ret = max(ret, newMax);
                oldMin = newMin;
                oldMax = newMax;
            }
            return ret;
        }
};
