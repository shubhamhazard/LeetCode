class Solution {
public:
    int solve(int idx, string s, int n, vector<int> &dp) {
        if (idx == n)
            return 1;
        if (s[idx] == '0')
            return 0;

        if(dp[idx] != -1)
            return dp[idx];
        int result = solve(idx + 1, s, n,dp);
        if (idx + 1 < n) {
            if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6'))
                result += solve(idx + 2, s, n,dp);
        }

        return dp[idx] = result;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return solve(0, s, n,dp);
    }
};