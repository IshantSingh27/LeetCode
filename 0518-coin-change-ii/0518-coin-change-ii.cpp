class Solution {
public:
    int solve(int ind , int amt , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(amt % arr[0] == 0) return 1;
            else return 0;
        }

        if(dp[ind][amt] != -1) return dp[ind][amt];

        int notTake = solve(ind - 1 , amt , arr , dp);
        int take = 0;
        if(arr[ind] <= amt){
            take = solve(ind , amt - arr[ind] , arr , dp);
        }

        return dp[ind][amt] = take + notTake;
    }
    int change(int amt, vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(amt + 1 , -1));
        // return solve(n - 1 , amt , arr , dp);

        long long mod = 1e18 + 7;
        vector<vector<long long>> dp(n , vector<long long>(amt + 1 , 0));

        for(long long i=0 ; i<=amt ; i++){
            if(i % arr[0] == 0) dp[0][i] = 1;
        }

        for(long long ind=1 ; ind<n ; ind++){
            for(long long w=0 ; w<=amt ; w++){
                long long notTake = dp[ind - 1][w];
                long long take = 0;
                if(arr[ind] <= w) take = dp[ind][w - arr[ind]];

                dp[ind][w] = (take + notTake) % mod;
            }
        }

        return dp[n - 1][amt];
    }
};