class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        vector<int> sum(n+1, 0);
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+nums[i-1];
        dp[0][0]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=i-1;k<j;k++){
                    dp[i][j]=min(dp[i][j], max(dp[i-1][k], sum[j]-sum[k]));
                }
            }
        }
        return dp[m][n];
    }
};
