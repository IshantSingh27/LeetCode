class Solution {
public:
    int solve(int ind , int buy , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == arr.size()) return 0; // if buy and never sell then profit in -ve. So, not considered.
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(solve(ind + 1, 0, arr, dp) - arr[ind] , solve(ind + 1, 1, arr, dp) - 0);
        }
        else profit = max(solve(ind + 1, 1, arr, dp) + arr[ind] , solve(ind + 1, 0, arr, dp) + 0);
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(2 , -1));
        // return solve(0 , 1 , arr , dp);
        //TABULATION
        vector<vector<int>> dp(n + 1 , vector<int>(2 , 0));
        //Base case: dp[n][0] = 0 , dp[n][1] = 0; i.e at last buy or not sell you get 0;
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                int profit = 0;
                if(buy){
                    profit = max(dp[ind + 1][0] - arr[ind] , dp[ind + 1][1] - 0);
                }
                else profit = max(dp[ind + 1][1] + arr[ind] , dp[ind + 1][0] + 0);
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};