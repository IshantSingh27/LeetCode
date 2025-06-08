class Solution {
public:
    // int solve(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
    //     if(i == 0 && j == 0) return grid[0][0];
    //     if(i < 0 || j < 0) return 1e9;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = grid[i][j] + solve(i - 1 , j , grid , dp);
    //     int left = grid[i][j] + solve(i , j - 1 , grid , dp);
    //     return dp[i][j] = min(left , up);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     return solve(n - 1 , m - 1 , grid , dp);
    //     //TABULATION
    //     for(int i=0 ; i<n ; i++){
    //         for(int j=0 ; j<m ; j++){
    //             if(i == 0 && j == 0) dp[0][0] = grid[0][0];
    //             else{
    //                 int up = 1e9;
    //                 int left = 1e9;
    //                 if(i > 0) up = grid[i][j] + dp[i - 1][j];
    //                 if(j > 0) left = grid[i][j] + dp[i][j-1];
    //                 dp[i][j] = min(up , left);
    //             }
    //         }
    //     }
    //     return dp[n - 1][m - 1];
    // }
    //SPACE OPTIMISATION
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m);
        for(int i=0 ; i<n ; i++){
            vector<int> temp(m);
            for(int j=0 ; j<m ; j++){
                if(i == 0 && j == 0) temp[0] = grid[0][0];
                else{
                    int up = 1e9;
                    int left = 1e9;
                    if(i > 0) up = grid[i][j] + prev[j];
                    if(j > 0) left = grid[i][j] + temp[j-1];
                    temp[j] = min(up , left);
                }
            }
            prev = temp;
        }
        return prev[m-1];
    }
};