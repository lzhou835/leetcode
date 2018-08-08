class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n, 0));
        int layer=n/2;
        int count=1;

        for(int i=0;i<layer;i++)
        {
            int end=n-1-i;
            for(int j=i;j<end;j++)
                ret[i][j]=count++;
            for(int j=i;j<end;j++)
                ret[j][end]=count++;
            for(int j=end;j>i;j--)
                ret[end][j]=count++;
            for(int j=end;j>i;j--)
                ret[j][i]=count++;
        }

        if(n%2) ret[n/2][n/2]=count++;

        return ret;
    }
};
