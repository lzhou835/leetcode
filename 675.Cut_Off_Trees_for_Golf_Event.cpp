class Solution {
public:
    int solve(vector<vector<int>> & forest, int srcrow, int srccol, int dstrow, int dstcol){
        if(srcrow==dstrow && srccol==dstcol) return 0;
        int m=forest.size(), n=forest[0].size(), cnt=0;
        queue<pair<int, int>> q;
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({srcrow, srccol});
        while(!q.empty()){
            cnt++;
            int limit=q.size();
            for(int i=0;i<limit;i++){
                auto t=q.front();
                q.pop();
                for(auto a:dir){
                    int x=t.first+a[0], y=t.second+a[1];
                    if(x<0 || y<0 || x>=m || y>=n || visited[x][y] || forest[x][y]==0) continue;
                    if(x==dstrow && y==dstcol) return cnt;
                    visited[x][y]=true;
                    q.push({x,y});
                }
            }
        }
        
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size(), n=forest[0].size(), res=0, col=0, row=0;
        vector<vector<int>> trees;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j]>1) trees.push_back({forest[i][j], i, j});
            }
        }
        
        sort(trees.begin(), trees.end());
        for(int i=0;i<trees.size();i++){
            int cnt=solve(forest, row, col, trees[i][1], trees[i][2]);
            if(cnt==-1) return -1;
            res+=cnt;
            row=trees[i][1];
            col=trees[i][2];
        }
        
        return res;
    }
};
