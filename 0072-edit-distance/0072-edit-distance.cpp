class Solution {
public:
    int solve(int i , int j , string s1 , string s2 , vector<vector<int>>& dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return dp[i][j] = solve(i - 1 , j - 1 , s1 , s2 , dp);

        int del = solve(i - 1 , j , s1 , s2 , dp);
        int ins = solve(i , j - 1 , s1 , s2 , dp);
        int rep = solve(i - 1 , j - 1 , s1 , s2 , dp);

        return dp[i][j] = 1 + min(del , min(rep , ins));
    }
    // int minDistance(string s1, string s2) {
    //     int n = s1.size() , m = s2.size();
    //     // vector<vector<int>> dp(n , vector<int>(m , -1));
    //     // return solve(n - 1 , m - 1 , s1 , s2 , dp);

    //     vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

    //     for(int i=0 ; i<= n ; i++) dp[i][0] = i;
    //     for(int i=0 ; i<= m ; i++) dp[0][i] = i; //ariving in reverse only going bottom up

    //     for(int i=1 ; i<=n ; i++){
    //         for(int j=1 ; j<=m ; j++){
    //             if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];

    //             else{
    //                 int del = dp[i - 1][j];
    //                 int ins = dp[i][j - 1];
    //                 int rep = dp[i - 1][j - 1];

    //                 dp[i][j] = 1 + min(del , min(rep , ins));
    //             }
    //         }
    //     }

    //     return dp[n][m];
    // }
    int minDistance(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        
        vector<int> prev(m + 1 , 0) , cur(m + 1 , 0);

        for(int i=0 ; i<= m ; i++) prev[i] = i; //ariving in reverse only going bottom up

        for(int i=1 ; i<=n ; i++){
            cur[0] = i;
            for(int j=1 ; j<=m ; j++){
                if(s1[i - 1] == s2[j - 1]) cur[j] = prev[j - 1];

                else{
                    int del = prev[j];
                    int ins = cur[j - 1];
                    int rep = prev[j - 1];

                    cur[j] = 1 + min(del , min(rep , ins));
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};