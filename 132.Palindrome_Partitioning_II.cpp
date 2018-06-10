class Solution {
public:
    int minCut(string s) {
        int len=s.size();
        vector<vector<bool>> p(len, vector<bool>(len, false));
        vector<int> dp(len+1, 0);
        for(int i=0;i<=len;i++)
            dp[i]=len-i-1;
        for(int i=len-1;i>=0;i--){
            for(int j=i;j<len;j++){
                if(s[i]==s[j] && (j-i<=1 || p[i+1][j-1])){
                    p[i][j]=true;
                    dp[i]=min(dp[i],1+dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};
