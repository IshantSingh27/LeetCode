class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
       sort(arr.begin() , arr.end());
       int n = arr.size() , ans = 1 , last = 0;

        vector<int> dp(n , 1) , parent(n , 0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
            for(int j = 0 ; j < i ; j++){
                if(arr[i] % arr[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
                last = i;
            }
        }

        vector<int> res;
        while(parent[last] != last){
            res.push_back(arr[last]);
            last = parent[last];
        }
        res.push_back(arr[last]);
        reverse(res.begin() , res.end());

        return res;
    }
};