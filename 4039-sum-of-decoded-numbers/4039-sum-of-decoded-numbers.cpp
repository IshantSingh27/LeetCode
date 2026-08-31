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

            string s = to_string(d);

            string sx = s.substr(0 , width);
            string sy = s.substr(width);

            long long x = stoll(sx);
            long long y = stoll(sy);

            ans = (ans + power(x , y)) % mod;
        }

        return ans;
    }
};