class Solution {
public:
    int solve(int ind , int prev , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == arr.size()) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notTake = 0 + solve(ind + 1 , prev , arr , dp);
        int take = 0;
        if(prev == -1 || arr[ind] > arr[prev]){
            take = 1 + solve(ind + 1 , ind , arr , dp);
        }
        return dp[ind][prev + 1] = max(take , notTake);
    }

    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
        return solve(0 , -1 , arr , dp);
    }
};