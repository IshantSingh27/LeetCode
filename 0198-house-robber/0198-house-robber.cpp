class Solution {
public:
int sol(int ind , bool can , vector<int>& arr , vector<vector<int>>& dp){
        if(ind == 0){
            if(can) return arr[ind];
            else return 0;
        }
        
        if(dp[ind][can] != -1) return dp[ind][can];
        
        int nottake = sol(ind - 1 , true , arr , dp);
        
        int take = 0;
        if(can) take = arr[ind] + sol(ind - 1 , false , arr , dp);
        
        return dp[ind][can] = max(take , nottake);
    }
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(2, -1));
        
        return sol(n - 1 , true , arr , dp);
    }
};