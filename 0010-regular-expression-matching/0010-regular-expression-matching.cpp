class Solution {
public:
    bool sol(int i, int j, string s, string p, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0) {
            while (j >= 0) {
                if (p[j] != '*')
                    return false;
                j -= 2;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '.') {
            if (sol(i - 1, j - 1, s, p, dp))
                return dp[i][j] = true;
        } else if (p[j] == '*') {
            bool zero = sol(i, j - 2, s, p, dp);
            bool one = false;
            if (p[j - 1] == '.' || p[j - 1] == s[i]) {
                one = sol(i - 1, j, s, p, dp);
            }
            return dp[i][j] = one || zero;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // vector<vector<int>> dp(n , vector<int>(m , -1));

        // return sol(n - 1 , m - 1 , s , p , dp);

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        vector<int> prev(m + 1 , 0);

        prev[0] = true;
        for (int j = 2; j <= m; j += 2) {
            if (p[j - 1] == '*') {
                prev[j] = prev[j - 2];
            }
        }

        for (int i = 1; i <= n; i++) {
            vector<int> cur(m + 1 , 0);
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    if (prev[j - 1])
                        cur[j] = true;
                } else if (p[j - 1] == '*') {
                    bool zero = cur[j - 2];
                    bool one = false;
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        one = prev[j];
                    }
                    cur[j] = one || zero;
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};