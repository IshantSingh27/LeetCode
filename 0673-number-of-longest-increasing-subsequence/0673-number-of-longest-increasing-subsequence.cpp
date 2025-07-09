class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size() , ans = 1;

        vector<int> dp(n , 1) , cnt(n , 1);

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if(arr[j] < arr[i] && dp[i] == dp[j] + 1){
                    cnt[i] += cnt[j];
                }
            }
            ans = max(ans , dp[i]);
        }
        
        int res = 0;
        for(int i=0 ; i<n ; i++){
            if(dp[i] == ans){
                res += cnt[i];
            }
        }

        return res;
    }
};