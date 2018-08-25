class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows<=0) return ret;
        ret.assign(numRows, vector<int>(1));
        for(int i=0;i<numRows;i++){
            ret[i][0]=1;
            if(i==0) continue;
            for(int j=1;j<i;j++) ret[i].push_back(ret[i-1][j-1]+ret[i-1][j]);
            ret[i].push_back(1);
        }
        return ret;
    }
};
