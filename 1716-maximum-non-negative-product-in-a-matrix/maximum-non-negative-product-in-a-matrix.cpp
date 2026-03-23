// 2D array optimized for space
int64_t dp[15][2];
class Solution {
public:
    static int maxProductPath(vector<vector<int>>& grid) {
        const int r=grid.size(), c=grid[0].size(), MOD=1e9+7;
        int64_t p=dp[0][0]=dp[0][1]=grid[0][0];
        for(int j=1; j<c; j++){
            p*=grid[0][j];
            dp[j][0]=dp[j][1]=p;
        }
        p=grid[0][0];
        for(int i=1; i<r; i++){
            p*=grid[i][0];
            dp[0][0]=dp[0][1]=p;
            for(int j=1; j<c; j++){
                const int x=grid[i][j];
                tie(dp[j][0], dp[j][1])=minmax({x*dp[j-1][0], x*dp[j-1][1], x*dp[j][0], x*dp[j][1]});
            }
        }
        int64_t ans=dp[c-1][1];
        return ans<0?-1: ans%MOD;
    }
};