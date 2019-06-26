class NumArray {
public:
    NumArray(vector<int>& nums)
    {
        if (nums.empty())
            return;
        data = nums;
        double root = sqrt(data.size());
        len = ceil(data.size() / root);
        block.resize(len);
        for (int i = 0; i < data.size(); ++i) {
            block[i / len] += data[i];
        }
    }

    void update(int i, int val)
    {
        ind idx = i / len;
        block[idx] += val - data[i];
        data[i] = val;
    }

    int sumRange(int i, int j)
    {
        int sum = 0;
        int start = i / len, end = j / len;
        if (start == end) {
            for (int k = 0; k <= j; ++k) {
                sum += data[k];
            }
            return sum;
        }
        for (int k = i; k < (start + 1) * len; ++k) {
            sum += data[k];
        }

        for (int k = start + 1; k < end; ++k) {
            sum += block[k];
        }

        for (int k = end * len; k <= j; ++k) {
            sum += data[k];
        }
        return sum;
    }

private:
    int len;
    vector<int> data, block;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
