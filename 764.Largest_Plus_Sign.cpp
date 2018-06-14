class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res=0, cnt=0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        unordered_set<int> s;
        for(auto m:mines) s.insert(N*m[0]+m[1]);
        for(int j=0;j<N;j++){
            cnt=0;
            for(int i=0;i<N;i++){
                cnt=s.count(i*N+j)==1?0:cnt+1;
                dp[i][j]=cnt;
            }
            cnt=0;
            for(int i=N-1;i>=0;i--){
                cnt=s.count(i*N+j)==1?0:cnt+1;
                dp[i][j]=min(dp[i][j], cnt);
            }
        }
        for(int i=0;i<N;i++){
            cnt=0;
            for(int j=0;j<N;j++){
                cnt=s.count(i*N+j)==1?0:cnt+1;
                dp[i][j]=min(dp[i][j], cnt);
            }
            cnt=0;
            for(int j=N-1;j>=0;j--){
                cnt=s.count(i*N+j)==1?0:cnt+1;
                dp[i][j]=min(dp[i][j], cnt);
                res=max(res, dp[i][j]);
            }
        }
        return res;
    }
};
