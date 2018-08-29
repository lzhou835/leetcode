class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;

        vector<int> leftprofit(n, 0);

        int leftmin=prices[0];
        int leftmaxprofit=0;

        for(int i=1;i<n;i++)
        {
            if(prices[i]<leftmin)
            {
                leftmin=prices[i];
            }else{
                leftmaxprofit=max(leftmaxprofit, prices[i]-leftmin);
            }
            leftprofit[i]=leftmaxprofit;
        }

        int ret=leftprofit[n-1];

        int rightmax=prices[n-1];
        int rightmaxprofit=0;
        for(int i=n-1;i>=0;i--)
        {
            if(prices[i]>rightmax)
            {
                rightmax=prices[i];
            }else{
                rightmaxprofit=max(rightmax-prices[i], rightmaxprofit);
            }
            ret=max(ret, rightmaxprofit+leftprofit[i]);
        }
        return ret;
    }
};
