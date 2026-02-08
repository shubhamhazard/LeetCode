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
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return maxAmount(n-1,nums,dp);
    }
};