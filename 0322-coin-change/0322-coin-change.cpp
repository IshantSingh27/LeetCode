class Solution {
public:
    int solve(int ind , int tar , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(tar % arr[0] == 0) return tar / arr[0];
            else return 1e9;
        }

        if(dp[ind][tar] != -1) return dp[ind][tar];

        int notTake = 0 + solve(ind - 1 , tar , arr , dp);
        int take = 1e9;
        if(arr[ind] <= tar) take = 1 + solve(ind , tar - arr[ind] , arr , dp);

        return dp[ind][tar] = min(take , notTake);
    }
    int coinChange(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(k + 1 , -1));
        // if(solve(n - 1 , k , arr , dp) == 1e9) return -1;
        // else return solve(n - 1 , k , arr , dp);
        vector<vector<int>> dp(n , vector<int>(k + 1 , 0));
        for(int i=0 ; i <= k ; i++){
            if(i % arr[0] == 0) dp[0][i] = i / arr[0];
            else dp[0][i] = 1e9;
        }

        for(int ind = 1 ; ind < n ; ind++){
            for(int tar=0 ; tar<=k ; tar++){
                int notTake = 0 + dp[ind - 1][tar];
                int take = 1e9;
                if(arr[ind] <= tar){
                    take = 1 + dp[ind][tar - arr[ind]];
                }
                dp[ind][tar] = min(take , notTake);
            }
        }
        if(dp[n - 1][k] == 1e9) return -1;
        else return dp[n - 1][k];
    }
};