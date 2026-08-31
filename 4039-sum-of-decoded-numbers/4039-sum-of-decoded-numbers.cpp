class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long x , long long y){
        long long res = 1;
        x %= mod;

        while(y > 0){
            if(y & 1) res = (res * x) % mod;

            x = (x * x) % mod;

            y = y / 2;
        }

        return res;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;

        for(long long i=0 ; i<nums.size() ; i++){
            long long width = nums[i] % 10;
            long long d = nums[i] / 10;

            long long digits = 0 , temp = d;

            while(temp > 0){
                digits++;
                temp = temp / 10;
            }

            long long div = power(10 , digits - width);

            long long x = d / div;
            long long y = d % div;

            ans = (ans + power(x , y)) % mod;
        }

        return ans;
    }
};