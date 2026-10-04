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

        // vector<vector<int>> dp(n , vector<int>(k + 1 , -1));

        // return sol(n - 1 , k , arr , dp);

        // vector<vector<int>> dp(n + 1 , vector<int>(k + 1 , 0));

        // for(int i=0 ; i<=n ; i++){
        //     dp[i][0] = 1;
        // }

        vector<int> prev(k + 1 , 0) , cur(k + 1 , 0);
        prev[0] = 1;
        cur[0] = 1;

        for(int ind = 1 ; ind <= n ; ind++){
            for(int tar=1 ; tar<=k ; tar++){
                int nottake = prev[tar];
                int take = 0;
                if(arr[ind - 1] <= tar){
                    take = prev[tar - arr[ind - 1]];
                }

                cur[tar] = take || nottake;
            }
            prev = cur;
        }

        return prev[k];
    }
};