class Solution {
public:
    int solve(int ind , int buy , int cap , vector<int>& arr , vector<vector<vector<int>>>& dp){
        if(cap == 0) return 0;
        if(ind == arr.size()) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(solve(ind + 1 , 0 , cap , arr , dp) - arr[ind] ,
                        solve(ind + 1 , 1 , cap , arr , dp) - 0);
        }
        else{
            profit = max(solve(ind + 1 , 1 , cap - 1 , arr , dp) + arr[ind] ,
                        solve(ind + 1 , 0 , cap , arr , dp) + 0);
        }
        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        // return solve(0 , 1 , 2 , arr , dp);
        //TABULATION
        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(2 , vector<int>(3 , 0)));
        // for(int i=0 ; i<n ; i++){ // cap == 0 return 0
        //     for(int j=0 ; j<=1 ; j++){
        //         dp[i][j][0] = 0;
        //     }
        // } // all initialized with 0 so no use
        // for(int i=0 ; i<=1 ; i++){ // ind == 0 return 0
        //     for(int j=0 ; j<=2 ; j++){
        //         dp[n][i][j] = 0;
        //     }
        // }
        for(int ind = n - 1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cap = 1 ; cap <= 2 ; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(dp[ind + 1][0][cap] - arr[ind] , dp[ind + 1][1][cap] - 0);
                    }
                    else{
                        profit = max(dp[ind + 1][1][cap - 1] + arr[ind] , dp[ind + 1][0][cap] + 0);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};