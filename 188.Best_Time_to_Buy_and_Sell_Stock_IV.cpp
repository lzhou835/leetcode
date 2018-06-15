class Solution {
public:
    int unlimitedmaxProfit(vector<int> & prices){
        int res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0) res+=prices[i]-prices[i-1];
        }
        return res;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0) return 0;
        if(prices.size()<=k) return unlimitedmaxProfit(prices);
        
        int local[k+1]={0};
        int global[k+1]={0};
        
        for(int i=0;i<prices.size()-1;i++){
            int diff=prices[i+1]-prices[i];
            for(int j=k;j>=1;j--){
                local[j]=max(global[j-1]+max(diff, 0), local[j]+diff);
                global[j]=max(global[j], local[j]);
            }
        }
        return global[k];
    }
};
