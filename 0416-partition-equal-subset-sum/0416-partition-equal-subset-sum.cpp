class Solution {
public:
    int solve(int ind , int tar , vector<int>& arr , vector<vector<int>>& dp){
        if(tar == 0) return true;
        if(ind == 0) return arr[0] == tar;

        if(dp[ind][tar] != -1) return dp[ind][tar];

        bool notTake = solve(ind - 1 , tar , arr , dp);
        bool take = 0;
        if(arr[ind] <= tar){
            take = solve(ind - 1 , tar - arr[ind] , arr , dp);
        }

        return dp[ind][tar] = take || notTake;
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size() , sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        if(sum % 2 != 0) return false;
        vector<vector<int>> dp(n , vector<int>( (sum / 2) + 1 , -1 ));
        return solve(n - 1 , sum / 2 , arr , dp);
    }
};