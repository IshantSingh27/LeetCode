class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size() , maxi = 0;
        vector<int> dp(n , 1) , cnt(n , 1);
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if(arr[ind] > arr[prev] && dp[ind] < dp[prev] + 1){
                    dp[ind] = dp[prev] + 1;
                    cnt[ind] = cnt[prev];
                }
                else if(arr[ind] > arr[prev] && dp[ind] == dp[prev] + 1){
                    cnt[ind] += cnt[prev];
                }
            }
            maxi = max(dp[ind] , maxi);
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(dp[i] == maxi) ans += cnt[i];
        }
        return ans; 
    }
};