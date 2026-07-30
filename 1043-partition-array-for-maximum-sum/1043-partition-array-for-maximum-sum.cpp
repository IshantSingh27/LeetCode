class Solution {
public:
    int sol(int ind , int k , vector<int>& arr , vector<int>& dp){
        if(ind == arr.size()) return 0;

        if(dp[ind] != -1) return dp[ind];

        int maxi = arr[ind] , len = 0 , ans = -1e9;
        for(int i=ind ; i < min((int)arr.size() , ind + k) ; i++){
            len++;
            maxi = max(maxi , arr[i]);
            int sum = (len * maxi) + sol(i + 1 , k , arr , dp);
            ans = max(ans , sum);
        }

        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n , -1);
        return sol(0 , k , arr , dp);
    }
};