class Solution {
public:
    bool palin(int i , int j , string& s){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i , int n , string& arr , vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mini = 1e9;
        for(int j = i ; j < n ; j++){
            if(palin(i , j , arr)){
                int cost = 1 + solve(j + 1 , n , arr , dp);
                mini = min(mini , cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string arr) {
        int n = arr.size();
        // vector<int> dp(n , -1);
        // return solve(0 , n , arr , dp) - 1;
        vector<int> dp(n + 1 , 0);
        dp[n] = 0;
        for(int i = n-1 ; i>=0 ; i--){
            int mini = 1e9;
            for(int j = i ; j < n ; j++){
                if(palin(i , j , arr)){
                    int cost = 1 + dp[j + 1];
                    mini = min(mini , cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};