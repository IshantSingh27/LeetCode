class Solution {
public:
    long long gcd(long long a , long long b){
        while(b != 0){
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long maxPairStrength(vector<int>& arr) {
        long long maxi = 0 , n = arr.size();
        for(long long i=0 ; i<n ; i++){
            for(long long j=i+1 ; j<n ; j++){
                long long cur = (1LL * arr[i] * arr[j]) / (1LL* gcd(arr[i] ,arr[j]) * gcd(arr[i] ,arr[j]));
                maxi = max(maxi , cur);
            }
        }
        return maxi;
    }
};