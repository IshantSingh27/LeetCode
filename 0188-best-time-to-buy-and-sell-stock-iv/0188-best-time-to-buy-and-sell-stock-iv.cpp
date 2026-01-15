class Solution {
public:
    int solve(int ind , int buy , int k , vector<vector<vector<int>>>& dp , vector<int>& arr){
        if(ind == arr.size() || k == 0) return 0;

        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];

        if(buy){
            return dp[ind][buy][k] = 
            max(solve(ind + 1 , buy , k , dp , arr) , solve(ind + 1 , !buy , k , dp , arr) - arr[ind]);
        }
        else{
            return dp[ind][buy][k] =
            max(solve(ind + 1 ,buy ,k ,dp ,arr), solve(ind + 1, !buy, k - 1, dp, arr) + arr[ind]);
        }
    }

    int maxProfit(int k, vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(k + 1 , -1)));

        return solve(0 , 1 , k , dp , arr);
    }
};