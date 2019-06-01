class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            /* return method1(obstacleGrid); */
            /* return method2(obstacleGrid); */
            return method3(obstacleGrid);
        }

        /******************************************************************************
        * Function:         
        * Description:      directly modify the inpout obstacleGrid
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method1(vector<vector<int>>& obstacleGrid) {
            if (obstacleGrid.size() == 0 || obstacleGrid[0][0]) { return 0; }
            int height = obstacleGrid.size(), width = obstacleGrid[0].size();

            obstacleGrid[0][0] = 1;
            for (int i = 1; i < width; ++i) {
                if (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) {
                    obstacleGrid[0][i] = 1;
                } else {
                    obstacleGrid[0][i] = 0; 
                }
            } 
            for (int j = 1; j < height; ++j) {
                if (obstacleGrid[j][0] == 0 && obstacleGrid[j - 1][0] == 1) {
                    obstacleGrid[j][0] = 1;
                } else {
                    obstacleGrid[j][0] = 0; 
                }
            } 
            for (int i = 1; i < height; ++i) {
                for (int j = 1; j < width; ++j) {
                    if (obstacleGrid[i][j] == 1) {
                        obstacleGrid[i][j] = 0; 
                    } else {
                        obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j];
                    } 
                } 
            }
            return obstacleGrid[height - 1][width - 1];
        }

        /******************************************************************************
        * Function:         int method2
        * Description:      create another m+1, n+1 matrix
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method2(vector<vector<int>>& obstacleGrid){
            if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
                return 0;
            }
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
            dp[0][1] = 1;
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (obstacleGrid[i - 1][j - 1] != 0) {
                        continue; 
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
            return dp[m][n];
        }

        /******************************************************************************
        * Function:         int method3
        * Description:      create one 1d array
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        int method3(vector<vector<int>>& obstacleGrid){
            if (obstacleGrid.empty() || obstacleGrid[0].empty())
                return 0;
            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            vector<long> dp(n, 0);
            dp[0] = 1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (obstacleGrid[i][j] == 1) {
                        dp[j] = 0;
                    } else if (j > 0) {
                        dp[j] += dp[j - 1];
                    }
                }
            }
            return dp[n - 1];
        }
};
