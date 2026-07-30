class Solution {
public:
    int sol(int ind , int k , vector<int>& arr , vector<int>& dp){
        if(ind == arr.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int len = 0 , maxi = 0 , ans = 0;
        for(int i=ind ; i<min(ind + k , (int)arr.size()) ; i++){
            len++;
            maxi = max(maxi , arr[i]);
            int cost = (len * maxi) + sol(i + 1 , k , arr , dp);
            ans = max(ans , cost);
        }

        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1 , 0);
        // return sol(0 , k , arr , dp);

        for(int i=n-1 ; i>=0 ; i--){
            int len = 0 , maxi = 0 , ans = 0;
            for(int j=i ; j<min(n , i + k) ; j++){
                len++;
                maxi = max(maxi , arr[j]);
                int cost = (len * maxi) + dp[j + 1];
                ans = max(ans , cost);
            }
            dp[i] = ans;
        }

        return dp[0];
    }
};