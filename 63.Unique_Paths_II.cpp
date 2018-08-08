class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]==1) return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<int> path(n, 1);
        for(int j=1;j<n;j++)
        {
            path[j] = obstacleGrid[0][j]==1?0:path[j-1];
        }

        for(int i=1;i<m;i++)
        {
            path[0] = obstacleGrid[i][0]==1?0:path[0];
            for(int j=1;j<n;j++)
            {
                path[j] = obstacleGrid[i][j]==1?0:path[j]+path[j-1];
            }
        }
        return path[n-1];
    }
};
