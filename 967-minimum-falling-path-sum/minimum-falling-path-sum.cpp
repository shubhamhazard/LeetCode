class Solution {
public:

    int f(int i, int j, int n, int m,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=m)
            return 1e9;
        
        if(i == 0)
            return matrix[0][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int up = matrix[i][j] + f(i-1, j, n, m, matrix, dp);
        int leftDia = matrix[i][j] + f(i-1,j-1, n, m, matrix, dp);
        int rightDia = matrix[i][j] + f(i-1, j+1, n,m, matrix, dp);

        return dp[i][j] = min(up, min(leftDia, rightDia));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m,0));
        
        vector<int> prev(n), curr(n);

        int mini = INT_MAX;

        // for(int j=0; j<m; j++)
        //     dp[0][j] = matrix[0][j];

        for(int j=0; j<m; j++)
            prev[j] = matrix[0][j];

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){

                int up = matrix[i][j] + prev[j];

                int leftDia = matrix[i][j];
                if(j-1 >=0)
                    leftDia += prev[j-1];
                else
                    leftDia += 1e8;
                
                int rightDia = matrix[i][j];
                if(j+1 < m)
                    rightDia += prev[j+1];
                else
                    rightDia += 1e8;

                curr[j] = min(up, min(leftDia, rightDia));
            }
            prev = curr;
        }

        // for(int j=0; j<m; j++){
        //     mini = min(mini, dp[n-1][j]);
        // }

        for(int j=0; j<m; j++)
            mini = min(mini, prev[j]);


        // for(int j=0; j<m; j++){
        //     mini = min(mini, f(n-1, j, n,m, matrix,dp));
        // }

        return mini;
    }
};