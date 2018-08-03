class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=0;
        int n=matrix.size()-1;

        while(m<n)
        {
            for(int i=m;i<n;i++)
            {
                int tmp=matrix[m][i];
                matrix[m][i]=matrix[n-i+m][m];
                matrix[n-i+m][m]=matrix[n][n-i+m];
                matrix[n][n-i+m]=matrix[i][n];
                matrix[i][n]=tmp;
            }
            m++;
            n--;
        }
    }
};
