class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if(M.empty() || M[0].empty()) return {};
        vector<vector<int>> res=M, dir{{0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {-1, -1}, {-1, 0}, {-1, 1}};
        int m=M.size(), n=M[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=M[i][j], cnt=1;
                for(auto d:dir){
                    int x=i+d[0], y=j+d[1];
                    if(x<0 || y<0 || x>=m || y>=n) continue;
                    cnt++;
                    sum+=M[x][y];
                }
                res[i][j]=sum/cnt;
            }
        }
        return res;
    }
};
