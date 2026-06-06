class Solution {
public:
    int sol(int ind , int buy , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == arr.size()){
            return 0;
        }

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit =  max(sol(ind + 1 , buy , arr , dp) , sol(ind + 1 , 0 , arr , dp) - arr[ind]);
        }
        else{
            profit = max(sol(ind , 1 , arr , dp) + arr[ind] , sol(ind + 1 , buy , arr , dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(2 , -1));
        // return sol(0 , 1 , arr , dp);

        vector<vector<int>> dp(n + 1 , vector<int>(2 , 0));

        for(int i=n-1 ; i>=0 ; i--){
            for(int j=0 ; j<2 ; j++){
                int profit = 0;
                if(j){
                    profit = max(dp[i + 1][j] , dp[i + 1][0] - arr[i]);
                }
                else profit = max(dp[i + 1][j] , dp[i + 1][1] + arr[i]);
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};