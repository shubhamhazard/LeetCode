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

    int bottomUp(string s)
    {
        int n = s.length();
        vector<int> t(n+1, 0);

        t[n] = 1;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i] == '0')
                t[i] = 0;
            else{
                t[i] += t[i+1];

                if(i+1 < n){
                    if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                        t[i] += t[i+2];
                }
            }
        }
        return t[0];
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        // return solve(0, s, n,dp);
        return bottomUp(s);
    }
};