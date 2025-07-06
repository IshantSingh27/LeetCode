class Solution {
public:
    int solve(int i , int j , string s1 , string s2 , vector<vector<int>>& dp){
        if(i < 0) return j + 1; // add remaining
        if(j < 0) return i + 1; // delete remaining
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 0 + solve(i-1 , j-1 , s1 , s2 , dp);
        else{
            int add = solve(i , j-1 , s1 , s2 , dp);
            int deletion = solve(i-1 , j , s1 , s2 , dp);
            int replace = solve(i-1 , j-1 , s1 , s2 , dp);
            return dp[i][j] = 1 + min(add , min(deletion , replace));
        }
    }
    int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        // vector<vector<int>> dp(n , vector<int>(m , -1));
        // return solve(n - 1 , m - 1 , s1 , s2 , dp);
        //TABULATION
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
        for(int i=1 ; i<=n ; i++) dp[i][0] = i; // add remaining
        for(int i=1 ; i<=m ; i++) dp[0][i] = i; // delete remaining
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = 0 + dp[i-1][j-1];
                else{
                    int add = dp[i][j - 1];
                    int deletion = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min(add , min(deletion , replace));
                }
            }
        }
        return dp[n][m];
    }
};