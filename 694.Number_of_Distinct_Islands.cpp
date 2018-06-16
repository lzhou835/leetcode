class Solution {
public:
    vector<vector<int>> dir{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    void solve(vector<vector<int>> & grid, vector<pair<int, int>> & v, int x0, int y0, int i, int j){
        int m=grid.size(), n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]<=0) return;
        grid[i][j]*=-1;
        v.push_back({i-x0, j-y0});
        for(auto d:dir){
            solve(grid, v, x0, y0, i+d[0], j+d[1]);
        }
        
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        set<vector<pair<int, int>>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=1) continue;
                vector<pair<int, int>> v;
                solve(grid, v, i, j, i, j);
                res.insert(v);
            }
        }
        return res.size();
    }
};
