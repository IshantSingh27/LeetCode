class Solution {
public:
    bool solve(int ind , int k , vector<int> arr , vector<vector<int>>& dp){
        if(k == 0) return true;
        else if(ind == 0) return arr[0] == k;

        if(dp[ind][k] != -1) return dp[ind][k];

        int nottake = solve(ind - 1 , k , arr , dp);
        int take = false;
        if(arr[ind] <= k){
            take = solve(ind - 1 , k - arr[ind] , arr , dp);
        }

        return dp[ind][k] = take || nottake;
    }

    bool canPartition(vector<int>& arr) {
        int n = arr.size() , sum = 0 , tar = 0;
        for(int i=0 ; i<n ; i++){
            sum += arr[i];
        }

        if(sum % 2 != 0) return false;
        else{
            tar = sum / 2;
        }

        // vector<vector<int>> dp(n , vector<int>(tar + 1 , -1));

        // return solve(n - 1 , tar , arr , dp);

        vector<vector<int>> dp(n , vector<int>(tar + 1 , 0));

        for(int i=0 ; i<n ; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= tar) dp[0][arr[0]] = true;

        for(int ind=1 ; ind<n ; ind++){
            for(int k=1 ; k<=tar ; k++){
                int nottake = dp[ind - 1][k];
                int take = false;
                if(arr[ind] <= k) take = dp[ind - 1][k - arr[ind]];

                dp[ind][k] = take || nottake;
            }
        }

        return dp[n - 1][tar];
    }
};