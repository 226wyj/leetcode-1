class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) {
                return nums[pos];
            } else if (pos > k - 1) {
                right = pos - 1;
            } else {
                left = pos + 1;
            }
        }
    }

    /*! \brief partition list
     *
     *  parition to make sure everything on the left of pivot are larger than
     * pivot
     *
     * \param nums inputs vector
     * \param left starting point
     * \param right ending point
     * \return curr position after sorting
     */
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot)
                ++l;
            if (nums[r] <= pivot)
                --r;
        }
        print(nums);
        swap(nums[left], nums[r]);
        return r;
    }

    void print(vector<int>& nums)
    {
        for (int n : nums) {
            printf("%d * ", n);
        }
        printf("\n");
    }
};
