class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m<1) return false;
        int n=matrix[0].size();
        if(n<1) return false;

        int low=0;
        int high=m*n-1;
        while(low+1<high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid/n][mid%n]<target)
            {
                low=mid;
            }else{
                high=mid;
            }
        }

        if(matrix[low/n][low%n] == target) return true;
        if(matrix[high/n][high%n] == target) return true;
        return false;
    }
};
