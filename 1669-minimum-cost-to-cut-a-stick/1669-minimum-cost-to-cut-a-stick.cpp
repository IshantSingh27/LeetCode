class Solution {
public:
    int solve(int i , int j , vector<int>& arr , vector<vector<int>>& dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for(int ind = i ; ind <= j ; ind++){
            int cost = arr[j + 1] - arr[i - 1] + solve(i, ind - 1, arr, dp) + solve(ind + 1, j, arr, dp);
            mini = min(mini , cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& arr) {
        arr.insert(arr.begin() , 0);
        arr.push_back(n);
        sort(arr.begin() , arr.end());
        int sz = arr.size();
        // vector<vector<int>> dp(sz , vector<int>(sz , -1));
        // return solve(1 , sz - 2 , arr , dp);

        vector<vector<int>> dp(sz , vector<int>(sz , 0));

        for(int i = sz-2 ; i >= 1 ; i--){
            for(int j = i ; j <= sz-2 ; j++){
                int mini = 1e9;
                for(int ind = i ; ind <= j ; ind++){
                    int cost = arr[j + 1] - arr[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(cost , mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][sz - 2];
    }
};