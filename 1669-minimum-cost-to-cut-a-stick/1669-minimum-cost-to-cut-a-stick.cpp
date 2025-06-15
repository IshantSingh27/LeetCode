class Solution {
public:
    int solve(int i , int j , vector<int>& arr , vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int ind = i ; ind <= j ; ind++){
            int cost = arr[j + 1] - arr[i - 1] + solve(i , ind - 1 , arr , dp) + solve(ind + 1 , j , arr , dp);
            mini = min(mini , cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& arr) {
        arr.push_back(n);
        arr.insert(arr.begin() , 0);
        sort(arr.begin() , arr.end());
        int m = arr.size();
        // vector<vector<int>> dp(m , vector<int>(m , -1));
        // return solve(1 , m - 2 , arr , dp);
        //TABULATION
        vector<vector<int>> dp(m , vector<int>(m , 0)); //base case 0 hi karna hai
        for(int i = m - 2 ; i > 0 ; i--){
            for(int j = 1 ; j <= m - 2 ; j++){ // obvio reverse se start hoga
            if(i > j) continue;
                int mini = 1e9;
                for(int ind = i ; ind <= j ; ind++){
                    int cost = arr[j + 1] - arr[i - 1] + dp[ind + 1][j] + dp[i][ind - 1];
                    mini = min(mini , cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m - 2];
    }
};