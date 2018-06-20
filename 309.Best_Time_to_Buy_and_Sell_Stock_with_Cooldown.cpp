class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre_buy=INT_MIN, buy=INT_MIN, pre_sell=0, sell=0;
        for(int price:prices){
            pre_buy=buy;
            buy=max(pre_buy, pre_sell-price);
            pre_sell=sell;
            sell=max(pre_sell, pre_buy+price);
        }
        return max(sell, buy);
    }
};
