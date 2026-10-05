class Solution {
public:
    int sol(int ind , int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(k % arr[ind] == 0) return k / arr[ind];
            else return 1e9;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = sol(ind - 1 , k , arr , dp);
        int take = 1e9;
        if(arr[ind] <= k) take = 1 + sol(ind , k - arr[ind] , arr , dp);

        return dp[ind][k] = min(take , nottake);
    }
    int coinChange(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        // int ans = sol(n - 1 , k , arr , dp);
        // if(ans == 1e9) return -1;
        // else return ans;

        // vector<vector<int>> dp(n + 1 , vector<int>(k + 1 , 1e9));

        vector<int> prev(k + 1 , 1e9) , cur(k + 1 , 1e9);
        prev[0] = 0;
        cur[0] = 0;
        for(int i=1 ; i<=k ; i++){
            if(i % arr[0] == 0) prev[i] = i / arr[0];
        }

        for(int i=1 ; i<=n ; i++){
            for(int j=0 ; j<=k ; j++){
                int nottake = prev[j];
                int take = 1e9;
                if(arr[i - 1] <= j) take = 1 + cur[j - arr[i - 1]];

                cur[j] = min(take , nottake);
            }
            prev = cur;
        }

        if(cur[k] == 1e9) return -1;
        else return cur[k];
    }
};