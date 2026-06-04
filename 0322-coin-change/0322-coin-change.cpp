class Solution {
public:
    int sol(int ind , int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(k == 0) return 0;
            if(k % arr[ind] == 0) return k / arr[ind];
            else return 1e8;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = sol(ind - 1 , k , arr , dp);
        int take = 1e8;
        if(arr[ind] <= k){
            take = 1 + sol(ind , k - arr[ind] , arr , dp);
        }

        return dp[ind][k] = min(take , nottake);
    }
    int coinChange(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(k + 1 , -1));
        // int ans = sol(n - 1 , k , arr , dp);
        // if(ans == 1e8) return -1;
        // else return ans;
        vector<vector<int>> dp(n , vector<int>(k + 1 , 1e5));
        for(int i=0 ; i<n ; i++){
            dp[i][0] = 0;
        }
        for(int i=1 ; i<=k ; i++){
            if(i % arr[0] == 0) dp[0][i] = i / arr[0]; 
        }

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<=k ; j++){
                int nottake = dp[i - 1][j];
                int take = 1e8;
                if(arr[i] <= j){
                    take = 1 + dp[i][j - arr[i]];
                }

                dp[i][j] = min(take , nottake);
            }
        }

        if(dp[n - 1][k] == 1e5) return -1;
        else return dp[n - 1][k];
    }
};