class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool sign = (dividend >= 0) == (divisor >= 0);

        long long n = abs((long long)dividend) , d = abs((long long)divisor) , ans = 0;

        while(n >= d){
            int cnt = 0;
            while(n >= (d * (1LL << (cnt + 1)))){ // (d * (1 << (cnt + 1)))
                cnt++;
            }

            ans += (1LL << cnt);
            n -= (d * (1LL << cnt));
        }

        if(!sign) ans = -ans;
        return ans;
    }
};
