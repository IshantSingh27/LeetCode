class Solution {
public:
    int solve(int row , int col , vector<vector<int>>& dp , vector<vector<int>>& arr){
        if(row == 0 && col == 0) return arr[0][0];
        if(row < 0 || col < 0) return 1e9;

        if(dp[row][col] != -1) return dp[row][col];

        int up = solve(row - 1 , col , dp , arr) + arr[row][col];
        int down = solve(row , col - 1 , dp , arr) + arr[row][col];

        return dp[row][col] = min(up , down);
    }

    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size() , m = arr[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));

        return solve(n - 1 , m - 1 , dp , arr);
    }
};