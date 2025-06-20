class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size() , maxi = 0 , last = 0;
        vector<int> dp(n , 1) , par(n , 0);
        for(int ind = 0 ; ind < n ; ind++){
            par[ind] = ind;
            for(int prev = 0 ; prev < ind ; prev++){
                if(arr[ind] % arr[prev] == 0){
                    if(dp[prev] + 1 > dp[ind]){
                        dp[ind] = dp[prev] + 1;
                        par[ind] = prev;
                    }
                }
            }
            if(dp[ind] > maxi){
                maxi = dp[ind];
                last = ind;
            }
        }
        vector<int> ans;
        ans.push_back(arr[last]);
        while(par[last] != last){
            ans.push_back(arr[par[last]]);
            last = par[last];
        }
        return ans;
    }
};