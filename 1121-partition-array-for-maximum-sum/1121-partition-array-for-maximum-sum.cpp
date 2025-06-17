class Solution {
public:
    int solve(int i , int n , vector<int>& arr , vector<int>& dp , int k){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxcur = -1e9 , maxans = -1e9 , len = 0;
        for(int j = i ; j < min(i + k , n) ; j++){
            len++;
            maxcur = max(maxcur , arr[j]);
            int sum = (maxcur * len) + solve(j + 1 , n , arr , dp , k);
            maxans = max(maxans , sum);
        }
        return dp[i] = maxans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // vector<int> dp(n , -1);
        // return solve(0 , n , arr , dp , k);
        //TABULATION
        vector<int> dp(n + 1 , 0);
        for(int i = n-1 ; i >= 0 ; i--){
            int maxcur = -1e9 , maxans = -1e9 , len = 0;
            for(int j=i ; j < min(i + k , n) ; j++){
                len++;
                maxcur = max(maxcur , arr[j]);
                int sum = (len * maxcur) + dp[j + 1];
                maxans = max(maxans , sum);
            }
            dp[i] = maxans;
        }
        return dp[0];
    }
};