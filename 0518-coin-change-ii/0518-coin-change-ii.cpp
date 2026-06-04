class Solution {
public:
    int change(int k, vector<int>& arr) {
        long long n = arr.size() , mod = 1e18 + 7;
        vector<long long> prev(k + 1 , 0);
        for(long long i=0 ; i<=k ; i++){
            if(i % arr[0] == 0) prev[i] = 1; 
        }

        for(long long i=1 ; i<n ; i++){
            for(long long j=0 ; j<=k ; j++){
                long long nottake = prev[j];
                long long take = 0;
                if(arr[i] <= j){
                    take = prev[j - arr[i]];
                }

                prev[j] = (take + nottake) % mod;
            }
        }

        return prev[k] % mod;
    }
};