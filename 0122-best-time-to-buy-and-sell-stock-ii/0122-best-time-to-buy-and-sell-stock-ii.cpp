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
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return solve(0 , 1 , arr , dp);
    }
};