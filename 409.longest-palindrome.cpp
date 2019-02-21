class Solution {
	public:
		int longestPalindrome(string s) {
			vector<int> count(128, 0);
			for (char c : s) count[c]++;
			int ret = 0;
			for (int v : count) {
				ret += v / 2 * 2;
				if (ret % 2 == 0 && v % 2 == 1) ret++;
			}
			return ret;
		}
};
