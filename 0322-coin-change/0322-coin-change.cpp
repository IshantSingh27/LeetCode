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
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(amt + 1 ,-1));
        int ans = solve(n - 1 , amt , arr , dp);
        if(ans == 1e9) return -1;
        else return ans;
    }
};