class Solution {
public:
    int sol(int ind , int buy , vector<int>& arr , vector<vector<int>>& dp){
        if(ind >= arr.size()){
            return 0;
        }

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit =  max(sol(ind + 1 , buy , arr , dp) , sol(ind + 1 , 0 , arr , dp) - arr[ind]);
        }
        else{
            profit = max(sol(ind + 2 , 1 , arr , dp) + arr[ind] , sol(ind + 1 , buy , arr , dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return sol(0 , 1 , arr , dp);
    }
};