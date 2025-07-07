class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(2 , vector<int>(k + 1 , 0)));
        // for(int i=0 ; i<n ; i++){
        //     for(int j=0 ; j<=1 ; j++){
        //         dp[i][j][0] = 0;
        //     }
        // }
        // for(int i=0 ; i<=1 ; i++){
        //     for(int j=0 ; j<=k ; j++){
        //         dp[n][i][j] = 0;
        //     }
        // } // already zero
        for(int ind = n - 1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cap = 1 ; cap <= k ; cap++){
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
        return dp[0][1][k];
    }
};