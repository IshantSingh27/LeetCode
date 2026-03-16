class Solution {
public:
    int solve(int ind , int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(k % arr[0] == 0) return k / arr[0];
            else return 1e9;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = solve(ind - 1 , k , arr , dp);
        int take = 1e9;
        if(arr[ind] <= k) take = 1 + solve(ind , k - arr[ind] , arr , dp);

        return dp[ind][k] = min(take , nottake);
    }

    int coinChange(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        // int ans = solve(n - 1 , k , arr , dp);
        // if(ans >= 1e9) return -1;
        // else return ans;

        vector<vector<int>> dp(n , vector<int>(k + 1 , 1e9));

        for(int i=0 ; i<=k ; i++){
            if(i % arr[0] == 0) dp[0][i] = i / arr[0];
        }

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=k ; j++){
                int nottake = dp[i - 1][j];
                int take = 1e9;
                if(arr[i] <= j) take = 1 + dp[i][j - arr[i]];

                dp[i][j] = min(take , nottake);
            }
        }

        int ans = dp[n - 1][k];
        if(ans >= 1e9) return -1;
        else return ans;
    }
};