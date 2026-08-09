class Solution {
public:
    int sol(int i , int j , vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int up = 0 , left = 0;
        if(i - 1 >= 0) up = sol(i - 1 , j , dp);
        if(j - 1 >= 0) left = sol(i , j - 1 , dp);

        return dp[i][j] = up + left;
    }
    int uniquePaths(int n, int m) {
        // vector<vector<int>> dp(n , vector<int>(m , -1));
        // return sol(n - 1 , m - 1 , dp);

        // vector<vector<int>> dp(n , vector<int>(m , 0));
        vector<int> prev(m , 0) , cur(m , 0);

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(i == 0 && j == 0){
                    cur[0] = 1;
                    continue;
                }
                int up = 0 , left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = cur[j - 1];

                cur[j] = up + left;
            }
            prev = cur;
        }

        return cur[m - 1];
    }
};