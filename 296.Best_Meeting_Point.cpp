class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        return distance(rows)+distance(cols);
    }
    
    int distance(vector<int> v){
        int res=0;
        int i=0, j=v.size()-1;
        sort(v.begin(), v.end());
        while(i<j) res+=v[j--]-v[i++];
        return res;
    }
};
