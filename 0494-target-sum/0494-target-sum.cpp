class Solution {
public:
    int sol(int ind , int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(k == 0 && arr[0] == 0) return 2;
            else if(k == 0 || k == arr[ind]) return 1;
            else return 0;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = sol(ind - 1 , k , arr , dp);
        int take = 0;
        if(arr[ind] <= k) take = sol(ind - 1 , k - arr[ind] , arr , dp);

        return dp[ind][k] = take + nottake;
    }
       
    int findTargetSumWays(vector<int>& arr, int k) {
        int n = arr.size() , sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        int tar = sum - k;
        if(tar < 0 || tar % 2 == 1 || abs(k) > sum) return 0;
        else{
            tar = tar / 2;
        }

        vector<vector<int>> dp(n , vector<int>(tar + 1 , -1));

        return sol(n - 1 , tar , arr , dp);
    }
};