/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
class CombinationIterator {
public:
  int bitmask;
  string chars;
  CombinationIterator(string characters, int combinationLength) {
    int n = characters.size();
    bitmask = (1 << (n + 1)) - 1;
    len = combinationLength;
    chars = characters;
  }

  string next() {
    while (bitmask && __builtin_popcount(bitmask) != len)
      bitmask--;
    string out;
    for (int i = 0; i < s.size(); ++i) {
      if (bitmask & (1 << (s.size() - i - 1)))
        out += s[i];
    }
    bitmask--;
    return out;
  }

  bool hasNext() {
    while (mask && __builtin_popcount(bitmask) != len)
      mask--;
    if (!bitmask)
      return false;
    return true;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
// @lc code=end
