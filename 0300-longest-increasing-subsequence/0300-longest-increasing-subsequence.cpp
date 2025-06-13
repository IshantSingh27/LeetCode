class Solution {
public:
    // int solve(int ind , int prev , int n , vector<int>& arr , vector<vector<int>>& dp){
    //     if(ind == n) return 0;
    //     if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
    //     int notTake = 0 + solve(ind + 1 , prev , n , arr , dp);
    //     int take = 0;
    //     if(prev == -1 || arr[ind] > arr[prev]){
    //         take = 1 + solve(ind + 1 , ind , n , arr , dp);
    //     }
    //     return dp[ind][prev + 1] = max(take , notTake);
    // }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
    //     return solve(0 , -1 , n , arr , dp);
    //     //TABULATION
    //     vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));
    //     for(int ind = n-1 ; ind>=0 ; ind--){
    //         for(int prev = ind-1 ; prev >= -1 ; prev--){
    //             int notTake = 0 + dp[ind + 1][prev + 1];
    //             int take = 0;
    //             if(prev == -1 || arr[ind] > arr[prev]){
    //                 take = 1 + dp[ind + 1][ind + 1];
    //             }
    //             dp[ind][prev + 1] = max(take , notTake);
    //         }
    //     }
    //     return dp[0][0];
    // }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> back(n + 1 , 0) , cur(n + 1 , 0);
    //     for(int ind = n-1 ; ind>=0 ; ind--){
    //         for(int prev = ind-1 ; prev >= -1 ; prev--){
    //             int notTake = 0 + back[prev + 1];
    //             int take = 0;
    //             if(prev == -1 || arr[ind] > arr[prev]){
    //                 take = 1 + back[ind + 1];
    //             }
    //             cur[prev + 1] = max(take , notTake);
    //         }
    //         back = cur;
    //     }
    //     return back[0];
    // }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> dp(n , 1);
    //     int maxi = 1;
    //     for(int i=0 ; i<n ; i++){
    //         for(int j=0 ; j<i ; j++){
    //             if(arr[j] < arr[i]){
    //                 dp[i] = max(dp[i] , 1 + dp[j]);
    //             }
    //         }
    //         maxi = max(maxi , dp[i]);
    //     }
    //     return maxi;
    // }
    // //PRINT
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> dp(n , 1) , parent(n , 1);
    //     int maxi = 1 , last = 0;
    //     for(int cur=0 ; cur<n ; cur++){
    //         parent[cur] = cur;
    //         for(int prev=0 ; prev<cur ; prev++){
    //             if(arr[prev] < arr[cur] && 1 + dp[prev] > dp[cur]){
    //                 dp[cur] = 1 + dp[prev];
    //                 parent[cur] = prev;
    //             }
    //         }
    //         if(dp[cur] > maxi){
    //             maxi = dp[cur];
    //             last = cur;
    //         }
    //     }
    //     vector<int> ans;
    //     ans.push_back(arr[last]);
    //     while(parent[last] != last){
    //         last = parent[last];
    //         ans.push_back(arr[last]);
    //     }
    //     reverse(ans.begin() , ans.end());
    //     for(auto it : ans){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    //     return 0;
    // }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> ans;
    //     ans.push_back(arr[0]);
    //     for(int i=1 ; i<n ; i++){
    //         if(arr[i] > ans.back()){
    //             ans.push_back(arr[i]);
    //         }
    //         else{
    //             int ind = lower_bound(ans.begin() , ans.end() , arr[i])  - ans.begin();
    //             ans[ind] = arr[i];
    //         }
    //     }
    //     return ans.size();
    // }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1 ; i<n ; i++){
            if(arr[i] > ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
                ans[ind] = arr[i];
            }
        }
        return ans.size();
    }
};