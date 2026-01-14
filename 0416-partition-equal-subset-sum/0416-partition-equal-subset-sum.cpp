class Solution {
public:
    bool solve(int ind , int k , vector<vector<int>>& dp , vector<int>& arr){
        if(ind == 0){
            if(arr[0] == k) return true;
            else return false;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        bool nottake = solve(ind - 1 , k , dp , arr);
        bool take = false;
        if(arr[ind] <= k) take = solve(ind - 1 , k - arr[ind] , dp , arr);

        return dp[ind][k] = take || nottake; 
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size() , sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        if(sum % 2 == 1) return false;
        int k = sum / 2;

        // vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        // return solve(n - 1 , k , dp ,  arr);

        vector<vector<bool>> dp(n + 1 , vector<bool>(k + 1 , false));
        for(int i=0 ; i<=n ; i++){
            dp[i][0] = true;
        }

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=k ; j++){
                bool nottake = dp[i - 1][j];
                bool take = false;
                if(arr[i - 1] <= j) take = dp[i - 1][j - arr[i - 1]];

                dp[i][j] = take || nottake;
            }
        }

        return dp[n][k];
    }
};