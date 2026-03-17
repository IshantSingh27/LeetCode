class Solution {
public:
    int solve(int ind , int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(k == 0 || k % arr[0] == 0) return 1;
            return 0;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = solve(ind - 1 , k , arr , dp);
        int take = 0;
        if(arr[ind] <= k) take = solve(ind , k - arr[ind] , arr , dp);

        return dp[ind][k] = take + nottake;
    }

    int change(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        return solve(n - 1 , k , arr , dp);
    }
};