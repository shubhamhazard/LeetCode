class Solution {
public:
    int maxAmount(int n, vector<int> &nums, vector<int> &dp)
    {
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int choice1 = nums[n] + maxAmount(n-2, nums,dp);

        int choice2 = maxAmount(n-1,nums,dp);

        return dp[n] = max(choice1,choice2);
    }

    int tabulation(int n , vector<int> &nums)
    {
        vector<int> dp(n,0);
        dp[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            int choice1 = nums[i];
            if(i>1)
                choice1 += dp[i-2];
            
            int choice2 = dp[i-1];

            dp[i] = max(choice1, choice2);
        }
        return dp[n-1];
    }

    int spaceOpti(int n, vector<int> &nums)
    {
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i=1; i<n; i++)
        {
            int choice1 = nums[i];
            if(i>1)
                choice1 += prev2;
            
            int choice2 = prev1;

            int curr = max(choice1, choice2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        // return maxAmount(n-1,nums,dp);
        // return tabulation(n,nums);
        return spaceOpti(n,nums);
    }
};