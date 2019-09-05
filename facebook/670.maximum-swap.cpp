class Solution {
public:
    int maximumSwap(int num)
    {
        string res = to_string(num), back = res;
        for (int i = back.size() - 2; i >= 0; --i) {
            back[i] = max(back[i], back[i + 1]);
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == back[i])
                continue;
            //如果当前的值不是可以放的最大的，则找到最大的位置，并且与当前值swap
            for (int j = res.size() - 1; j > i; --j) {
                if (res[j] == back[i]) {
                    swap(res[i], res[j]);
                    return stoi(res);
                }
            }
        }
        return stoi(res);
    }
};
