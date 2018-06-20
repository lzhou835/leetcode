class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N+1, 0);
        for(int i=0;i<N+1;i++){
            dp[i]=i;
            for(int j=1;j<i-2;j++){
                dp[i]=max(dp[i], dp[j]*(i-1-j));
            }
        }
        return dp[N];
    }
};
