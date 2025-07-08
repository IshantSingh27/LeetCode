class Solution {
public:
    int solve(int i , int j , vector<int>& arr , vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxi = -1e9;
        for(int k = i ; k <= j ; k++){
            int coin = (arr[i - 1] * arr[k] * arr[j + 1]) + solve(i , k - 1 , arr , dp) +
                                                      solve(k + 1 , j , arr , dp);
            maxi = max(maxi , coin);
        }

        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& arr) {
        arr.insert(arr.begin() , 1);
        arr.push_back(1);
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(n , -1));
        // return solve(1 , n - 2 , arr , dp);

        vector<vector<int>> dp(n , vector<int>(n , 0));

        for(int i = n-2 ; i >= 1 ; i--){
            for(int j = i ; j <= n-2 ; j++){
                int maxi = -1e9;
                for(int k = i ; k <= j ; k++){
                    int coin = (arr[i - 1] * arr[k] * arr[j + 1]) + dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi , coin);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 2];
    }
};