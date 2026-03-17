class Solution {
public:
    int f(int &m, int &n, vector<vector<int>> &dp){
        if(m == 0 && n==0)
            return 1;
        
        if(m <0 || n<0)
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        m = m-1;
        int left = f(m, n,dp);
        m = m+1;
        n = n-1;
        int up = f(m, n,dp);
        n = n+1;

        return dp[m][n] = left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        m = m-1;
        n = n-1;
        return f(m,n,dp);
    }
};