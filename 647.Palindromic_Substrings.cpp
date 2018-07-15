class Solution {
public:
    int countSubstrings(string s) {
        int ret=0, n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                dp[i][j]=(s[i]==s[j]) && (j-i<=2 || dp[i+1][j-1]);
                if(dp[i][j]) ret++;
            }
        }
        return ret;
    }
};

