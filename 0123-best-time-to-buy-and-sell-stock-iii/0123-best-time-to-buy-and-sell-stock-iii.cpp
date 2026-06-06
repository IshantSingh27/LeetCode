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
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        return sol(0 , 1 , 2 , arr , dp);
    }
};