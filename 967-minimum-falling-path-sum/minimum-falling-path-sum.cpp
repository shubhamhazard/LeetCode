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

        int mini = INT_MAX;

        for(int j=0; j<m; j++)
            dp[0][j] = matrix[0][j];

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){

                int up = matrix[i][j] + dp[i-1][j];

                int leftDia = matrix[i][j];
                if(j-1 >=0)
                    leftDia += dp[i-1][j-1];
                else
                    leftDia += 1e8;
                
                int rightDia = matrix[i][j];
                if(j+1 < m)
                    rightDia += dp[i-1][j+1];
                else
                    rightDia += 1e8;

                dp[i][j] = min(up, min(leftDia, rightDia));
            }
        }

        for(int j=0; j<m; j++){
            mini = min(mini, dp[n-1][j]);
        }

        // return mini;


        // for(int j=0; j<m; j++){
        //     mini = min(mini, f(n-1, j, n,m, matrix,dp));
        // }

        return mini;
    }
};