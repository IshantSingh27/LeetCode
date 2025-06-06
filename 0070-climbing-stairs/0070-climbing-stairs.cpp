class Solution {
public:
    int climb(int ind , int n , vector<int>& dp){
        if(ind == n) return 1;
        if(ind > n) return 0;
        
        if(dp[ind] != -1) return dp[ind];

        int one = climb(ind + 1 , n , dp);
        int two = climb(ind + 2 , n , dp);

        return dp[ind] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1 , -1);
        // int ans = climb(0 , n , dp);
        // return ans;

        dp[n] = 1; dp[n-1] = 1;
        int prev = 1 , prev1 = 1;
        for(int i=n-2 ; i>=0 ; i--){
            // dp[i] = dp[i+1] + dp[i+2];
            dp[i] = prev + prev1;
            prev1 = prev;
            prev = dp[i];
        }
        return prev;
    }
};