class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n , 1) , par(n , 1);
        int ans = 1 , last = -1;
        sort(arr.begin() , arr.end());
        
        for(int i=0 ; i<n ; i++){
            par[i] = i;
            for(int j=0 ; j<i ; j++){
                if((arr[i] % arr[j] == 0) && dp[i] <= 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    par[i] = j;
                }
            }
            if(ans < dp[i]){
                ans = dp[i];
                last = i;
            }
        }
        
        vector<int> res;
        if(last == -1){
            res.push_back(arr[0]);
            return res;
        }
        while(par[last] != last){
            res.push_back(arr[last]);
            last = par[last];
        }
        res.push_back(arr[last]);
        reverse(res.begin() , res.end());
        
        return res;
    }
};