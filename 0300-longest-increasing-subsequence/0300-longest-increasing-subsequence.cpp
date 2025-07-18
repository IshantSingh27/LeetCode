class Solution {
public:
    int solve(int ind , int prev , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == arr.size()) return 0;

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
    //         for(int prev = ind-1 ; prev >= -1 ; prev--){
    //             int notTake = 0 + dp[ind + 1][prev + 1];
    //             int take = 0;
    //             if(prev == -1 || arr[prev] < arr[ind]){
    //                 take = 1 + dp[ind + 1][ind + 1];
    //             }
    //             dp[ind][prev + 1] = max(take , notTake);
    //         }
    //     }
    //     return dp[0][0];
    // }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();

    //     vector<int> next(n + 1 , 0) , cur(n + 1 , 0);

    //     for(int ind = n-1 ; ind >= 0 ; ind--){
    //         for(int prev = ind-1 ; prev >= -1 ; prev--){
    //             int notTake = 0 + next[prev + 1];
    //             int take = 0;
    //             if(prev == -1 || arr[prev] < arr[ind]){
    //                 take = 1 + next[ind + 1];
    //             }
    //             cur[prev + 1] = max(take , notTake);
    //         }
    //         next = cur;
    //     }
    //     return next[0];
    // }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size() , ans = 1;

        vector<int> dp(n , 1);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[j] < arr[i]){
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};