class Solution {
public:
    int solve(int ind , vector<int>& nums , vector<int>& dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + solve(ind - 2 , nums , dp);
        int notpick = solve(ind - 1 , nums , dp);
        return dp[ind] = max(pick , notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        // return solve(n - 1 , nums , dp);

        // dp[0] = nums[0];
        int prev = nums[0] , prev1 = 0;
        for(int i=1 ; i<n ; i++){
            // int pick = nums[i];
            int pick = nums[i] + prev1;
            // if(i > 1) pick += dp[i - 2];
            // int notpick = dp[i - 1];
            int notpick = prev;
            // dp[i] = max(pick , notpick);
            int cur = max(pick , notpick);
            prev1 = prev;
            prev = cur;
        }
        // return dp[n-1];
        return prev;
    }
};