class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        for(int i=0;i<pow(2,n);i++)
            ret.push_back((i>>1)^i);
        return ret;
    }
};
