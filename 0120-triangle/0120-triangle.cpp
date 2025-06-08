class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& arr , vector<vector<int>>& dp , int n){
        if(i == n - 1) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = arr[i][j] + solve(i + 1 , j , arr , dp , n);
        int diag = arr[i][j] + solve(i + 1 , j + 1 , arr , dp , n);
        return dp[i][j] = min(down , diag);
    }

    // int minimumTotal(vector<vector<int>>& arr) {
    //     int r = arr.size();
    //     int n = arr[r - 1].size();
    //     vector<vector<int>> dp(r , vector<int>(r , -1));
    //     // return solve(0 , 0 , arr , dp , r);
    //     // TABULATION
    //     for(int i=0 ; i<n ; i++) dp[r-1][i] = arr[r-1][i];
    //     for(int i=r-2 ; i >= 0 ; i--){
    //         for(int j=i ; j >= 0 ; j--){
    //             int down = arr[i][j] + dp[i+1][j];
    //             int diag = arr[i][j] + dp[i+1][j+1];
    //             dp[i][j] = min(down , diag);
    //         }
    //     }
    //     return dp[0][0];
    // }
    int minimumTotal(vector<vector<int>>& arr) {
        int r = arr.size();
        int n = arr[r - 1].size();
        vector<int> prev(n);
        for(int i=0 ; i<n ; i++) prev[i] = arr[r-1][i];
        for(int i=r-2 ; i >= 0 ; i--){
            vector<int> temp(n);
            for(int j=i ; j >= 0 ; j--){
                int down = arr[i][j] + prev[j];
                int diag = arr[i][j] + prev[j+1];
                temp[j] = min(down , diag);
            }
            prev = temp;
        }
        return prev[0];
    }
};