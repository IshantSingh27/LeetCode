class Solution {
public:
    int sol(int ind , int buy , int k , vector<int>& arr , vector<vector<vector<int>>>& dp){
        if(ind == arr.size() || k == 0) return 0;

        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];

        int profit = 0;
        if(buy){
            profit =  max(sol(ind + 1 , buy , k ,  arr , dp) , sol(ind + 1 , 0 , k , arr , dp) - arr[ind]);
        }
        else{
            profit = max(sol(ind , 1 , k - 1 , arr , dp) + arr[ind] , sol(ind + 1 , buy , k , arr , dp));
        }

        return dp[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        // vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(k + 1 , -1)));
        // return sol(0 , 1 , k , arr , dp);

        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>>(2 , vector<int>(k + 1 , 0)));

        for(int i=n-1 ; i>=0 ; i--){
            for(int j=0 ; j<2 ; j++){
                for(int cap=k ; cap>0 ; cap--){
                    int profit = 0;
                    if(j){
                        profit = max(dp[i + 1][j][cap] , dp[i + 1][0][cap] - arr[i]);
                    }
                    else profit = max(dp[i + 1][j][cap] , dp[i + 1][1][cap - 1] + arr[i]);
                    dp[i][j][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};