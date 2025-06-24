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
        // vector<vector<int>> dp(n , vector<int>( (sum / 2) + 1 , -1 ));
        // return solve(n - 1 , sum / 2 , arr , dp);
        int k = sum / 2;
        vector<int> prev(k + 1 , false) , cur(k + 1 , false);
        prev[0] = false ; cur[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int ind = 1 ; ind < n ; ind++){
            for(int tar = 1 ; tar <= k ; tar++){
                bool notTake = prev[tar];
                bool take = 0;
                if(arr[ind] <= tar){
                    take = prev[tar - arr[ind]];
                }
        
                cur[tar] = take || notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
};