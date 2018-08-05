class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;

        if(matrix.empty() || matrix[0].empty()) return ret;

        int m=matrix.size();
        int n=matrix[0].size();

        int layer=(min(m,n)+1)/2;

        for(int i=0;i<layer;i++)
        {
            int rowend=m-1-i;
            int colend=n-1-i;

            if(i==rowend){
                for(int j=i;j<=colend;j++)
                    ret.push_back(matrix[i][j]);
            }else if(i==colend){
                for(int j=i;j<=rowend;j++)
                    ret.push_back(matrix[j][i]);
            }else{
                for(int j=i;j<colend;j++)
                    ret.push_back(matrix[i][j]);
                for(int j=i;j<rowend;j++)
                    ret.push_back(matrix[j][colend]);
                for(int j=colend;j>i;j--)
                    ret.push_back(matrix[rowend][j]);
                for(int j=rowend;j>i;j--)
                    ret.push_back(matrix[j][i]);
            }
        }

        return ret;
    }
};

