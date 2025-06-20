class Solution {
public:
    int solve(int ind , int prev , vector<int>& arr , vector<vector<int>>& dp){
        if(ind== arr.size()) return 0;
        
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int notTake = 0 + solve(ind + 1 , prev , arr , dp);
        int take = 0;
        if(prev == -1 || arr[ind] > arr[prev]){
            take = 1 + solve(ind + 1 , ind , arr , dp);
        }
        return dp[ind][prev + 1] = max(take , notTake);
    }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     // vector<vector<int>> dp(n , vector<int>(n + 1 , -1));
    //     // return solve(0 , -1 , arr , dp);
    //     vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));
    //     for(int ind = n-1 ; ind >= 0 ; ind--){
    //         for(int prev = ind - 1 ; prev >= -1 ; prev--){
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
    //     vector<int> pre(n + 1 , 0);
    //     for(int ind = n-1 ; ind >= 0 ; ind--){
    //         vector<int> cur(n + 1 , 0);
    //         for(int prev = ind - 1 ; prev >= -1 ; prev--){
    //             int notTake = 0 + pre[prev + 1];
    //             int take = 0;
    //             if(prev == -1 || arr[ind] > arr[prev]){
    //                 take = 1 + pre[ind + 1];
    //             }
    //             cur[prev + 1] = max(take , notTake);
    //         }
    //         pre = cur;
    //     }
    //     return pre[0];
    // }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     int maxi = 1;
    //     vector<int> dp(n , 1);
    //     for(int ind = 0 ; ind < n ; ind++){
    //         for(int prev = 0 ; prev <= ind ; prev++){
    //             if(arr[ind] > arr[prev]){
    //                 dp[ind] = max(dp[ind] , dp[prev] + 1);
    //             }
    //         }
    //         maxi = max(maxi , dp[ind]);
    //     }
    //     return maxi;
    // }
    // int lengthOfLIS(vector<int>& arr) {
    //     int n = arr.size();
    //     int maxi = 1 , last = 0;
    //     vector<int> dp(n , 1) , parent(n , 0);
    //     for(int ind = 0 ; ind < n ; ind++){
    //         parent[ind] = ind;
    //         for(int prev = 0 ; prev < ind ; prev++){
    //             if(arr[ind] > arr[prev] && dp[prev] + 1 > dp[ind]){
    //                 dp[ind] = dp[prev] + 1;
    //                 parent[ind] = prev;
    //             }
    //         }
    //         if(dp[ind] > maxi){
    //             maxi = dp[ind];
    //             last = ind;
    //         }
    //     }
    //     vector<int> ans;
    //     while(parent[last] != last){
    //         ans.push_back(arr[last]);
    //         last = parent[last];
    //     }
    //     ans.push_back(last);
    //     reverse(ans.begin() , ans.end());
    //     for(auto it : ans){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    //     return 0;
    // }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1 ; i<n ; i++){
            if(arr[i] > ans.back()) ans.push_back(arr[i]);
            else{
                int ind = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
                ans[ind] = arr[i];
            }
        }
        return ans.size();
    }
};