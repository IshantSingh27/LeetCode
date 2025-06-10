class Solution {
public:
    int solve(int ind , int tar , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(tar % arr[0] == 0) return tar / arr[0];
            else return 1e9;
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notTake = 0 + solve(ind - 1 , tar , arr , dp);
        int take = 1e9;
        if(arr[ind] <= tar){
            take = 1 + solve(ind , tar - arr[ind] , arr , dp);
        }
        return dp[ind][tar] = min(take , notTake);
    }
    int coinChange(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(tar + 1 , -1));
        int ans = solve(n - 1 , tar , arr , dp);
        if(ans == 1e9) return -1;
        else return ans;
    }
};