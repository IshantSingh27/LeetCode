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
    int minCost(int n, vector<int>& arr) {
        arr.push_back(0);
        arr.push_back(n);
        sort(arr.begin() , arr.end());
        int sz = arr.size();
        vector<vector<int>> dp(sz , vector<int>(sz , -1));

        return sol(1 , sz - 2 , arr , dp);
    }
};