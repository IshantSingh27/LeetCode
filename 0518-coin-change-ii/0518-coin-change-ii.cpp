class Solution {
public:
    int solve(int ind , int tar , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            return (tar % arr[0] == 0);
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notTake = solve(ind - 1 , tar , arr, dp);
        int take = 0;
        if(arr[ind] <= tar){
            take = solve(ind , tar - arr[ind] , arr , dp);
        }
        return dp[ind][tar] = take + notTake;
    }
    // int change(int amt, vector<int>& arr) {
    //     int n = arr.size();
    //     vector<vector<int>> dp(n , vector<int>(amt + 1 , -1));
    //     return solve(n - 1 , amt , arr , dp);
    //     //TABULATION
    //     vector<vector<long long>> dp(n , vector<long long>(amt + 1 , 0));
    //     long long mod = 1e11 + 7;
    //     for(long long i=0 ; i <= amt ; i++){
    //         if(i % arr[0] == 0) dp[0][i] = 1;
    //     }
    //     for(long long ind = 1 ; ind < n ; ind++){
    //         for(long long tar = 0 ; tar <= amt ; tar++){
    //             long long notTake = dp[ind - 1][tar];
    //             long long take = 0;
    //             if(arr[ind] <= tar) take = dp[ind][tar - arr[ind]];
    //             dp[ind][tar] = (take + notTake) % mod;
    //         }
    //     }
    //     return dp[n - 1][amt];
    // }
    // SPACE OPT
    int change(int amt, vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(amt + 1 , 0) , cur(amt + 1 , 0);
        long long mod = 1e11 + 7;
        for(long long i=0 ; i <= amt ; i++){
            if(i % arr[0] == 0) prev[i] = 1;
        }
        for(long long ind = 1 ; ind < n ; ind++){
            for(long long tar = 0 ; tar <= amt ; tar++){
                long long notTake = prev[tar];
                long long take = 0;
                if(arr[ind] <= tar) take = cur[tar - arr[ind]];
                cur[tar] = (take + notTake) % mod;
            }
            prev = cur;
        }
        return prev[amt];
    }
};