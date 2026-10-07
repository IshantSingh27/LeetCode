class Solution {
public:
    long long mod = 1e18;
    int sol(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return 1;
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int move = 0;
        if (s[i] == t[j])
            move = sol(i - 1, j - 1, s, t, dp);
        int skip = sol(i - 1, j, s, t, dp);

        return dp[i][j] = skip + move;
    }
    int numDistinct(string s, string t) {
        long long n = s.size(), m = t.size();
        // vector<vector<long long>> dp(n , vector<long long>(m , -1));

        // return sol(n - 1 , m - 1 , s , t , dp);

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        dp[0][0] = 1;
        for (long long i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (long long i = 1; i <= n; i++) {
            for (long long j = 1; j <= m; j++) {
                long long move = 0;
                if (s[i - 1] == t[j - 1])
                    move = dp[i - 1][j - 1];
                long long skip = dp[i - 1][j];

                dp[i][j] = (skip + move) % mod;
            }
        }

        return dp[n][m];
    }
};