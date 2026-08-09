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
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return sol(n - 1 , m - 1 , dp);
    }
};