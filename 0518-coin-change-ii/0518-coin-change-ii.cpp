class Solution {
public:
    int solve(int ind , int amt , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(amt % arr[0] == 0) return 1;
            else return 0;
        }

        if(dp[ind][amt] != -1) return dp[ind][amt];

        int notTake = solve(ind - 1 , amt , arr , dp);
        int take = 0;
        if(arr[ind] <= amt){
            take = solve(ind , amt - arr[ind] , arr , dp);
        }

        return dp[ind][amt] = take + notTake;
    }
    int change(int amt, vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(amt + 1 , -1));
        return solve(n - 1 , amt , arr , dp);
    }
};