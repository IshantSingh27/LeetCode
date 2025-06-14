class Solution {
public:
    // int solve(int i , int j , string s1, string s2 , vector<vector<int>>& dp){
    //     if(i < 0 || j < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s1[i] == s2[j]) return 1 + solve(i - 1 , j - 1 , s1 , s2 , dp);
    //     int left = solve(i - 1 , j , s1 , s2 , dp);
    //     int right = solve(i , j - 1 , s1 , s2 , dp);
    //     return dp[i][j] = max(left , right);
    // }
    // int longestCommonSubsequence(string s1, string s2) {
    //     int n = s1.size() , m = s2.size();
    //     // vector<vector<int>> dp(n , vector<int>(m , -1));
    //     // return solve(n - 1 , m - 1 , s1 , s2 , dp);
    //     //TABULATION
    //     vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
    //     for(int i=0 ; i<=n ; i++) dp[i][0] = 0; // base case
    //     for(int j=0 ; j<=m ; j++) dp[0][j] = 0; // rather of no use
    //     for(int i=1 ; i<=n ; i++){
    //         for(int j=1 ; j<=m ; j++){ //i - 1 , j - 1 for index shift
    //             if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
    //             else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
    //         }
    //     }
    //     return dp[n][m];
    // }
    //SPACE OPT
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        vector<int> prev(m + 1) , cur(m + 1 , 0);
        for(int i=0 ; i<=m ; i++) prev[i] = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){ //i - 1 , j - 1 for index shift
                if(s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
                else cur[j] = max(prev[j] , cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};