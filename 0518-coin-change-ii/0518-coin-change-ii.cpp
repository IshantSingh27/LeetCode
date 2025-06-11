class Solution {
public:
    int solve(int ind , int tar , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            return (tar % arr[0] == 0);
        }
        if(dp[ind][tar] != -1) return dp[ind][tar];
        int notTake = solve(ind - 1 , tar , arr, dp);
        int take = 0;
        if(arr[ind] <= tar){
            take = solve(ind , tar - arr[ind] , arr , dp);
        }
        return dp[ind][tar] = take + notTake;
    }
    int change(int amt, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(amt + 1 , -1));
        return solve(n - 1 , amt , arr , dp); 
    }
};