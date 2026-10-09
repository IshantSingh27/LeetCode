class Solution {
public:
    int sol(int i , int j , string s1 , string s2 , vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = 1 + sol(i - 1 , j - 1 , s1 , s2 , dp);

        return dp[i][j] = max(sol(i , j - 1 , s1 , s2 , dp) , sol(i - 1 , j , s1 , s2 , dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size() , m = s2.size();

        // vector<vector<int>> dp(n , vector<int>(m , -1));

        // return sol(n - 1 , m - 1 , s1 , s2 , dp);

        // vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

        vector<int> cur(m + 1 , 0) , prev(m + 1 , 0);

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];

              else cur[j] = max(cur[j - 1] , prev[j]);
            }
            prev = cur;
        }

        return cur[m];
    }
};