class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& arr , vector<vector<int>>& dp){
        if(j < 0 || j > arr[0].size() - 1) return 1e9;
        if(i == 0) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up = arr[i][j] + solve(i - 1 , j , arr , dp);
        int left = arr[i][j] + solve(i - 1 , j - 1 , arr , dp);
        int right = arr[i][j] + solve(i - 1 , j + 1 , arr , dp);
        return min(up , min(left , right));
    }
    // int minFallingPathSum(vector<vector<int>>& arr) {
    //     int n = arr.size();
    //     int m = arr[0].size();
    //     vector<vector<int>> dp(n , vector<int>(m , -1));
    //     int mini = 1e9;
    //     for(int i=0 ; i<m ; i++){
    //         int cur = solve(n - 1 , i , arr , dp);
    //         mini = min(mini , cur);
    //     }
    //     return mini;
    //     //TABULATION
    //     for(int i=0 ; i<m ; i++){
    //         dp[0][i] = arr[0][i];
    //     }
    //     for(int i=1 ; i<n ; i++){
    //         for(int j=0 ; j<m ; j++){
    //             int left = 1e9;
    //             int right = 1e9;
    //             int up = arr[i][j] + dp[i - 1][j];
    //             if(j > 0) left = arr[i][j] + dp[i - 1][j - 1];
    //             if(j < m - 1) right = arr[i][j] + dp[i - 1][j + 1];
    //             dp[i][j] = min(up , min(left , right));
    //         }
    //     }
    //     int mini = 1e9;
    //     for(int i=0 ; i<m ; i++){
    //         mini = min(mini , dp[n - 1][i]);
    //     }
    //     return mini;
    // }
    //SPACE OPTIMISATION
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> prev(n);
        for(int i=0 ; i<m ; i++){
            prev[i] = arr[0][i];
        }
        for(int i=1 ; i<n ; i++){
            vector<int> temp(n);
            for(int j=0 ; j<m ; j++){
                int left = 1e9;
                int right = 1e9;
                int up = arr[i][j] + prev[j];
                if(j > 0) left = arr[i][j] + prev[j - 1];
                if(j < m - 1) right = arr[i][j] + prev[j + 1];
                temp[j] = min(up , min(left , right));
            }
            prev = temp;
        }
        int mini = 1e9;
        for(int i=0 ; i<m ; i++){
            mini = min(mini , prev[i]);
        }
        return mini;
    }
};