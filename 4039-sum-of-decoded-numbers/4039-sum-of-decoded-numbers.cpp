class Solution {
public:

    long long power(long long x, long long y, long long mod) {

        long long result = 1;

        x %= mod;

        while(y > 0) {

            if(y & 1)
                result = (result * x) % mod;

            x = (x * x) % mod;

            y /= 2;
        }

        return result;
    }

    int sumDecoded(vector<long long>& nums) {

        const long long mod = 1e9 + 7;
        long long ans = 0;

        for(long long num : nums) {

            long long width = num % 10;
            long long d = num / 10;

            string s = to_string(d);

            string sx = s.substr(0, width);
            string sy = s.substr(width);

            long long x = stoll(sx);
            long long y = stoll(sy);

            ans = (ans + power(x, y, mod)) % mod;
        }

        return ans;
    }
};