class Solution {
public:
    void dfs(vector<vector<int>> & grid, map<int, vector<pair<int, int>>> & mp, int i, int j, int cnt){
        int m=grid.size(), n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return;
        if(grid[i][j]!=1) return;
        grid[i][j]=cnt;
        mp[cnt].push_back({i, j});
        dfs(grid, mp, i+1, j, cnt);
        dfs(grid, mp, i-1, j, cnt);
        dfs(grid, mp, i, j+1, cnt);
        dfs(grid, mp, i, j-1, cnt);
    }
    
    vector<pair<int, int>> norm(vector<pair<int, int>>  v){
        vector<vector<pair<int, int>>> a(8);
        
        for(auto p:v){
            int x=p.first, y=p.second;
            a[0].push_back({x, y});
            a[1].push_back({x, -y});
            a[2].push_back({-x, y});
            a[3].push_back({-x, -y});
            a[4].push_back({y, -x});
            a[5].push_back({-y, x});
            a[6].push_back({-y, -x});
            a[7].push_back({y, x});
        }
        
        for(auto & l:a) sort(l.begin(), l.end());
        for(auto & l:a){
            for(int i=1;i<v.size();i++){
                l[i]={l[i].first-l[0].first, l[i].second-l[0].second};
            }
            l[0]={0, 0};
        }
        
        sort(a.begin(), a.end());
        return a[0];
    }
    
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int cnt=1;
        map<int, vector<pair<int, int>>> mp;
        set<vector<pair<int, int>>> s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    dfs(grid, mp, i, j, ++cnt);
                    s.insert(norm(mp[cnt]));
                }
            }
        }
        return s.size();
    }
};
