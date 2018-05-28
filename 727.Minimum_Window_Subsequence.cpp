class Solution {
public:
    string minWindow(string S, string T) {
        int m=S.length(), n=T.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        int minlen=m, start=-1;
        for(int i=0;i<=m;i++) dp[i][0]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=min(i, n);j++){
                dp[i][j]=S[i-1]==T[j-1]?dp[i-1][j-1]:dp[i-1][j];
            }
            if(dp[i][n]!=-1){
                int len=i-dp[i][n];
                if(len<minlen){
                    minlen=len;
                    start=dp[i][n];
                }
            }
        }
        return start==-1?"":S.substr(start, minlen);
    }
};
