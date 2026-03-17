class Solution {
public:
    int solve(int ind , int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(k == 0 && arr[ind] == 0) return 2;
            if(k == 0 || arr[ind] == k) return 1;
            return 0;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = solve(ind - 1 , k , arr , dp);
        int take = 0;
        if(arr[ind] <= k) take = solve(ind - 1 , k - arr[ind] , arr , dp);

        return dp[ind][k] = take + nottake;
    }

    int findTargetSumWays(vector<int>& arr, int tar) {
        int n = arr.size() , sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        int k = sum - tar;
        if(sum - tar < 0 || (sum - tar) % 2 != 0) return 0;
        else k = k / 2;

        // vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        // return solve(n - 1 , k , arr , dp);

        vector<vector<int>> dp(n , vector<int>(k + 1 , 0));

        for(int i=0 ; i<n ; i++){
            dp[i][0] = 1;
        }
        if(arr[0] == 0) dp[0][arr[0]] = 2;
        else if(arr[0] <= k) dp[0][arr[0]] = 1;

        for(int ind=1 ; ind<n ; ind++){
            for(int j=0 ; j<= k ; j++){
                int nottake = dp[ind - 1][j];
                int take = 0;
                if(arr[ind] <= j) take = dp[ind - 1][j - arr[ind]];

                dp[ind][j] = take + nottake;
            }
        }

        return dp[n - 1][k];
    }
};