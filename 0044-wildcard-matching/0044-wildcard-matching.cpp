class Solution {
public:
    bool solve(int i , int j , string p , string s , vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(i >= 0 && j < 0){ // bacha hua saara star hai agar s1 mein toh chalega as it can be empty;
            for(int k=0 ; k<=i ; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if( (p[i] == s[j]) || p[i] == '?' ) return dp[i][j] = solve(i - 1 , j - 1 , p , s , dp);
        else if(p[i] == '*') return dp[i][j] = solve(i, j - 1, p, s, dp) || solve(i - 1, j, p, s, dp);
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = p.size() , m = s.size();
        // vector<vector<int>> dp(n , vector<int>(m , -1));
        // return solve(n - 1 , m - 1 , p , s , dp);
        //TABULATION
        vector<vector<bool>> dp(n + 1 , vector<bool>(m + 1 , false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            bool chk = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*') {
                chk = false;
                break;
                }
            }
            dp[i][0] = chk;
        }

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if((p[i - 1] == s[j - 1]) || p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(p[i - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};