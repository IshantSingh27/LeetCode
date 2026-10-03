class Solution {
public:
    long long sol(long long n , vector<long long>& dp){
        if(n <= 0) return 1;

        if(dp[n] != -1) return dp[n];

        long long one = sol(n - 1 , dp);
        long long two = 0;
        if(n >= 2) two = sol(n - 2 , dp);

        return dp[n] = one + two;
    }
    int climbStairs(int n) {
        // vector<long long> dp(n + 1 , -1);
        // return sol(n , dp);

        // vector<long long> dp(n + 1 , 0);
        // dp[0] = 1;

        int pre1 = 1 , pre2 = 1;

        for(long long i=1 ; i<=n ; i++){
            long long one = pre1;
            long long two = 0;
            if(i >= 2){
                two = pre2;
            }

            pre2 = pre1;

            pre1 = one + two;
        }

        return pre1;
    }
};