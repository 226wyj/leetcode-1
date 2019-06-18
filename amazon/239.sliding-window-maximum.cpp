class MonoQueue {
public:
    /*! \brief push
     *
     *  keep the larger value in the deque
     *
     * \param e integer
     * \return void
     */
    void push(int e)
    {
        while (!data_.empty() && e > data_.back()) {
            data_.pop_back();
        }
        data_.push_back(e);
    }

    /*! \brief pop
     *
     *  pop the first element from the queue
     *
     * \return void
     */
    void pop() { data_.pop_front(); }

    /*! \brief front
     *
     *  get the front/largest element from the queue
     *
     * \return largest element
     */
    int max() const { return data_.front(); }

private:
    deque<int> data_;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        MonoQueue q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
            if (i - k + 1 >= 0) {
                ans.push_back(q.max());
                if (nums[i - k + 1] == q.max())
                    q.pop();
            }
        }
        return ans;
    }
};
