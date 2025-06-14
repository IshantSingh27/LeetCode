class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n , 1) , parent(n , 0);
        int maxi = 1 , last = 0;
        sort(arr.begin() , arr.end());
        for(int cur = 1 ; cur < n ; cur++){
            parent[cur] = cur;
            for(int prev = 0 ; prev < cur ; prev++){
                if(arr[cur] % arr[prev] == 0 && dp[cur] < dp[prev] + 1){
                    dp[cur] = dp[prev] + 1;
                    parent[cur] = prev;
                }
            }
            if(dp[cur] > maxi){
                maxi = dp[cur];
                last = cur;
            }
        }
        vector<int> ans;
        while(parent[last] != last){
            ans.push_back(arr[last]);
            last = parent[last];
        }
        ans.push_back(arr[last]);
        return ans;
    }
};