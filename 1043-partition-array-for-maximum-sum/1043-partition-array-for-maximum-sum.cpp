class Solution {
public:
    int sol(int ind , int k , vector<int>& arr , vector<int>& dp){
        if(ind == arr.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int maxi = arr[ind] , len = 0 , ans = -1e9;
        for(int i=ind ; i<min((int)arr.size() , ind + k) ; i++){
            len++;
            maxi = max(maxi , arr[i]);
            int sum = (len * maxi) + sol(i + 1 , k , arr , dp);
            ans = max(ans , sum);
        }

        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1 , 0);
        // return sol(0 , k , arr , dp);
        for(int i=n-1 ; i>=0 ; i--){
            int maxi = 0 , len = 0 , ans = 0;
            for(int j=i ; j<min(n , i + k) ; j++){
                len++;
                maxi = max(maxi , arr[j]);
                int sum = (len * maxi) + dp[j + 1];
                ans = max(ans , sum);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};