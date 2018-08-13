class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ret=0;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j]= A[i-1]==B[j-1]?dp[i-1][j-1]+1:0;
                ret=max(ret, dp[i][j]);
            }
        }
        return ret;
    }
};
