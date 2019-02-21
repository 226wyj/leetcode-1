class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
	unsigned sum = 0;
	for (int n : nums) sum += n;
	// it is not possible to sum non-fractional number into fractional
	if (sum % k > 0) return false;
	unsigned target = sum / k;
	sort(nums.begin(), nums.end());
	int row = nums.size() - 1;
	// largest element is already greater than target
	if (nums[row] > target) return false;
	// if current element is already = target -> skip
	while (row >= 0 && nums[row] == target) {
		row--;
		k--;
	}
	vector<int> groups(k);
	return search(groups, row, nums, target);
    }

    bool search(vector<int>& groups, int row, vector<int>& nums, unsigned target)  {
	if (row < 0) return true;
	int v = nums[row--];
	for (unsigned i = 0; i < groups.size(); ++i) {
		if (groups[i] + v <= target) {
			groups[i] += v;
			if (search(groups, row, nums, target)) return true;
			groups[i] -= v;
		}
		if (groups[i] == 0) break;
	}
	return false;
    }
};
