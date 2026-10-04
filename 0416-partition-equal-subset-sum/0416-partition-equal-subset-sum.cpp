class Solution {
public:
    bool sol(int ind ,int k , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(arr[ind] == k || k == 0) return true;
            else return false;
        }

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = sol(ind - 1 , k , arr , dp);
        int take = 0;
        if(arr[ind] <= k){
            take = sol(ind - 1 , k - arr[ind] , arr , dp);
        }

        return dp[ind][k] = take || nottake;
    }
    bool canPartition(vector<int>& arr) {
        int n = arr.size() , sum = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }
        if(sum % 2 == 1) return false;
        int k = sum / 2;

        vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        return sol(n - 1 , k , arr , dp);
    }
};