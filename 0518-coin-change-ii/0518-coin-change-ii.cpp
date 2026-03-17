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

    vector<vector<long long>> dp(n , vector<long long>(k + 1 , 0));

    if(arr[0] == 0){
        dp[0][0] = 2;
    } else {
        dp[0][0] = 1;
        for(int i = 1; i <= k; i++){
            if(i % arr[0] == 0) dp[0][i] = 1;
        }
    }

    const int MOD = 1e18 + 7;

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= k ; j++){

            long long nottake = dp[i - 1][j];

            long long take = 0;
            if(arr[i] <= j)
                take = dp[i][j - arr[i]];

            dp[i][j] = (take + nottake) % MOD;
        }
    }

    return dp[n - 1][k];
}
};