class Solution {
public:
    int sol(int ind , int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(k == 0) return 1;
            else if(k % arr[ind] == 0) return 1;
            else return 0;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = sol(ind - 1 , k , arr , dp);
        int take = 0;
        if(arr[ind] <= k) take = sol(ind , k - arr[ind] , arr , dp);

        return dp[ind][k] = take + nottake;
    }
    int change(int k, vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        return sol(n - 1 , k , arr , dp);
    }
};