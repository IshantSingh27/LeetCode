class Solution {
public:
    int sol(int i , int j , vector<int>& arr , vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for(int k=i ; k<=j ; k++){
            int cost = arr[j + 1] - arr[i - 1] + sol(i , k - 1 , arr , dp) + sol(k + 1 , j , arr , dp);
            mini = min(mini , cost);
        }

        return dp[i][j] = mini;
    }
    int minCost(int sz, vector<int>& arr) {
        arr.push_back(0);
        arr.push_back(sz);
        sort(arr.begin() , arr.end());
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(n , -1));

        // return sol(1 , n - 2 , arr , dp);

        vector<vector<int>> dp(n , vector<int>(n , 0));

        for(int i=n-2 ; i>=1 ; i--){
            for(int j=i ; j<n-1 ; j++){
                int mini = 1e9;
                for(int k=i ; k<=j ; k++){
                    int cost = arr[j + 1] - arr[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini , cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n-2];
    }
};