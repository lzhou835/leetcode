class Solution {
public:
    vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int dfs(vector<vector<int>> & matrix, vector<vector<int>> & dp, int i, int j){
        if(dp[i][j]) return dp[i][j];
        int m=matrix.size(), n=matrix[0].size();
        int mx=1;
        for(auto d:dir){
            int x=i+d[0], y=j+d[1];
            if(x<0 || y<0 || x>=m || y>=n || matrix[x][y]<=matrix[i][j]) continue;
            int len=1+dfs(matrix, dp, x, y);
            mx=max(mx, len);
        }
        dp[i][j]=mx;
        return mx;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res=max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
};
