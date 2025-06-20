class Solution {
public:
    int solve(int ind , int prev , vector<int>& arr , vector<vector<int>>& dp){
        if(ind== arr.size()) return 0;
        
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notTake = 0 + solve(ind + 1 , prev , arr , dp);
        int take = 0;
        if(prev == -1 || arr[ind] > arr[prev]){
            take = 1 + solve(ind + 1 , ind , arr , dp);
        }
        return dp[ind][prev + 1] = max(take , notTake);
    }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     // vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
    //     // return solve(0 , -1 , arr , dp);
    //     vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));
    //     for(int ind = n-1 ; ind >= 0 ; ind--){
    //         for(int prev = ind - 1 ; prev >= -1 ; prev--){
    //             int notTake = 0 + dp[ind + 1][prev + 1];
    //             int take = 0;
    //             if(prev == -1 || arr[ind] > arr[prev]){
    //                 take = 1 + dp[ind + 1][ind + 1];
    //             }
    //             dp[ind][prev + 1] = max(take , notTake);
    //         }
    //     }
    //     return dp[0][0];
    // }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n + 1 , 0);
        for(int ind = n-1 ; ind >= 0 ; ind--){
            vector<int> cur(n + 1 , 0);
            for(int prev = ind - 1 ; prev >= -1 ; prev--){
                int notTake = 0 + pre[prev + 1];
                int take = 0;
                if(prev == -1 || arr[ind] > arr[prev]){
                    take = 1 + pre[ind + 1];
                }
                cur[prev + 1] = max(take , notTake);
            }
            pre = cur;
        }
        return pre[0];
    }
};