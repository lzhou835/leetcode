class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), res=0;
        for(int i=0;i<m;i++){
            vector<int> v;
            for(int k=0;k<grid[i].size();k++) if(grid[i][k]) v.push_back(k);
            for(int j=i+1;j<m;j++){
                int cnt=0;
                for(int a:v){
                    if(grid[j][a]) cnt++;
                }
                res+=cnt*(cnt-1)/2;
            }
        }
        return res;
    }
};
