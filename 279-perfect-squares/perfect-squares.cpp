    class Solution {
    public:
        int countMin(int n, vector<int> &dp){
            if(n==0)
                return 0;

            if(dp[n] != -1)
                return dp[n];

            int mini = INT_MAX;
            for(int i=1; i*i<=n; i++)
            {
                int result = 1 + countMin(n-i*i, dp);
                mini = min(mini, result);
            }
            return dp[n]=mini;
        }
        int numSquares(int n) {
            vector<int> dp(n+1, -1);
            return countMin(n,dp);
        }
    };