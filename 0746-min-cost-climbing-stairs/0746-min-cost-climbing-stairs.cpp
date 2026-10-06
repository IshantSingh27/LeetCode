class Solution {
public:
    int sol(int ind , vector<int>& arr , vector<int>& dp){
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int one = arr[ind] + sol(ind - 1 , arr , dp);
        int two = arr[ind] + sol(ind - 2 , arr , dp);

        return dp[ind] = min(one , two);
    }
    int minCostClimbingStairs(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n , -1);

        return min(sol(n - 1 , arr , dp) , sol(n - 2 , arr , dp));
    }
};