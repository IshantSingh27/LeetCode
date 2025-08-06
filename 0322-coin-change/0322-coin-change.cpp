class Solution {
public:
    int solve(int ind , int amt , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(amt % arr[0] == 0) return amt / arr[0];
            else return 1e9;
        }

        if(dp[ind][amt] != -1) return dp[ind][amt];

        int notTake = 0 + solve(ind - 1 , amt , arr , dp);
        int take = 1e9;
        if(arr[ind] <= amt){
            take = 1 + solve(ind , amt - arr[ind] , arr , dp);
        }

        return dp[ind][amt] = min(take , notTake);
    }
    int coinChange(vector<int>& arr, int amt) {
        if(amt == 0) return 0;
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(amt + 1 ,-1));
        // int ans = solve(n - 1 , amt , arr , dp);
        // if(ans == 1e9) return -1;
        // else return ans;

        vector<vector<int>> dp(n , vector<int>(amt + 1 , 1e9));

        for(int i=0 ; i<=amt ; i++){
            if(i % arr[0] == 0) dp[0][i] = i / arr[0];
        }

        for(int ind=1 ; ind<n ; ind++){
            for(int w=0 ; w<=amt ; w++){
                int notTake = 0 + dp[ind - 1][w];
                int take = 1e9;
                if(arr[ind] <= w){
                    take = 1 + dp[ind][w - arr[ind]];
                }

                dp[ind][w] = min(take , notTake);
            }
        }

        if(dp[n - 1][amt] == 1e9) return -1;
        else return dp[n - 1][amt];
    }
};