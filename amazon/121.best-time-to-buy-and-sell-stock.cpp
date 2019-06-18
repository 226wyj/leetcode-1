class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int curr_price = 0, final_price = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int temp = prices[i] - prices[i - 1];
            curr_price += temp;
            if (curr_price < 0)
                curr_price = 0;
            if (curr_price > final_price)
                final_price = curr_price;
        }
        return final_price;
    }
};
