class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ret=0, start=arrays[0][0], end=arrays[0].back();
        for(int i=1;i<arrays.size();i++){
            ret=max(ret, max(abs(arrays[i].back()-start), abs(arrays[i][0]-end)));
            start=min(start, arrays[i][0]);
            end=max(end, arrays[i].back());
        }
        return ret;
    }
};
